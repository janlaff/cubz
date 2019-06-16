cmake_minimum_required(VERSION 3.10)

set(
        SHADERS
        triangle
)

foreach(shader IN LISTS SHADERS)
    configure_file(${shader}.vert ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${shader}.vert COPYONLY)
    configure_file(${shader}.frag ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${shader}.frag COPYONLY)
endforeach()