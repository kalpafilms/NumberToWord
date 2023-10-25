cmake_minimum_required(VERSION 3.13)

set(PROJECT_NAME NumberToWord)
set(SOURCE_FILES main.cpp)

set(CMAKE_CXX_STANDARD 17)

project(
    ${PROJECT_NAME}
    VERSION 0.1
    DESCRIPTION "Transform a number to a word"
    LANGUAGES CXX
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Werror)
