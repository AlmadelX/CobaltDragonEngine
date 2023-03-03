project "spdlog"
    kind "StaticLib"
    language "C++"
    cppdialect "C++11"
    files { "include/spdlog/**.h", "src/**.cpp" }
    defines "SPDLOG_COMPILED_LIB"
    includedirs "include"
    staticruntime "On"
    targetdir("%{wks.location}/bin/" .. outputdir)
    objdir("%{wks.location}/bin-int/" .. outputdir)
