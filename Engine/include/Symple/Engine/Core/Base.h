#pragma once

#if defined(_MSC_VER)
    #if defined(SY_ENGINE_BUILD_DLL)
        #define SY_ENGINE_API __declspec(dllexport)
    #elif defined(SY_ENGINE_USE_DLL)
        #define SY_ENGINE_API __declspec(dllimport)
    #else
        #define SY_ENGINE_API
    #endif
#elif defined(__GNUC__)
#if defined(SY_ENGINE_BUILD_DLL)
        #define SY_ENGINE_API __attribute__((visibility("default")))
    #elif defined(SY_ENGINE_USE_DLL)
        #define SY_ENGINE_API __declspec(dllimport)
    #else
        #define SY_ENGINE_API
    #endif
#endif