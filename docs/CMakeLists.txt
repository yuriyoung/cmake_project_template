set(DOXYGEN_EXTRACT_ALL YES)
set(DOXYGEN_BUILTIN_STL_SUPPORT YES)

doxygen_add_docs(docs libexample/example.h "${CMAKE_CURRENT_SOURCE_DIR}/MainPage.md"
                 WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}/include")
