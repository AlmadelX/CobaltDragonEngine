outputdir = "%{cfg.buildcfg}-%{cfg.platform}/%{prj.name}"

local libs = {
    ["spdlog"] = "CobaltDragonEngine/vendor/spdlog/include",
    ["GLFW"]   = "CobaltDragonEngine/vendor/GLFW/include",
    ["glad"]   = "CobaltDragonEngine/vendor/glad/include",
    ["glm"]    = "CobaltDragonEngine/vendor/glm/include"
}

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

group "Dependencies"
    include "CobaltDragonEngine/vendor/GLFW"
    include "CobaltDragonEngine/vendor/glad"

group ""

project "CobaltDragonEngine"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    location "%{prj.name}"
    files { "%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp" }
    includedirs { "%{prj.name}/src", libs["spdlog"], libs["GLFW"], libs["glad"], libs["glm"] }
    pchheader "cdepch.h"
    pchsource "%{prj.name}/src/cdepch.cpp"
    links { "opengl32.lib", "GLFW", "glad" }
    staticruntime "On"
    targetdir("bin/" .. outputdir)
    objdir("bin-int/" .. outputdir)

project "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    location "%{prj.name}"
    files { "%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp" }
    includedirs { "%{prj.name}/src", "CobaltDragonEngine/src", libs["spdlog"], libs["glm"] }
    links "CobaltDragonEngine"
    staticruntime "On"
    targetdir("bin/" .. outputdir)
    objdir("bin-int/" .. outputdir)
