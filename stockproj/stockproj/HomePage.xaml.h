#pragma once

#include "HomePage.g.h"

namespace winrt::stockproj::implementation
{
    struct HomePage : HomePageT<HomePage>
    {
        HomePage()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }
        void search(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);

    };
}

namespace winrt::stockproj::factory_implementation
{
    struct HomePage : HomePageT<HomePage, implementation::HomePage>
    {
    };
}
