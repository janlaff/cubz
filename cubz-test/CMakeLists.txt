cmake_minimum_required(VERSION 3.10)

set(
        CUBZ_TEST_SOURCE_FILES
        main.cpp
)

add_executable(cubz-test ${CUBZ_TEST_SOURCE_FILES})
target_link_libraries(cubz-test cubz-engine)
target_include_directories(cubz-test PUBLIC .)

file(COPY assets DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})