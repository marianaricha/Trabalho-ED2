
file(GLOB source_files src/*.cc include/*.h)
add_library(tabela ${source_files})
target_include_directories(tabela PUBLIC ${PROJECT_SOURCE_DIR}/include)