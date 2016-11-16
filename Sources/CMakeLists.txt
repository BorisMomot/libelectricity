set(libSources_SOURCE_FILES
		Source.cpp Source.h
		RintCalculator.cpp RintCalculator.h
		DG.cpp DG.h
		)

add_library(Sources ${libSources_SOURCE_FILES})
include_directories(${CMAKE_SOURCE_DIR}/Base)
target_link_libraries(Sources Base)