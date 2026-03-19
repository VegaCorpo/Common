cmake_minimum_required(VERSION 3.14)

project(orbital_common)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION ON)
set(CMAKE_CXX_STANDARD 23 CACHE STRING "C++ standard")
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CPM_USE_LOCAL_PACKAGES ON)

include(${CMAKE_CURRENT_LIST_DIR}/cmake/CPM.cmake)
CPMUsePackageLock(${CMAKE_CURRENT_LIST_DIR}/package-lock.cmake)
CPMGetPackage("glfw")


file(GLOB_RECURSE src "*.hpp")

add_library(Common INTERFACE)

target_include_directories(Common
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CPM_PACKAGE_glfw_SOURCE_DIR}/include>
)

target_link_libraries(Common INTERFACE glfw)

target_sources(Common INTERFACE ${src})
