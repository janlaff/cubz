cmake_minimum_required(VERSION 3.10)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/triangle.vert ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/triangle.vert COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/triangle.frag ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/triangle.frag COPYONLY)