#include <stdafx.h>

#include "Developer.h"

#include "HelperWidgets.h"

Developer::Developer(Options& aOptions)
    : m_options(aOptions)
{
}

void Developer::OnEnable()
{
    Load();
}

void Developer::OnDisable()
{
}

void Developer::Update()
{
    if (ImGui::Button("Load"))
        Load();
    ImGui::SameLine();
    if (ImGui::Button("Save"))
        Save();
    ImGui::SameLine();
    if (ImGui::Button("Defaults"))
        ResetToDefaults();

    ImGui::Spacing();
    
    if (ImGui::BeginChild("##SETTINGS_ACTUAL", ImVec2(0,0), true))
    {
        HelperWidgets::BoolWidget("Draw ImGui Diagnostic Window:", m_drawImGuiDiagnosticWindow, m_options.DrawImGuiDiagnosticWindow);
        if (m_drawImGuiDiagnosticWindow)
            ImGui::ShowMetricsWindow(&m_drawImGuiDiagnosticWindow);

        HelperWidgets::BoolWidget("Remove Dead Bindings:", m_removeDeadBindings, m_options.RemoveDeadBindings);
    }
    ImGui::EndChild();
}

void Developer::Load()
{
    m_options.Load();

    m_drawImGuiDiagnosticWindow = m_options.DrawImGuiDiagnosticWindow;
    m_removeDeadBindings = m_options.RemoveDeadBindings;
}

void Developer::Save()
{
    m_options.DrawImGuiDiagnosticWindow = m_drawImGuiDiagnosticWindow;
    m_options.RemoveDeadBindings = m_removeDeadBindings;

    m_options.Save();
}

void Developer::ResetToDefaults()
{
    m_options.ResetToDefaults();
    Load();
}
