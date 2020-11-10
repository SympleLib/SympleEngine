#pragma once

#ifdef SY_PLATFORM_WINDOWS
#ifdef SY_BUILD_DLL
#define SYMPLE_API __declspec(dllexport)
#else
#define SYMPLE_API __declspec(dllimport)
#endif
#else
#error Symple Engine only supports windows!
#endif

#ifdef _SY_DEBUG
#define SY_ENABLE_ASSERTS
#endif

#include <memory>

namespace Symple
{
	template<typename T>
	using Reference = std::shared_ptr<T>;

	template<typename T, typename ... Args>
	constexpr Reference<T> MakeReference(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T, typename ... Args>
	constexpr Scope<T> MakeScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}
}