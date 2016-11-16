cmake_minimum_required(VERSION 3.6)
project(libelectricity)

find_package(Threads)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

set(SOURCE_FILES_LIBELECTRICITY
#        AbstractModel.cpp AbstractModel.h AbstractElModel.cpp AbstractElModel.h Consumer.cpp Consumer.h Source.cpp Source.h GRU.cpp GRU.h
#        RintCalculator.cpp RintCalculator.h
#        LoadDivider.cpp LoadDivider.h
#        AllLoadDivider.cpp AllLoadDivider.h
#		DG.cpp DG.h PID.cc PID.h
#		SimpleDrive.cpp SimpleDrive.h
#		Q.cpp Q.h
#		Q_withDisc.cpp Q_withDisc.h
#		Drive.cpp Drive.h
#		Propeller.cpp Propeller.h
#		ShipOnRails.cpp ShipOnRails.h
#		Propulsion.cc Propulsion.h
		ModelRunner.cpp ModelRunner.h)

include_directories(${CMAKE_SOURCE_DIR}/Base)
include_directories(${CMAKE_SOURCE_DIR}/Consumers)
include_directories(${CMAKE_SOURCE_DIR}/GRU)
include_directories(${CMAKE_SOURCE_DIR}/Ships)
include_directories(${CMAKE_SOURCE_DIR}/Sources)
include_directories(${CMAKE_SOURCE_DIR}/Q)

add_subdirectory(googletest)
add_subdirectory(Base)
add_subdirectory(Consumers)
add_subdirectory(GRU)
add_subdirectory(Ships)
add_subdirectory(Sources)
add_subdirectory(Q)

add_library(electricity ${SOURCE_FILES_LIBELECTRICITY})
target_link_libraries(electricity
		Base
		Consumers
		GRU
		Ships
		Sources
		Q
		)
add_subdirectory(tests)
#-------------------------------------------------------------------
set(SOURCE_FILES main.cpp)
add_executable(libelectricity_run ${SOURCE_FILES})
target_link_libraries(libelectricity_run electricity)
