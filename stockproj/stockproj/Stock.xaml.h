#pragma once

#include "Stock.g.h"
#include <iostream>
using namespace std;
namespace winrt::stockproj::implementation
{
    struct Stock : StockT<Stock>
    {
        Stock() = default;
        /*Stock(hstring ticker, hstring time, hstring high, hstring low, hstring close, hstring open) :
            m_ticker{ ticker }, m_time{ time }, m_high{ high }, m_low{ low }, m_close{ close }, m_open{ open } {}        */


        //create getters/setters
        hstring Ticker() const { return m_ticker; }
        void Ticker(hstring const& val) { m_ticker = val; }

        hstring Time() const { return m_time; }
        void Time(hstring const& val) { m_time = val; }

        hstring Open() const { return m_open; }
        void Open(hstring const& val) { m_open = val; }

        hstring High() const { return m_high; }
        void High(hstring const& val) { m_high = val; }

        hstring Low() const { return m_low; }
        void Low(hstring const& val) { m_low = val; }

        hstring Close() const { return m_close; }
        void Close(hstring const& val) { m_close = val; }

        static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output);
        static void fetch_stock_quote(const string& ticker, const string& interval, const string& days);
        static hstring OutputJsonField(const std::string& label, const std::string& value);
       

       

        private:
            hstring m_ticker;
            hstring m_time;
            hstring m_high;
            hstring m_low;
            hstring m_close;
            hstring m_open;
    };
  
}

namespace winrt::stockproj::factory_implementation
{
    struct Stock : StockT<Stock, implementation::Stock>
    {
    };
}
