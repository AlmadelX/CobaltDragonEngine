project "glad"
    kind "StaticLib"
    language "C"
    files { "include/**.h", "src/glad.c" }
    includedirs "include"
    staticruntime "On"
    targetdir("%{wks.location}/bin/" .. outputdir)
    objdir("%{wks.location}/bin-int/" .. outputdir)
