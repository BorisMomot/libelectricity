set(PITests_SOURCE_FILES )
include_directories(${CMAKE_SOURCE_DIR}/Base)
add_library(piTests ${PITests_SOURCE_FILES})
target_link_libraries(piTests gtest gmock Base)
