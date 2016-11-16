set(libGRU_SOURCE_FILES
		AllLoadDivider.cpp AllLoadDivider.h
		LoadDivider.cpp LoadDivider.h
		GRU.cpp GRU.h)

add_library(GRU ${libGRU_SOURCE_FILES})
include_directories(${CMAKE_SOURCE_DIR}/Base)
include_directories(${CMAKE_SOURCE_DIR}/Sources)
include_directories(${CMAKE_SOURCE_DIR}/Consumers)
target_link_libraries(GRU Base)
target_link_libraries(GRU Sources)
target_link_libraries(GRU Consumers)
