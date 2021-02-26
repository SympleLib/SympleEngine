project(SympleEngine-Engine)
message(STATUS "Setting up the Engine")

set(TARGET_NAME SympleEngine)
add_library(
        ${TARGET_NAME} STATIC
        src/Test.cpp
)

target_include_directories(${TARGET_NAME} PUBLIC include)
target_include_directories(${TARGET_NAME} PRIVATE src)