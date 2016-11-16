set(libConsumers_SOURCE_FILES
		Consumer.cpp Consumer.h
		SimpleDrive.cpp SimpleDrive.h)

include_directories(${CMAKE_SOURCE_DIR}/Base)
add_library(Consumers ${libConsumers_SOURCE_FILES})
target_link_libraries(Consumers Base)
