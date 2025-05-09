#include "pch.h"
#include "HomePage.xaml.h"
#if __has_include("HomePage.g.cpp")
#include "HomePage.g.cpp"
#endif

#include <winrt/Windows.UI.Input.h>
#include <winrt/Windows.UI.Xaml.Input.h>
#include "NavigationService.h"
#include "winrt/Windows.UI.Xaml.Interop.h"
#include "StockList.xaml.h"
#include "Stock.xaml.h"


using namespace winrt;
using namespace Microsoft::UI::Xaml;


namespace winrt::stockproj::implementation
{
	void HomePage::search(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e){
		NavigationService::Navigate(xaml_typename<winrt::stockproj::StockList>());
		DispatcherQueue().TryEnqueue([this] {
			auto tickerStr = to_string(ticker().Text());
			Stock::fetch_stock_quote(tickerStr);
			});

	}
}
