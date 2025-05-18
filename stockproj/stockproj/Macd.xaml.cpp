#include "pch.h"
#include "Macd.xaml.h"
#if __has_include("Macd.g.cpp")
#include "Macd.g.cpp"
#endif

#include "macdlist.h"
#include "curl/curl.h"
#include "Indicator.xaml.h"
#include <winrt/Windows.UI.Input.h>
#include <winrt/Windows.UI.Xaml.Input.h>
#include "NavigationService.h"
#include "winrt/Windows.UI.Xaml.Interop.h"
#include <string>
#include <nlohmann/json.hpp>  // Include this after installing
using namespace globalmacd;

using json = nlohmann::json;

using namespace std;
using namespace winrt;
using namespace Microsoft::UI::Xaml;
// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::stockproj::implementation
{
    hstring Macd::OutputJsonField(const std::string& label, const std::string& value) { //converts json to hstring
        std::wstring wlabel(label.begin(), label.end());
        std::wstring wvalue(value.begin(), value.end());
        std::wstring message = wlabel + L": " + wvalue + L"\n";
        return winrt::hstring{ message };
    }

    size_t Macd::WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output)
    {
        size_t totalSize = size * nmemb;
        output->append((char*)contents, totalSize);
        return totalSize;
    }

    void Macd::fetch_macd(const string& ticker) {
        
        CURL* curl = curl_easy_init();
        if (curl) {
            string readBuffer;
            string apiKey = "35d57fadcdc94333a8eff11a9d0077e1";

            /* Buying conditions : When the MACD fast line crosses the slow line(golden cross) and the RSI is below 40 (oversold), buy.
             Selling conditions : When the MACD fast line crosses below the slow line(death cross) and the RSI is above 60 (overbought), sell.

             Default setup

             Macd:
             
              "interval": "1min",
              "currency": "USD",
              "exchange_timezone": "America/New_York",
              "exchange": "NYSE",
              "mic_code": "XNYS",
              "type": "Common Stock",
              "indicator": {
                 "name": "MACD - Moving Average Convergence Divergence",
                 "fast_period": 12,
                 "series_type": "close",
                 "signal_period": 9,
                 "slow_period": 26
                 interval 1 min
                 outputsize = 5
             */

            string url = "https://api.twelvedata.com/macd?symbol=" + ticker + "&interval=1min&outputsize=5&apikey=" + apiKey;
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

            CURLcode res = curl_easy_perform(curl);

            if (res == CURLE_OK) {

                try {

                    auto j = json::parse(readBuffer);


                    auto values = j["values"];
                    for (const auto& entry : values) {
                        winrt::stockproj::Macd my_macd;// creates the stock obj
                        my_macd.MACD_Ticker(OutputJsonField("Ticker:", j["meta"]["symbol"].get<std::string>()));
                        my_macd.MACD_Date(OutputJsonField("Time:", entry["datetime"].get<std::string>()));
                        my_macd.MACD_Value(OutputJsonField("Macd:", entry["macd"].get<std::string>()));


                        //OutputDebugStringW((stock.Time()).c_str());

                        g_macdList.macdappendlist(my_macd);

                        /*std::wstring debug = L"[DEBUG] RSI Item: " +
                            std::wstring(my_macd.MACD_Ticker().c_str()) +
                            L" | " + std::wstring(my_macd.MACD_Date().c_str()) +
                            L" | " + std::wstring(my_macd.MACD_Value().c_str()) + L"\n";
                        OutputDebugStringW(debug.c_str());*/
                    }

                    OutputDebugStringW(L"My output string.");//test with output tommorrow

                }
                catch (const std::exception& e) {
                    OutputDebugStringW(L"JSON parse error:");
                }
            }
            else {
                OutputDebugStringW(L"CURL failed:");
            }

            curl_easy_cleanup(curl);
            
        }
    }
}
