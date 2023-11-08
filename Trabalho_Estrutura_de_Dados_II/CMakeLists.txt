

cmake_minimum_required(VERSION 3.14)
project(dcc012b-trab2-team-mmvg)

option(CLASSROOM "Enable classroom build" OFF)
option(CPU_TIME  "Enable cputime build" ON)

set(INPUT_DIR "${PROJECT_SOURCE_DIR}/tests/input/")
set(TESTES_DIR "${PROJECT_SOURCE_DIR}/tests/")
set(EXPECTED_OUTPUT_DIR "${PROJECT_SOURCE_DIR}/tests/expected_output/")
set(BUILD_DIR "${PROJECT_SOURCE_DIR}/build/")

configure_file(${PROJECT_SOURCE_DIR}/tabela/config.h.in ${PROJECT_SOURCE_DIR}/tabela/include/config.h) 
include_directories(${PROJECT_SOURCE_DIR}/tabela/include)


enable_testing()
add_subdirectory(tabela)
add_subdirectory(tests)

# # teste 1:
# add_test(
#     NAME EncontraPalavrasMaisFrequentes
#     COMMAND $<TARGET_FILE:test1>
# )

# # teste 2:
# add_test(
#     NAME TestaRotinasHash
#     COMMAND $<TARGET_FILE:test2>
# )

# # teste 3:
# add_test(
#     NAME ComparativoFuncHash
#     COMMAND $<TARGET_FILE:test3>
# )

# teste 4_01:
add_test(
    NAME TesteInsercaoABD
    COMMAND cmake -E compare_files test4_01.csv ${PROJECT_SOURCE_DIR}/tests/expected_output/test4_01.csv
)

# teste 4_02:
add_test(
    NAME TesteBuscaABD
    COMMAND $<TARGET_FILE:test4_02>
)

# teste 4_03:
add_test(
    NAME TesteRemocaoABD
    COMMAND $<TARGET_FILE:test4_03> && cmake -E compare_files test4_03.csv ${PROJECT_SOURCE_DIR}/tests/expected_output/test4_03.csv
)