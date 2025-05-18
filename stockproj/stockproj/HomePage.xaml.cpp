#include "pch.h"
#include "HomePage.xaml.h"
#if __has_include("HomePage.g.cpp")
#include "HomePage.g.cpp"
#endif

#include <winrt/Windows.UI.Input.h>
#include <winrt/Windows.UI.Xaml.Input.h>
#include "NavigationService.h"
#include "winrt/Windows.UI.Xaml.Interop.h"
//#include "StockList.xaml.h"
//#include "Indicator.xaml.h"
#include "Stock.xaml.h"
#include "Rsi.xaml.h"
#include "Macd.xaml.h"


using namespace winrt;
using namespace Microsoft::UI::Xaml;


namespace winrt::stockproj::implementation
{
	void HomePage::search(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e){
		NavigationService::Navigate(xaml_typename<winrt::stockproj::StockList>());
		DispatcherQueue().TryEnqueue([this] {
			auto tickerStr = to_string(ticker().Text());
			auto intervalStr = to_string(Interval().Text());
			auto daysStr = to_string(Output().Text());
			Stock::fetch_stock_quote(tickerStr, intervalStr, daysStr);
			});

	}

	void HomePage::indicator_search(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e) {
		NavigationService::Navigate(xaml_typename<winrt::stockproj::Indicator>());
		auto tickerStr = to_string(ticker().Text());
		Macd::fetch_macd(tickerStr);
		Rsi::fetch_rsi(tickerStr);

		
	}
}
