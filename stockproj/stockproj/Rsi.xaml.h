#pragma once

#include "Rsi.g.h"
#include <iostream>
using namespace std;
namespace winrt::stockproj::implementation
{
    struct Rsi : RsiT<Rsi>
    {
    public:
        Rsi() {
            //InitializeComponent();
        }
        

        static hstring OutputJsonField(const std::string& label, const std::string& value);

        static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output);

        static void fetch_rsi(const string& ticker);

        //create getters/setters
        hstring RSI_Ticker() const { return m_ticker; }
        void RSI_Ticker(hstring const& val) { m_ticker = val; }

        hstring RSI_Date() const { return m_date; }
        void RSI_Date(hstring const& val) { m_date = val; }

        hstring RSI_Value() const { return m_rsi; }
        void RSI_Value(hstring const& val) { m_rsi = val; }

    private:

        hstring m_ticker;
        hstring m_date;
        hstring m_rsi;
      
    };
}

namespace winrt::stockproj::factory_implementation
{
    struct Rsi : RsiT<Rsi, implementation::Rsi>
    {
    };
}
