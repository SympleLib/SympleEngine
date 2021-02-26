project(SympleEngine-Sandbox)
message(STATUS "Setting up Example")

set(TARGET_NAME SympleEngine-Sandbox)
file(GLOB_RECURSE SRCS "src/**.cpp" "src/**.h")
add_executable(
        ${TARGET_NAME} ${SRCS}
        src/Main.cpp
)
target_include_directories(${TARGET_NAME} PUBLIC src)

target_link_libraries(${TARGET_NAME} PRIVATE SympleEngine)