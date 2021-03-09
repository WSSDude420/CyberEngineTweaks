#pragma once

#include "Widget.h"

struct VKBindings;
struct Overlay;
struct Options;

struct Developer : Widget
{
    Developer(Options& aOptions);
    ~Developer() override = default;

    void OnEnable() override;
    void OnDisable() override;
    void Update() override;
    
    void Load();
    void Save();
    void ResetToDefaults(); 

private:
    bool m_drawImGuiDiagnosticWindow{ false };
    bool m_removeDeadBindings{ true };
    
    Options& m_options;
};
