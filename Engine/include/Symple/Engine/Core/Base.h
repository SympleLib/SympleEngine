#pragma once

#if !defined(__has_declspec_attribute)
    #define __has_declspec_attribute(attr) _MSC_VER
#endif

#if __has_declspec_attribute(dllexport) && __has_declspec_attribute(dllimport)
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

    #define SY_ENGINE_PROPERTY_GET(getter)
    #define SY_ENGINE_PROPERTY_GET_SET(getter, setter)
#endif

#if __has_declspec_attribute(property)
    #define SY_ENGINE_PROPERTY_GET(getter) __declspec(property(get = getter))
    #define SY_ENGINE_PROPERTY_GET_SET(getter, setter) __declspec(property(get = getter, put = setter))
#endif

#if defined(SY_DEBUG)
#   ifndef SY_ASSERT
        #define SY_ASSERT(c, msg, ...) if (!(c)) { std::fprintf(stderr, msg "\n", ##__VA_ARGS__); std::abort(); }
    #endif
#else
    #ifndef SY_ASSERT
        #define SY_ASSERT(c, msg, ...)
    #endif
#endif

#include <cstdio>

#include "Symple/Engine/Core/Object.h"