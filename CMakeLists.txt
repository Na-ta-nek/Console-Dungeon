cmake_minimum_required(VERSION 3.14)
project(Console-Dungeon)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    DungeonGame.cpp)

add_executable(
    ${PROJECT_NAME}
    ${SOURCES}
    main.cpp)