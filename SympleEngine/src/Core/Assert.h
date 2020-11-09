#pragma once

#include "Core/Core.h"
#include "Core/Console.h"
#include <filesystem>

#ifdef SY_ENABLE_ASSERTS

// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
#define SY_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { SY##type##ERROR(msg, __VA_ARGS__); SY_DEBUGBREAK(); } }
#define SY_INTERNAL_ASSERT_WITH_MSG(type, check, ...) SY_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
#define SY_INTERNAL_ASSERT_NO_MSG(type, check) SY_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", SY_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

#define SY_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
#define SY_INTERNAL_ASSERT_GET_MACRO(...) SY_EXPAND_MACRO( SY_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, SY_INTERNAL_ASSERT_WITH_MSG, SY_INTERNAL_ASSERT_NO_MSG) )

// Currently accepts at least the condition and one additional parameter (the message) being optional
#define SY_ASSERT(...) SY_EXPAND_MACRO( SY_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
#define SY_CORE_ASSERT(...) SY_EXPAND_MACRO( SY_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
#define SY_ASSERT(...)
#define SY_CORE_ASSERT(...)
#endif
