set(Test1_SOURCE_FILES tests.cpp AbstractElModel_Test.cpp AbstractElModel_Test.h SourceModel_Test.cpp SourceModel_Test.h
        RintCalculator_Test.cpp RintCalculator_Test.h
        LoadDivider_Test.cpp LoadDivider_Test.h
        GRU_Test.cpp GRU_Test.h
        PI_Test.cpp PI_Test.h)

add_executable(test1 ${Test1_SOURCE_FILES})
target_link_libraries(test1 gtest gmock libelectricity)
target_include_directories(test1 PUBLIC libelectricity )
