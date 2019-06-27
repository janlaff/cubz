cmake_minimum_required(VERSION 3.10)

find_package(freetype CONFIG REQUIRED)

set(
        UI_SOURCE_FILES
        FreetypeContext.cpp
        FreetypeText.cpp
        DebugView.cpp
        TextGrid.cpp
        FreetypeChar.cpp
        FreetypeCharMap.cpp
)

add_library(ui STATIC ${UI_SOURCE_FILES})
target_link_libraries(ui graphics freetype::freetype)