#pragma once

#include "Indicator.g.h"
#include "rsilist.h"
#include "macdlist.h"
using namespace winrt::Windows::Foundation::Collections;
using namespace std;
namespace winrt::stockproj::implementation
{
    struct Indicator : IndicatorT<Indicator>
    {
        winrt::Windows::Foundation::Collections::IVector<winrt::stockproj::Rsi> r_items;
        winrt::Windows::Foundation::Collections::IVector<winrt::stockproj::Macd> m_items;

        Indicator(){
            InitializeComponent();
            globalrsi::g_rsiList = *this;
            globalmacd::g_macdList = *this;

            r_items = winrt::single_threaded_observable_vector<winrt::stockproj::Rsi>();
            m_items = winrt::single_threaded_observable_vector<winrt::stockproj::Macd>();

            this->DataContext(*this);
        }
        
        void rsiappendlist(winrt::stockproj::Rsi const& rsi);

        winrt::Windows::Foundation::Collections::IVector<winrt::stockproj::Rsi> RsiItems();

        void macdappendlist(winrt::stockproj::Macd const& macd);

        winrt::Windows::Foundation::Collections::IVector<winrt::stockproj::Macd> MacdItems();

        //void IndicatorItems(winrt::Windows::Foundation::Collections::IVector<winrt::stockproj::Stock> const& value);//setter

       
       
    };
}

namespace winrt::stockproj::factory_implementation
{
    struct Indicator : IndicatorT<Indicator, implementation::Indicator>
    {
    };
}
