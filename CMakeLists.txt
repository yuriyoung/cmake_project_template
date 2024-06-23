cmake_minimum_required(VERSION 3.12...3.30)
project(
    ExampleCMake
    VERSION 0.1.0
    DESCRIPTION "A example project with CMake"
    LANGUAGES CXX)
 
### Require out-of-source builds
file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if(EXISTS "${LOC_PATH}")
    message(FATAL_ERROR "You cannot build in a source directory (or any directory with a CMakeLists.txt file). Please make a build subdirectory. Feel free to remove CMakeCache.txt and CMakeFiles.")
endif()

# If you set any CMAKE_ variables, that can go here.
# (But usually don't do this, except maybe for C++ standard)

# Find packages go here.

# Only do these if this is the main project, and not if it is included through add_subdirectory
# 只有当这是主要项目时才这样做，而不是通过add_subdirectory包含它
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

    # Optionally set things like CMAKE_CXX_STANDARD, CMAKE_POSITION_INDEPENDENT_CODE here
    set(CMAKE_CXX_STANDARD 11 CACHE STRING "The C++ standard to use")
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    # Let's ensure -std=c++xx instead of -std=g++xx
    # set(CMAKE_CXX_EXTENSIONS OFF)
    # option(PACKAGE_TESTS "Build the tests" ON)

    set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

    # Testing only available if this is the main app
    # Note this needs to be done in the main CMakeLists since 
    # it calls enable_testing, which must be in the main CMakeLists.
    # 注意，这需要在主CMakeLists中完成，因为它调用了enable_testing，它必须在主CMakeLists中。
    include(CTest)
    enable_testing()

    # Docs only available if this is the main app
    find_package(Doxygen)
    if(Doxygen_FOUND)
        add_subdirectory(docs)
    else()
        message(STATUS "Doxygen not found, not building docs")
    endif()
endif()

# FetchContent added in CMake 3.11, downloads during the configure step
# FetchContent_MakeAvailable was added in CMake 3.14; simpler usage
include(FetchContent)

# Accumulator library
# This is header only, so could be replaced with git submodules or FetchContent
# find_package(Boost REQUIRED)
# Adds Boost::boost

# Formatting library
# FetchContent_Declare(
#   fmtlib
#   GIT_REPOSITORY https://github.com/fmtlib/fmt.git
#   GIT_TAG 5.3.0)
# FetchContent_MakeAvailable(fmtlib) # CMake 3.14+
# Adds fmt::fmt

# The compiled library code is here
add_subdirectory(src)

# The executable code is here
add_subdirectory(apps)

# Testing only available if this is the main app
if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME) AND BUILD_TESTING)
   add_subdirectory(tests)
endif()

if(MSVC)
    add_compile_options($<$<CXX_COMPILER_ID:MSVC>:/MP>)
endif(MSVC)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
