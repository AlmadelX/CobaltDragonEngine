project "ImGui"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    files { "include/**.h", "include/**.cpp" }
    includedirs { "include", libs["GLFW"] }
    links "GLFW"
    staticruntime "On"
    targetdir("%{wks.location}/bin/" .. outputdir)
    objdir("%{wks.location}/bin-int/" .. outputdir)
