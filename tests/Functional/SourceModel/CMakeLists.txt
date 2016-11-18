set(SourceTests_SOURCE_FILES )
include_directories(${CMAKE_SOURCE_DIR}/Sources)
add_library(sourceTests ${SourceTests_SOURCE_FILES})
target_link_libraries(sourceTests gtest gmock Sources)