add_library(vec_f_library
  vec_f.cpp)

add_library(mat_f_library
  mat_f.cpp)

target_link_libraries(mat_f_library
  vec_f_library)


  
add_executable(programma_vettori
  vec_f_test.cpp)

target_link_libraries(programma_vettori
  vec_f_library)

add_executable(programma_matrici
  mat_f_test.cpp)

target_link_libraries(programma_matrici
  mat_f_library
  vec_f_library)
