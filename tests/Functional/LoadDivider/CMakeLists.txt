set(LoadDividerTests_SOURCE_FILES )
include_directories(${CMAKE_SOURCE_DIR}/GRU)
add_library(loadDividerTests ${LoadDividerTests_SOURCE_FILES})
target_link_libraries(loadDividerTests gtest gmock GRU)