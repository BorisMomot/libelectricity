set(libShips_SOURCE_FILES )

add_library(libShips ${libShips_SOURCE_FILES})
target_link_libraries(libShips STATIC libBase)