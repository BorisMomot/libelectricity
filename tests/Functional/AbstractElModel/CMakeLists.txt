set(abstractModelTests_SOURCE_FILES )
include_directories(${CMAKE_SOURCE_DIR}/Base)
add_library(abstractModelTests ${abstractModelTests_SOURCE_FILES})
target_link_libraries(abstractModelTests gtest gmock	Base)
