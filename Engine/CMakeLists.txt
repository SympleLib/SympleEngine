project(SympleEngine-Engine)
message(STATUS "Setting up the Engine")

set(TARGET_NAME SympleEngine)
add_library(
        ${TARGET_NAME} STATIC
        include/Symple/Engine/Core/Base.h
        src/Core/Application.cpp
        include/Symple/Engine/Core/Application.h
        include/Symple/Engine/Core/EntryPoint.h
        include/Symple/Engine/SympleEngine.h
)

target_include_directories(${TARGET_NAME} PUBLIC include)
target_include_directories(${TARGET_NAME} PRIVATE src)