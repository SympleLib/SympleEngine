workspace "SympleEngine"
	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Production"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

includeMap = {};
includeMap["spdlog"] = "SympleEngine/vender/spdlog/include"
includeMap["GLFW"] = "SympleEngine/vender/GLFW/include"

include "SympleEngine/vender/GLFW"

project "SympleEngine"
	location "SympleEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "syegpch.h"
	pchsource "SympleEngine/src/syegpch.cpp"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.c",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/src",
		"%{includeMap.spdlog}",
		"%{includeMap.GLFW}"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"SY_PLATFORM_WINDOWS",
			"SY_BUILD_DLL"
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SympleExample")
		}

	filter "configurations:Debug"
		defines "SY_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SY_RELEASE"
		optimize "On"

	filter "configurations:Production"
		defines "SY_PRODUCTION"
		optimize "On"

project "SympleExample"
	location "SympleExample"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.c",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{includeMap.spdlog}",
		"%{includeMap.GLFW}",
		"SympleEngine/src"
	}

	links {
		"SympleEngine",
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"SY_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "SY_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SY_RELEASE"
		optimize "On"

	filter "configurations:Production"
		defines "SY_PRODUCTION"
		optimize "On"