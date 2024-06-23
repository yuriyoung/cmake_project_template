
set(LIBRARY_NAME "libexample")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

if(MSVC)
    add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
endif(MSVC)

# Note that headers are optional, and do not affect add_library, but they will not
# show up in IDEs unless they are listed in add_library.
# 注意，头文件是可选的，并且不影响add_library，但是它们不会显示在IDE中，除非它们被列在add_library中。

# Optionally glob, but only for CMake 3.12 or later:
file(GLOB HEADER_FILES CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/libexample/*.h")
file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)
# Group files

# Make an automatic library - will be static or dynamic based on user setting
add_library(${LIBRARY_NAME} STATIC ${SOURCES} ${HEADER_FILES})

# Link the library suing alias: target_link_libraries(${PROJECT_NAME} libexample::libexample)
add_library(libexample::${LIBRARY_NAME} ALIAS ${LIBRARY_NAME})

# We need this directory, and users of our library will need it too
# This will cause the include directories for this project to be added to that target
target_include_directories(${LIBRARY_NAME}
	PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
	PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

# this command will append "d" to the name of the debug version of
# the library - this is very helpful when installing as it ensures
# the debug and release version of library can be installed to the
# same location and will not conflict (overwrite each other)
set_target_properties(${LIBRARY_NAME} PROPERTIES DEBUG_POSTFIX "d")

# Then copy each of the header files over to that include directory.
#NOTE: DO NOT missing the final slash
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/
    DESTINATION ${PROJECT_SOURCE_DIR}/include/libexample/
    FILES_MATCHING PATTERN "*.h*"
)

# This depends on (header only) boost
# target_link_libraries(${LIBRARY_NAME} PRIVATE Boost::boost)

# All users of this library will need at least C++11
target_compile_features(${LIBRARY_NAME} PUBLIC cxx_std_11)

# IDEs should put the headers in a nice place
# source_group(
#   TREE "${PROJECT_SOURCE_DIR}/include"
#   PREFIX "Header Files"
#   FILES ${HEADER_FILES})


export(TARGETS ${LIBRARY_NAME} NAMESPACE libexample:: FILE ${LIBRARY_NAME}-targets.cmake)

install(
	#NOTE: DO NOT missing the final slash
    DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/
    DESTINATION include/libexample
    FILES_MATCHING PATTERN "*.h*"
)

install(
	TARGETS ${LIBRARY_NAME}
	EXPORT ${LIBRARY_NAME}-targets
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
	INCLUDES DESTINATION include/libexample
)

install(EXPORT ${LIBRARY_NAME}-targets
    FILE ${LIBRARY_NAME}-targets.cmake
    NAMESPACE libexample::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${LIBRARY_NAME}
)
