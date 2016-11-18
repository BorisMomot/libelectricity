set(RintCalculatorTests_SOURCE_FILES )
include_directories(${CMAKE_SOURCE_DIR}/GRU)
add_library(rintCalculatorTests ${RintCalculatorTests_SOURCE_FILES})
target_link_libraries(rintCalculatorTests gtest gmock GRU)
