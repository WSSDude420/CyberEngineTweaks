#pragma once

struct Paths
{
    Paths() = delete;
    ~Paths() = delete;

    static void Initialize()
    {
        TCHAR exePathBuf[MAX_PATH] = { 0 };
        GetModuleFileName(GetModuleHandle(nullptr), exePathBuf, std::size(exePathBuf));
        ExePath = exePathBuf;

        RootPath = ExePath.parent_path();

        CETPath = RootPath;
        CETPath /= "plugins";
        CETPath /= "cyber_engine_tweaks";
        std::filesystem::create_directories(CETPath);
        
        ConfigPath = CETPath / "config.json";
        // remove empty config.json
        if (std::filesystem::exists(ConfigPath) && !std::filesystem::file_size(ConfigPath))
            std::filesystem::remove(ConfigPath);

        VKBindingsPath = CETPath / "vkbindings.json";
        // remove empty vkbindings.json
        if (std::filesystem::exists(VKBindingsPath) && !std::filesystem::file_size(VKBindingsPath))
            std::filesystem::remove(VKBindingsPath);

        ModsPath = CETPath / "mods";
        std::filesystem::create_directories(ModsPath);

        Initialized = true;
    }
    
    static inline std::filesystem::path ExePath{ };
    static inline std::filesystem::path RootPath{ };
    static inline std::filesystem::path CETPath{ };
    static inline std::filesystem::path ConfigPath{ };
    static inline std::filesystem::path VKBindingsPath{ };
    static inline std::filesystem::path ModsPath{ };

    static inline bool Initialized{ false };
};