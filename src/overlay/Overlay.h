#pragma once

#include "widgets/Widget.h"
#include "widgets/Console.h"
#include "widgets/Bindings.h"
#include "widgets/Settings.h"
#include "widgets/Developer.h"

using TClipToCenter = HWND(RED4ext::CGameEngine::UnkC0*);

struct D3D12;
struct Options;

struct Overlay
{  
    Overlay(D3D12& aD3D12, VKBindings& aBindings, Options& aOptions, LuaVM& aVm);
    ~Overlay();

    void PostInitialize();
    
    [[nodiscard]] bool IsInitialized() const noexcept;

    Console& GetConsole();
    Bindings& GetBindings();
    Settings& GetSettings();
    
    void Toggle();
    [[nodiscard]] bool IsEnabled() const noexcept;
    [[nodiscard]] VKBind GetBind() const noexcept;

    void Update();

    LRESULT OnWndProc(HWND ahWnd, UINT auMsg, WPARAM awParam, LPARAM alParam);

protected:
    
    void Hook();
    
    static BOOL ClipToCenter(RED4ext::CGameEngine::UnkC0* apThis);

private:

    void SetActiveWidget(WidgetID aNewActive);
    
    Console m_console;
    Bindings m_bindings;
    Settings m_settings;
    Developer m_developer;
    std::array<Widget*, size_t(WidgetID::COUNT)> m_widgets{ }; 

    TClipToCenter* m_realClipToCenter{ nullptr };

    WidgetID m_activeWidgetID{WidgetID::CONSOLE };
    
    std::atomic_bool m_enabled{ false };
    std::atomic_bool m_toggled{ false };
    bool m_initialized{ false };
    VKBind m_VKBOverlay;

    D3D12& m_d3d12;
    Options& m_options;
    LuaVM& m_vm;
    size_t m_connectInitialized;
    size_t m_connectUpdate;
};
