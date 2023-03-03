outputdir = "%{cfg.buildcfg}-%{cfg.platform}/%{prj.name}"

libs = {
    ["spdlog"] = "%{wks.location}/vendor/spdlog/include",
    ["GLFW"]   = "%{wks.location}/CobaltDragonEngine/vendor/GLFW/include",
    ["glad"]   = "%{wks.location}/CobaltDragonEngine/vendor/glad/include",
    ["glm"]    = "%{wks.location}/vendor/glm/include",
    ["ImGui"]  = "%{wks.location}/vendor/ImGui/include"
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

group "dependencies"
    include "vendor/spdlog"
    include "CobaltDragonEngine/vendor/GLFW"
    include "CobaltDragonEngine/vendor/glad"
    include "vendor/ImGui"

group ""

project "CobaltDragonEngine"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    location "%{prj.name}"
    files {
        "%{prj.name}/src/cdepch.h",
        "%{prj.name}/src/CobaltDragonEngine.h",
        "%{prj.name}/src/CobaltDragonEngine/**.h",
        "%{prj.name}/src/cdepch.cpp",
        "%{prj.name}/src/CobaltDragonEngine/**.cpp"
    }
    includedirs { "%{prj.name}/src", libs["spdlog"], libs["GLFW"], libs["glad"], libs["glm"], libs["ImGui"] }
    pchheader "cdepch.h"
    pchsource "%{prj.name}/src/cdepch.cpp"
    links { "opengl32.lib", "GLFW", "glad", "ImGui", "spdlog" }
    staticruntime "On"
    targetdir("bin/" .. outputdir)
    objdir("bin-int/" .. outputdir)

    filter "platforms:Windows"
        files {
            "%{prj.name}/src/platform/Windows/**.h",
            "%{prj.name}/src/platform/OpenGL/**.h",
            "%{prj.name}/src/platform/Windows/**.cpp",
            "%{prj.name}/src/platform/OpenGL/**.cpp"
        }

project "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    location "%{prj.name}"
    files { "%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp" }
    includedirs { "%{prj.name}/src", "CobaltDragonEngine/src", libs["spdlog"], libs["glm"], libs["ImGui"] }
    links "CobaltDragonEngine"
    staticruntime "On"
    targetdir("bin/" .. outputdir)
    objdir("bin-int/" .. outputdir)
