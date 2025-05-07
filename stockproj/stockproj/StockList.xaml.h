#pragma once

#include "StockList.g.h"
#include <iostream>

namespace winrt::stockproj::implementation
{
    struct StockList : StockListT<StockList>
    {
        StockList()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

        static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output);

        static void fetch_stock_quote(const std::string& ticker);

    };
}

namespace winrt::stockproj::factory_implementation
{
    struct StockList : StockListT<StockList, implementation::StockList>
    {
    };
}
