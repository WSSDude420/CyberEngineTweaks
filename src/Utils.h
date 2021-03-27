#pragma once

void ltrim(std::string& s);
void rtrim(std::string& s);
void trim(std::string& s);

spdlog::sink_ptr CreateCustomSinkST(std::function<void(const std::string&)> aSinkItHandler, std::function<void()> aFlushHandler = nullptr);
spdlog::sink_ptr CreateCustomSinkMT(std::function<void(const std::string&)> aSinkItHandler, std::function<void()> aFlushHandler = nullptr);
std::shared_ptr<spdlog::logger> CreateLogger(const std::filesystem::path& aPath, const std::string& aID, spdlog::sink_ptr aExtraSink = nullptr, const std::string& aPattern = "[%Y-%m-%d %H:%M:%S UTC%z] [%l] %v");

// deep copies sol object (doesnt take into account potential duplicates)
sol::object DeepCopySolObject(sol::object aObj, const sol::state_view& aStateView);

// extend hash so we can hash sol objects too
namespace std
{
    template<>
    struct hash<sol::object>
    {
        std::size_t operator()(const sol::object& k) const
        {
            return reinterpret_cast<size_t>(k.pointer());
        }
    };
} // namespace std

// deep copies sol object (takes into account potential duplicates, may be redundant)
sol::object DeepCopySolObject(sol::object aObj, const sol::state_view& aStateView,std::unordered_map<sol::object, sol::object>& aSeen);