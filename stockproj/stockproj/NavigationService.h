#pragma once
#include <winrt/Microsoft.UI.Xaml.Controls.h>

struct NavigationService
{
    static void Initialize(winrt::Microsoft::UI::Xaml::Controls::Frame const& frame)
    {
        m_frame = frame;
    }

    static winrt::Microsoft::UI::Xaml::Controls::Frame Frame()
    {
        return m_frame;
    }

    static void Navigate(winrt::Windows::UI::Xaml::Interop::TypeName const& pageType)
    {
        if (m_frame)
        {
            m_frame.Navigate(pageType);
        }
    }

private:
    inline static winrt::Microsoft::UI::Xaml::Controls::Frame m_frame{ nullptr };
};