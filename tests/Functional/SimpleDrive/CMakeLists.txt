set(SimpleDriveTests_SOURCE_FILES )
include_directories(${CMAKE_SOURCE_DIR}/Consumers)
add_library(simpleDriveTests ${SimpleDriveTests_SOURCE_FILES})
target_link_libraries(simpleDriveTests gtest gmock Consumers)
