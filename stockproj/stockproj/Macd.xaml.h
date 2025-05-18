#pragma once

#include "Macd.g.h"
#include <iostream>
using namespace std;
namespace winrt::stockproj::implementation
{
    struct Macd : MacdT<Macd>
    {
        Macd() {
            //InitializeComponent();
        }

        static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output);
        static void fetch_macd(const string& ticker);
        static hstring OutputJsonField(const std::string& label, const std::string& value);

        //create getters/setters
        hstring MACD_Ticker() const { return m_ticker; }
        void MACD_Ticker(hstring const& val) { m_ticker = val; }

        hstring MACD_Date() const { return m_date; }
        void MACD_Date(hstring const& val) { m_date = val; }

        hstring MACD_Value() const { return m_rsi; }
        void MACD_Value(hstring const& val) { m_rsi = val; }

    private:
        hstring m_ticker;
        hstring m_date;
        hstring m_rsi;
    };
}

namespace winrt::stockproj::factory_implementation
{
    struct Macd : MacdT<Macd, implementation::Macd>
    {
    };
}
