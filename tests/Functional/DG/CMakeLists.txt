set(DGTests_SOURCE_FILES )
include_directories(${CMAKE_SOURCE_DIR}/Sources)
add_library(dgTests ${DGTests_SOURCE_FILES})
target_link_libraries(dgTests gtest gmock Sources)