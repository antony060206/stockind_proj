#pragma once

#include "Stock.g.h"
#include <iostream>
namespace winrt::stockproj::implementation
{
    struct Stock : StockT<Stock>
    {
        Stock() = default;
        Stock(hstring ticker, hstring time, hstring high, hstring low, hstring close, hstring open) :
            m_ticker{ ticker }, m_time{ time }, m_high{ high }, m_low{ low }, m_close{ close }, m_open{ open } {}        


        //create getters
        hstring Ticker() const { return m_ticker; }
        hstring Time() const { return m_time; }
        hstring High() const { return m_high; }
        hstring Low() const { return m_low; }
        hstring Close() const { return m_close; }
        hstring Open() const { return m_open; }

        static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output);
        static void fetch_stock_quote(const std::string& ticker);

       

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
