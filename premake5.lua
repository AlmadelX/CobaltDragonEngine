local outputdir = "%{cfg.buildcfg}-%{cfg.platform}/%{prj.name}"

workspace "CobaltDragonEngine"
    configurations { "Debug", "Release", "Dist" }
    platforms "Windows"
    startproject "Sandbox"

    filter "configurations:Debug"
        defines "CDE_DEBUG"
        runtime "Debug"
        symbols "On"
    
    filter "configurations:Release"
        defines "CDE_RELEASE"
        runtime "Release"
        optimize "On"
    
    filter "configurations:Dist"
        defines "CDE_DIST"
        runtime "Release"
        optimize "On"
    
    filter "platforms:Windows"
        defines "CDE_PLATFORM_WINDOWS"
        architecture "x64"
        system "Windows"

project "CobaltDragonEngine"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    location "%{prj.name}"
    files { "%{prj.name}/src/**.cpp", "%{prj.name}/src/**.h" }
    includedirs "%{prj.name}/src"
    staticruntime "On"
    targetdir("bin/" .. outputdir)
    objdir("bin-int/" .. outputdir)

project "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    location "%{prj.name}"
    files { "%{prj.name}/src/**.cpp", "%{prj.name}/src/**.h" }
    includedirs { "%{prj.name}/src", "CobaltDragonEngine/src" }
    links "CobaltDragonEngine"
    staticruntime "On"
    targetdir("bin/" .. outputdir)
    objdir("bin-int/" .. outputdir)
