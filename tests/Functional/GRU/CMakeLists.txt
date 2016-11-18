set(GRUTests_SOURCE_FILES )
include_directories(${CMAKE_SOURCE_DIR}/GRU)
add_library(gruTests ${GRUTests_SOURCE_FILES})
target_link_libraries(gruTests gtest gmock GRU)