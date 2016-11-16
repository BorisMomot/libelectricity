set(Test1_SOURCE_FILES )

include_directories(${CMAKE_SOURCE_DIR}/Base)
include_directories(${CMAKE_SOURCE_DIR}/Consumers)
include_directories(${CMAKE_SOURCE_DIR}/GRU)
include_directories(${CMAKE_SOURCE_DIR}/Ships)
include_directories(${CMAKE_SOURCE_DIR}/Sources)
include_directories(${CMAKE_SOURCE_DIR}/Q)

add_executable(test1 ${Test1_SOURCE_FILES})
target_link_libraries(test1 gtest gmock
		Base
		Consumers
		GRU
		Ships
		Sources
		Q
#		STATIC libelectricity
		)
#target_include_directories(test1 PUBLIC libelectricity )
