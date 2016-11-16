set(libBase_SOURCE_FILES AbstractModel.cpp AbstractElModel.h
		Convinience_functions.h
		AbstractElModel.cpp AbstractElModel.h
		PID.cc PID.h)

add_library(Base ${libBase_SOURCE_FILES})
