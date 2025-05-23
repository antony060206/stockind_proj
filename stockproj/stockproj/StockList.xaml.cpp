#include "pch.h"
#include "StockList.xaml.h"
#if __has_include("StockList.g.cpp")
#include "StockList.g.cpp"
#endif

#include "curl/curl.h"
#include <winrt/Windows.UI.Input.h>
#include <winrt/Windows.UI.Xaml.Input.h>
#include "NavigationService.h"
#include "winrt/Windows.UI.Xaml.Interop.h"
#include <string>


#include <nlohmann/json.hpp>  // Include this after installing

using json = nlohmann::json;

using namespace winrt::Windows::Foundation::Collections;
using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace std;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::stockproj::implementation
{		
	
	/*void StockList::buildlist() {
		m_items = winrt::single_threaded_observable_vector<winrt::stockproj::Stock>();
	}*/

	void StockList::appendlist(winrt::stockproj::Stock const& stock)
	{
		m_items.Append(stock);	
	}

	winrt::Windows::Foundation::Collections::IVector<winrt::stockproj::Stock> StockList::StockItems()//getter
	{
		return m_items;
	}

	void StockList::StockItems(winrt::Windows::Foundation::Collections::IVector<winrt::stockproj::Stock> const& value)//not used setter
	{
		m_items = value;
	}

	

}
