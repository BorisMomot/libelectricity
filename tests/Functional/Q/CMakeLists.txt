set(QTests_SOURCE_FILES )
include_directories(${CMAKE_SOURCE_DIR}/Q)
add_library(qTests ${QTests_SOURCE_FILES})
target_link_libraries(qTests gtest gmock Q)
