#include "pch.h"
#include "Indicator.xaml.h"
#if __has_include("Indicator.g.cpp")
#include "Indicator.g.cpp"
#endif

#include "curl/curl.h"
#include <winrt/Windows.UI.Input.h>
#include <winrt/Windows.UI.Xaml.Input.h>
#include "NavigationService.h"
#include "winrt/Windows.UI.Xaml.Interop.h"
#include <string>
#include "rsilist.h"
#include "macdlist.h"

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
	

	void Indicator::rsiappendlist(winrt::stockproj::Rsi const& rsi)
	{
		r_items.Append(rsi);
	}

	winrt::Windows::Foundation::Collections::IVector<winrt::stockproj::Rsi> Indicator::RsiItems()//getter
	{
		return r_items;
	}

	void Indicator::macdappendlist(winrt::stockproj::Macd const& macd)
	{
		m_items.Append(macd);
	}

	winrt::Windows::Foundation::Collections::IVector<winrt::stockproj::Macd> Indicator::MacdItems()//getter
	{
		return m_items;
	}

	//void Indicator::IndicatorItems(winrt::Windows::Foundation::Collections::IVector<winrt::stockproj::Stock> const& value)//not used setter
	//{
	//	m_items = value;
	//	r_items = value;
	//}

	/*void Indicator::output() {

	}*/

	
}
