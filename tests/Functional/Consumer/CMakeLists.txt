set(ConsumerTests_SOURCE_FILES )
include_directories(${CMAKE_SOURCE_DIR}/Consumers)
add_library(consumerTests ${ConsumerTests_SOURCE_FILES})
target_link_libraries(consumerTests gtest gmock	Consumers)


