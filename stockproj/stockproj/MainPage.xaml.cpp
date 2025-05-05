#include "pch.h"
#include "MainPage.xaml.h"
#if __has_include("MainPage.g.cpp")
#include "MainPage.g.cpp"
#endif
#include "winrt/Windows.UI.Xaml.Interop.h"

//#include <cpprest/http_client.h>//inlucde header in project/tools as wella as exclude errors
//#include <cpprest/json.h>  // for parsing JSON
//using namespace web;
//using namespace web::http;
//using namespace web::http::client;

#include "curl/curl.h"
#include <string>
#include "NavigationService.h"

using namespace winrt;
using namespace Microsoft::UI::Xaml;

namespace winrt::stockproj::implementation
{
	
	void MainPage::Page_Loaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::IRoutedEventArgs const& e)
	{
		NavigationService::Initialize(mainFrame());
	}

	//Navigates through the pages in the menu screen using the windows ui NavigationView
	void MainPage::NavigationView_ItemInvoked(winrt::Microsoft::UI::Xaml::Controls::NavigationView const& sender, winrt::Microsoft::UI::Xaml::Controls::NavigationViewItemInvokedEventArgs args) {

		if (args.IsSettingsInvoked())
		{
			//open settings page
		}
		else
		{
			hstring tag = unbox_value<hstring>(args.InvokedItemContainer().Tag());
			if (tag == L"stocklist") {
				openStockPage();
			}
			else if (tag == L"home") {
				openHomePage();
			}
		}
	}
	//use main frame to open the HomePage
	void MainPage::openHomePage()
	{
		mainFrame().Navigate(xaml_typename<winrt::stockproj::HomePage>());
	}
	//use main frame to open the Stocklist page
	void MainPage::openStockPage() {
		mainFrame().Navigate(xaml_typename<winrt::stockproj::StockList>());

	}
	//Enables teh Back button in the NaviatioView only when there's a page to go back
	void MainPage::mainFrame_Navigated(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& e)
	{
		nav().IsBackEnabled(mainFrame().CanGoBack());
	}
	//sends back to the previous page
	void MainPage::nav_BackRequested(winrt::Microsoft::UI::Xaml::Controls::NavigationView const& sender, winrt::Microsoft::UI::Xaml::Controls::NavigationViewBackRequestedEventArgs const& args)
	{
		mainFrame().GoBack();
	}

}
