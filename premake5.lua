-- premake5.lua
workspace "Hazel"
	architecture "x64"
   configurations { "Debug", "Release", "Dist" }

   outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{}"

project "Hazel"
	location "Hazel"
	kind "SharedLib"
	langue "c++"
	targetdir ("bin/" ..outputdir.. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h"
		"%{prj.name}/src/**.cpp"
	}

	include
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.17763.0"

		defines
		{
			"HZ_PLATFORM_WINDOWS",
			"HZ_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir.. "/Sandbox)
		}
