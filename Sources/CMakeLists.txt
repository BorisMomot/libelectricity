set(libSources_SOURCE_FILES )

add_library(libSources ${libSources_SOURCE_FILES})
target_link_libraries(libSources STATIC libBase)