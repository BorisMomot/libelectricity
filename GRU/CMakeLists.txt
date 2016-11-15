set(libGRU_SOURCE_FILES )

add_library(libGRU ${libGRU_SOURCE_FILES})
target_link_libraries(libGRU STATIC libBase)