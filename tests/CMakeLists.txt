set(Test1_SOURCE_FILES tests.cpp AbstractElModel_Test.cpp AbstractElModel_Test.h SourceModel_Test.cpp SourceModel_Test.h
        RintCalculator_Test.cpp RintCalculator_Test.h
        LoadDivider_Test.cpp LoadDivider_Test.h
        GRU_Test.cpp GRU_Test.h
        PI_Test.cpp PI_Test.h
        DG_Test.cpp DG_Test.h
        SimpleDrive_Test.cpp SimpleDrive_Test.h
        Q_Test.cpp Q_Test.h
        Consumer_Test.cpp Consumer_Test.h)

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
