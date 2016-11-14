cmake_minimum_required(VERSION 3.6)
project(libelectricity)

find_package(Threads)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

set(SOURCE_FILES_LIBELECTRICITY
        AbstractModel.cpp AbstractModel.h AbstractElModel.cpp AbstractElModel.h Consumer.cpp Consumer.h Source.cpp Source.h GRU.cpp GRU.h
        RintCalculator.cpp RintCalculator.h
        LoadDivider.cpp LoadDivider.h
        AllLoadDivider.cpp AllLoadDivider.h
		DG.cpp DG.h PID.cc PID.h
		SimpleDrive.cpp SimpleDrive.h
		Q.cpp Q.h
		Q_withDisc.cpp Q_withDisc.h
		ModelRunner.cpp ModelRunner.h
		Drive.cpp Drive.h
		Propeller.cpp Propeller.h
		ShipOnRails.cpp ShipOnRails.h)

add_library(libelectricity STATIC ${SOURCE_FILES_LIBELECTRICITY})

add_subdirectory(googletest)
add_subdirectory(tests)

set(SOURCE_FILES main.cpp)
add_executable(libelectricity_run ${SOURCE_FILES})
target_link_libraries(libelectricity_run libelectricity)
#target_include_directories(test1 PUBLIC Class1Lib PUBLIC statesLib PUBLIC AbstractFactoryLib PUBLIC BuilderLib PUBLIC turtleLib)