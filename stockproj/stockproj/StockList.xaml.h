#pragma once

#include "StockList.g.h"
#include "globallist.h"
using namespace winrt::Windows::Foundation::Collections;
using namespace std;
namespace winrt::stockproj::implementation
{
    struct StockList : StockListT<StockList>
    {
        winrt::Windows::Foundation::Collections::IVector<winrt::stockproj::Stock> m_items;

        StockList() {
            globallist::g_stockList = *this;
            m_items = winrt::single_threaded_observable_vector<winrt::stockproj::Stock>();
            this->DataContext(*this);
        }


        winrt::Windows::Foundation::Collections::IVector<winrt::stockproj::Stock> StockItems();//getter

        void StockItems(winrt::Windows::Foundation::Collections::IVector<winrt::stockproj::Stock> const& value);//setter

        void buildlist();

        void appendlist(winrt::stockproj::Stock const& stock);
        
       

    };
}

namespace winrt::stockproj::factory_implementation
{
    struct StockList : StockListT<StockList, implementation::StockList>
    {
    };
}
