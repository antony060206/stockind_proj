#include "pch.h"
#include "HomePage.xaml.h"
#if __has_include("HomePage.g.cpp")
#include "HomePage.g.cpp"
#endif

#include "curl/curl.h"
#include <sstream>
#include <winrt/Windows.UI.Input.h>
#include <winrt/Windows.UI.Xaml.Input.h>
#include "NavigationService.h"
#include "winrt/Windows.UI.Xaml.Interop.h"


using namespace winrt;
using namespace Microsoft::UI::Xaml;


namespace winrt::stockproj::implementation
{
	void HomePage::search(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e){
		OutputDebugString(L"Hello World");
		NavigationService::Navigate(xaml_typename<winrt::stockproj::StockList>());
	}
}
