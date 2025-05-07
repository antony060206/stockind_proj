#pragma once

#include "StockList.g.h"
using namespace winrt::Windows::Foundation::Collections;

namespace winrt::stockproj::implementation
{
    struct StockList : StockListT<StockList>
    {
        StockList()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

        winrt::Windows::Foundation::Collections::IVector<winrt::stockproj::Stock> m_items;

        static void buildlist();
        static void appendlist();
        static IVector<winrt::stockproj::Stock> getlist();

    };
}

namespace winrt::stockproj::factory_implementation
{
    struct StockList : StockListT<StockList, implementation::StockList>
    {
    };
}
