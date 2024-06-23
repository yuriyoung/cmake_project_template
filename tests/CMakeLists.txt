# Testing library
# FetchContent_Declare(
#   catch
#   GIT_REPOSITORY https://github.com/catchorg/Catch2.git
#   GIT_TAG v2.13.6)
# FetchContent_MakeAvailable(catch)
# Adds Catch2::Catch2

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.14.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

include_directories(${CMAKE_SOURCE_DIR})

# Tests need to be added as executables first
add_executable(testlib testlib.cpp)
# I'm using C++17 in the test
target_compile_features(testlib PRIVATE cxx_std_17)
# Should be linked to the main library, as well as the Catch2 testing library
target_link_libraries(testlib PRIVATE libexample::libexample GTest::gtest_main)
# If you register a test, then ctest and make test will run it.
# You can also run examples and check the output, as well.
# add_test(NAME testlibtest COMMAND testlib) # Command can be a target

# gtest_discover_tests(testlib)
gtest_add_tests(TARGET testlib)

# more test ...
# ...
