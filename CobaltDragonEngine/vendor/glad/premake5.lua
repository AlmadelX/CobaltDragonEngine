project "glad"
    kind "StaticLib"
    language "C"
    files { "include/glad/glad.h", "include/KHR/khrplatform.h", "src/glad.c" }
    includedirs "include"
    staticruntime "On"
    targetdir("%{wks.location}/bin/" .. outputdir)
    objdir("%{wks.location}/bin-int/" .. outputdir)
