set(Test1_SOURCE_FILES
		${CMAKE_SOURCE_DIR}/tests/Functional/AbstractElModel/AbstractElModel_Test.cpp
		${CMAKE_SOURCE_DIR}/tests/Functional/AbstractElModel/AbstractElModel_Test.h
		${CMAKE_SOURCE_DIR}/tests/Functional/SourceModel/SourceModel_Test.cpp
		${CMAKE_SOURCE_DIR}/tests/Functional/SourceModel/SourceModel_Test.h
		${CMAKE_SOURCE_DIR}/tests/Functional/RintCalculator/RintCalculator_Test.cpp
		${CMAKE_SOURCE_DIR}/tests/Functional/RintCalculator/RintCalculator_Test.h
		${CMAKE_SOURCE_DIR}/tests/Functional/LoadDivider/LoadDivider_Test.cpp
		${CMAKE_SOURCE_DIR}/tests/Functional/LoadDivider/LoadDivider_Test.h
#		${CMAKE_SOURCE_DIR}/tests/Functional/GRU/GRU_Test.cpp
#		${CMAKE_SOURCE_DIR}/tests/Functional/GRU/GRU_Test.h
		${CMAKE_SOURCE_DIR}/tests/Functional/PI/PI_Test.cpp
		${CMAKE_SOURCE_DIR}/tests/Functional/PI/PI_Test.h
		${CMAKE_SOURCE_DIR}/tests/Functional/DG/DG_Test.cpp
		${CMAKE_SOURCE_DIR}/tests/Functional/DG/DG_Test.h
		${CMAKE_SOURCE_DIR}/tests/Functional/SimpleDrive/SimpleDrive_Test.cpp
		${CMAKE_SOURCE_DIR}/tests/Functional/SimpleDrive/SimpleDrive_Test.h
		${CMAKE_SOURCE_DIR}/tests/Functional/Q/Q_Test.cpp
		${CMAKE_SOURCE_DIR}/tests/Functional/Q/Q_Test.h
		${CMAKE_SOURCE_DIR}/tests/Functional/Consumer/Consumer_Test.cpp
		${CMAKE_SOURCE_DIR}/tests/Functional/Consumer/Consumer_Test.h

		${CMAKE_SOURCE_DIR}/tests/Stress/AbstractElModel/MultithreadWorkTest.cpp
		${CMAKE_SOURCE_DIR}/tests/Stress/AbstractElModel/MultithreadWorkTest.h
		tests.cpp)

include_directories(${CMAKE_SOURCE_DIR}/tests/Functional/AbstractElModel/)
include_directories(${CMAKE_SOURCE_DIR}/tests/Functional/Consumer/)
include_directories(${CMAKE_SOURCE_DIR}/tests/Functional/DG/)
include_directories(${CMAKE_SOURCE_DIR}/tests/Functional/GRU/)
include_directories(${CMAKE_SOURCE_DIR}/tests/Functional/LoadDivider/)
include_directories(${CMAKE_SOURCE_DIR}/tests/Functional/PI/)
include_directories(${CMAKE_SOURCE_DIR}/tests/Functional/Q/)
include_directories(${CMAKE_SOURCE_DIR}/tests/Functional/RintCalculator/)
include_directories(${CMAKE_SOURCE_DIR}/tests/Functional/SimpleDrive/)
include_directories(${CMAKE_SOURCE_DIR}/tests/Functional/SourceModel/)

include_directories(${CMAKE_SOURCE_DIR}/tests/Stress/AbstractElModel/)


add_subdirectory(Functional)
#add_subdirectory(Integration)
#add_subdirectory(Perfomance)
add_subdirectory(Stress)

add_executable(test1 ${Test1_SOURCE_FILES})
target_link_libraries(test1 gtest gmock
		abstractModelTests
		consumerTests
		dgTests
		gruTests
		loadDividerTests
		piTests
		qTests
		rintCalculatorTests
		simpleDriveTests
		sourceTests
		)
