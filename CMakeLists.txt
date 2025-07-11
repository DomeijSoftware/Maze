cmake_minimum_required(VERSION 3.28)
project(Engine LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

# Hitta alla .cpp-filer rekursivt i src
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    ${PROJECT_SOURCE_DIR}/src/*.cpp
)

add_executable(main ${SOURCES})

target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries(main PRIVATE SFML::Graphics)

# Hitta alla undermappar i src (rekursivt)
file(GLOB_RECURSE ALL_HEADERS RELATIVE ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/src/*)

set(INCLUDE_DIRS)
foreach(dir ${ALL_HEADERS})
    if(IS_DIRECTORY ${PROJECT_SOURCE_DIR}/src/${dir})
        list(APPEND INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/src/${dir})
    endif()
endforeach()

list(REMOVE_DUPLICATES INCLUDE_DIRS)

target_include_directories(main PRIVATE ${INCLUDE_DIRS})
