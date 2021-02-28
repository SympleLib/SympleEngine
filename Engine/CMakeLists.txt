project(SympleEngine-Engine)
message(STATUS "Setting up Symple Engine")

set(SY_ENGINE_ENABLE_PROFILE ON CACHE BOOL "Enable or disable profiling?" FORCE)

find_package(glfw3 CONFIG REQUIRED)

set(TARGET_NAME SympleEngine)
add_library(
        ${TARGET_NAME} STATIC
        include/Symple/Engine/Core/Base.h
        src/Core/Application.cpp
        include/Symple/Engine/Core/Application.h
        include/Symple/Engine/Core/EntryPoint.h
        include/Symple/Engine/SympleEngine.h
        include/Symple/Engine/Core/Object.h
        include/Symple/Engine/Graphics/Window.h
)

#if (WIN32)
    target_sources(
        ${TARGET_NAME}
        PRIVATE include/Platform/GLFW/GLFWWindow.h
        PRIVATE src/Platform/GLFW/GLFWWindow.cpp
    )
#endif()

target_include_directories(${TARGET_NAME} PUBLIC include)
target_include_directories(${TARGET_NAME} PRIVATE src)

if (CMAKE_BUILD_TYPE EQUAL "DEBUG")
    add_compile_definitions(SY_DEBUG)
endif()