workspace "Sparky"
    architecture  "x64"

    configurations {
        -- debugging
        "Debug",
        -- faster version of debug
        "Release",
        -- actual build
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Sparky"
    location "Sparky"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
		"%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
    }

    filter "system:windows" 
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "SPY_PLATFORM_WINDOWS",
            "SPY_BUILD_DLL",
        }

        postbuildcommands {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "SPY_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "SPY_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "SPY_DIST"
        optimize "On"
    
    filter "action:vs*"
        buildoptions { "/utf-8" }


project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "Sparky/vendor/spdlog/include",
        "Sparky/src"
    }

    links {
        "Sparky"
    }

    filter "action:vs*"
        buildoptions { "/utf-8" }


    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "SPY_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "SPY_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "SPY_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "SPY_DIST"
        optimize "On"
