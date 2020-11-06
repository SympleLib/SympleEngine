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