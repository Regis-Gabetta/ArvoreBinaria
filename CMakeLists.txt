cmake_minimum_required(VERSION 3.3)

project(ArvoreBinaria C CXX)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories (
  header/
  src/
  include/
)

set (HEADERS
	header/Arvore.h
)

set (SRC
	src/main.cpp
)

set (ALL ${HEADERS} ${SRC})

add_library(lib
${ALL})

foreach (FILE ${ALL})
  message (${FILE}) 
endforeach (FILE)

add_executable(main_arvore src/main.cpp)
target_link_libraries(main_arvore lib)

