cmake_minimum_required(VERSION 3.6)
project(libelectricity)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES_LIBELECTRICITY
        AbstractModel.cpp AbstractModel.h AbstractElModel.cpp AbstractElModel.h Consumer.cpp Consumer.h Source.cpp Source.h GRU.cpp GRU.h
        RintCalculator.cpp RintCalculator.h
        LoadDivider.cpp LoadDivider.h
        AllLoadDivider.cpp AllLoadDivider.h)

add_library(libelectricity STATIC ${SOURCE_FILES_LIBELECTRICITY})

add_subdirectory(googletest)
add_subdirectory(tests)

set(SOURCE_FILES main.cpp)
add_executable(libelectricity_run ${SOURCE_FILES})
target_link_libraries(libelectricity_run libelectricity)
#target_include_directories(test1 PUBLIC Class1Lib PUBLIC statesLib PUBLIC AbstractFactoryLib PUBLIC BuilderLib PUBLIC turtleLib)