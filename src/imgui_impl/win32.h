// dear imgui: Platform Backend for Windows (standard windows API for 32 and 64 bits applications)
// This needs to be used along with a Renderer (e.g. DirectX11, OpenGL3, Vulkan..)

// Implemented features:
//  [X] Platform: Clipboard support (for Win32 this is actually part of core dear imgui)
//  [X] Platform: Mouse cursor shape and visibility. Disable with 'io.ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange'.
//  [X] Platform: Keyboard arrays indexed using VK_* Virtual Key Codes, e.g. ImGui::IsKeyPressed(VK_SPACE).
//  [X] Platform: Gamepad support. Enabled with 'io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad'.

// You can copy and use unmodified imgui_impl_* files in your project. See examples/ folder for examples of using this.
// If you are new to Dear ImGui, read documentation from the docs/ folder + read the top of imgui.cpp.
// Read online: https://github.com/ocornut/imgui/tree/master/docs

#pragma once
#include "imgui.h"      // IMGUI_IMPL_API

bool ImGui_ImplWin32_Init(HWND ahWnd);
void ImGui_ImplWin32_Shutdown();
void ImGui_ImplWin32_NewFrame(SIZE aOutSize);

// Win32 message handler your application need to call.
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND ahWnd, UINT auMsg, WPARAM awParam, LPARAM alParam);

// DPI-related helpers (optional)
// - Use to enable DPI awareness without having to create an application manifest.
// - Your own app may already do this via a manifest or explicit calls. This is mostly useful for our examples/ apps.
// - In theory we could call simple functions from Windows SDK such as SetProcessDPIAware(), SetProcessDpiAwareness(), etc.
//   but most of the functions provided by Microsoft require Windows 8.1/10+ SDK at compile time and Windows 8/10+ at runtime,
//   neither we want to require the user to have. So we dynamically select and load those functions to avoid dependencies.
void  ImGui_ImplWin32_EnableDpiAwareness();
float ImGui_ImplWin32_GetDpiScaleForHwnd(HWND ahWnd);
float ImGui_ImplWin32_GetDpiScaleForMonitor(HMONITOR ahMonitor);
