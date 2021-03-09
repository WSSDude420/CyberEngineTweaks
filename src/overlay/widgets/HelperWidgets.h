#pragma once

#include "Widget.h"

struct Options;
namespace HelperWidgets
{
WidgetID ToolbarWidget(const Options& aOptions);
void BindWidget(VKBindInfo& aVKBindInfo, const std::string& acId);
void BoolWidget(const std::string& label, bool& current, bool saved);
}