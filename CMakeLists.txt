cmake_minimum_required(VERSION 3.16)

include(vendor/cmake/VcpkgToolchain.cmake)

project(SympleEngine)

set(CMAKE_C_STANDARD 20)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set(CMAKE_C_FLAGS "-Wall")
#set(CMAKE_CXX_FLAGS "-Wall")

add_subdirectory(Engine)
add_subdirectory(Sandbox)