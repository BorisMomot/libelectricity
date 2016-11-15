set(libConsumers_SOURCE_FILES Co.h Co.cpp)

add_library(libConsumers ${libConsumers_SOURCE_FILES})
include_directories(${CMAKE_SOURCE_DIR}/Base)
target_link_libraries(libConsumers STATIC libBase)
