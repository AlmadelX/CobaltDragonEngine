project "ImGui"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    files {
        "include/imconfig.h",
        "include/imgui.h",
        "include/imgui_internal.h",
        "include/imstb_rectpack.h",
        "include/imstb_textedit.h",
        "include/imstb_truetype.h",
        "include/imgui.cpp",
        "include/imgui_demo.cpp",
        "include/imgui_draw.cpp",
        "include/imgui_tables.cpp",
        "include/imgui_widgets.cpp"
    }
    includedirs "include"
    staticruntime "On"
    targetdir("%{wks.location}/bin/" .. outputdir)
    objdir("%{wks.location}/bin-int/" .. outputdir)
