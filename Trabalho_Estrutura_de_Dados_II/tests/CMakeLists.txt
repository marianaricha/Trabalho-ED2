
add_executable(test1 teste1.cc)
target_link_libraries(test1 PUBLIC tabela)

add_executable(test2 teste2.cc)
target_link_libraries(test2 PUBLIC tabela)

add_executable(test3 teste3.cc)
target_link_libraries(test3 PUBLIC tabela)

add_executable(test4_01 teste4_01.cc)
target_link_libraries(test4_01 PUBLIC tabela)

add_executable(test4_02 teste4_02.cc)
target_link_libraries(test4_02 PUBLIC tabela)

add_executable(test4_03 teste4_03.cc)
target_link_libraries(test4_03 PUBLIC tabela)

add_executable(test5 teste5.cc)
target_link_libraries(test5 PUBLIC tabela)

add_executable(test6 teste6.cc)
target_link_libraries(test6 PUBLIC tabela)