workspace "Nebulark"
    architecture "x64"
    
    configurations
    { 
        "Debug",
        "Release",
        "Dist" 
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Nebulark"
    location "Nebulark"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "%{prj.name}/vendor/spdlog/include",
        "%{prj.name}/vendor/SDL/SDL3/include",
        "%{prj.name}/vendor/ImGui",
        "%{prj.name}/vendor/Vulkan/include"
    }

    libdirs {
        "%{prj.name}/vendor/SDL/SDL3/lib/x64"
    }

    links {
        "SDL3"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
        buildoptions { "/utf-8" }

        defines {
            "NBL_PLATFORM_WINDOWS",
            "NBL_BUILD_DLL"
        }

        postbuildcommands {
            "{COPY} \"%{cfg.buildtarget.relpath}\" ../bin/" .. outputdir .. "/Sandbox",
        }




    filter "configurations:Debug"
        defines "NBL_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "NBL_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "NBL_DIST"
        optimize "On"


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
        "Nebulark/vendor/spdlog/include",
        "Nebulark/vendor/ImGui",
        "Nebulark/vendor/SDL/SDL3/include",
        "Nebulark/vendor/Vulkan/include",
        "Nebulark/src"
    }
    
    links {
        "Nebulark"
    }


    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
        buildoptions { "/utf-8" }

        defines {
            "NBL_PLATFORM_WINDOWS"
        }
        

    filter "configurations:Debug"
        defines "NBL_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "NBL_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "NBL_DIST"
        optimize "On"