set(libQ_SOURCE_FILES
		Q.cpp Q.h
		Q_withDisc.cpp Q_withDisc.h)

add_library(Q ${libQ_SOURCE_FILES})
include_directories(${CMAKE_SOURCE_DIR}/Base)
target_link_libraries(Q Base)