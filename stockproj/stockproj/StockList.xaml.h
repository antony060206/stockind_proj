#pragma once

#include "StockList.g.h"

namespace winrt::stockproj::implementation
{
    struct StockList : StockListT<StockList>
    {
        StockList()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

    };
}

namespace winrt::stockproj::factory_implementation
{
    struct StockList : StockListT<StockList, implementation::StockList>
    {
    };
}
