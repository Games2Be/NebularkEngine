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
        "%{prj.name}/vendor/glfw/include",
        os.getenv("VULKAN_SDK") .. "/Include"

    }

    libdirs {
        os.getenv("VULKAN_SDK") .. "/Lib"
    }

    links {
        "glfw3",
        "vulkan-1"
    }

    filter "configurations:Debug"
        libdirs { "Nebulark/vendor/glfw/build/src/Debug" }

    filter "configurations:Release or Dist"
        libdirs { "Nebulark/vendor/glfw/build/src/Release" }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "Off"
        systemversion "latest"
        buildoptions { "/utf-8" }

        defines {
            "NBL_PLATFORM_WINDOWS",
            "NBL_BUILD_DLL"
        }

        postbuildcommands {
            '{COPY} "%{cfg.buildtarget.relpath}" "../bin/' .. outputdir .. '/Sandbox/"',
            '{COPY} "$(VULKAN_SDK)/Lib/vulkan-1.lib" "../bin/' .. outputdir .. '/Sandbox/"'
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
        "Nebulark/vendor/glfw/include",
        os.getenv("VULKAN_SDK") .. "/Include",
        "Nebulark/src"
    }
    
    links {
        "Nebulark"
    }


    filter "system:windows"
        cppdialect "C++17"
        staticruntime "Off"
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