#include "pch.h"
#include "Stock.xaml.h"
#if __has_include("Stock.g.cpp")
#include "Stock.g.cpp"
#endif

//#include "globallist.h"
#include "curl/curl.h"
#include "StockList.xaml.h"
#include <winrt/Windows.UI.Input.h>
#include <winrt/Windows.UI.Xaml.Input.h>
#include "NavigationService.h"
#include "winrt/Windows.UI.Xaml.Interop.h"
#include <string>
#include <nlohmann/json.hpp>  // Include this after installing
using namespace globallist;


using json = nlohmann::json;

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace std;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::stockproj::implementation
{
    hstring OutputJsonField(const std::string& label, const std::string& value) { //converts json to wstring
        std::wstring wlabel(label.begin(), label.end());
        std::wstring wvalue(value.begin(), value.end());
        std::wstring message = wlabel + L": " + wvalue + L"\n";
        return winrt::hstring{ message };
    }

    size_t Stock::WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output)
    {
        size_t totalSize = size * nmemb;
        output->append((char*)contents, totalSize);
        return totalSize;
    }

    void Stock::fetch_stock_quote(const string& ticker) {
        CURL* curl = curl_easy_init();
        if (curl) {
            string readBuffer;
            string apiKey = "35d57fadcdc94333a8eff11a9d0077e1";
            string url = "https://api.twelvedata.com/time_series?symbol=" + ticker + "&interval=1day&outputsize=5&apikey=" + apiKey;

            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

            CURLcode res = curl_easy_perform(curl);

            

            if (res == CURLE_OK) {

                try {
                    if (g_stockList == nullptr) return; // creates the list and the consructor builds it
                    winrt::stockproj::Stock stock; // creates the list
                    //list.buildlist();

                    auto j = json::parse(readBuffer);
                   

                    auto values = j["values"];
                    for (const auto& entry : values) {
                         stock.Ticker(OutputJsonField("Ticker:", j["meta"]["symbol"].get<std::string>()));
                         stock.Time(OutputJsonField("Time:", entry["datetime"].get<std::string>()));
                         stock.Open(OutputJsonField("Open:", entry["open"].get<std::string>()));
                         stock.High(OutputJsonField("High:", entry["high"].get<std::string>()));
                         stock.Low(OutputJsonField("Low:", entry["low"].get<std::string>()));
                         stock.Close(OutputJsonField("Close:", entry["close"].get<std::string>()));

                         g_stockList.appendlist(stock);
                    }

                    OutputDebugStringW(L"My output string.");//test with output tommorrow

                }
                catch (const std::exception& e) {
                    std::cerr << "JSON parse error: " << e.what() << "\n";
                }
            }
            else {
                std::cerr << "CURL failed: " << curl_easy_strerror(res) << "\n";
            }

            curl_easy_cleanup(curl);

        }
    }
}
