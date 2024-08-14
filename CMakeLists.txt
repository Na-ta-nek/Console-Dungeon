cmake_minimum_required(VERSION 3.14)
project(Console-Dungeon)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    DungeonGame.cpp
    Player.cpp)

find_package(GTest REQUIRED)

add_executable(
    ${PROJECT_NAME}
    ${SOURCES}
    main.cpp)

enable_testing()

add_executable(
    ${PROJECT_NAME}-ut
    ${SOURCES}
    tests.cpp)

target_link_libraries(${PROJECT_NAME}-ut GTest::GTest GTest::Main)
target_link_libraries(${PROJECT_NAME}-ut GTest::GTest GTest::gmock_main)

gtest_discover_tests(${PROJECT_NAME}-ut)