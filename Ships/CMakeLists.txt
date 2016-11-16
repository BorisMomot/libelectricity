set(libShips_SOURCE_FILES
		Drive.cpp Drive.h
		Propeller.cpp Propeller.h
		Propulsion.cpp Propulsion.h
		ShipOnRails.cpp ShipOnRails.h)

add_library(Ships ${libShips_SOURCE_FILES})
include_directories(${CMAKE_SOURCE_DIR}/Base)
target_link_libraries(Ships Base)