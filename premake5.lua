workspace "SympleEngine"
	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Production"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "SympleEngine"
	location "SympleEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.c",
		"%{prj.name}/src/**.cpp"
	}

	include {
		"%{prj.name}/vender/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"

	SY_PLATFORM_WINDOWS;SY_BUILD_DLL;_WINDLL;