cmake_minimum_required(VERSION 3.14)
project(Console-Dungeon)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include Creatures)

set(SOURCES
    Action.cpp
    DungeonGame.cpp
    GameConfig.cpp
    Item.cpp
    Room.cpp
    Creatures/Creature.cpp
    Creatures/DeathKnight.cpp
    Creatures/Dragon.cpp
    Creatures/Golem.cpp
    Creatures/Monster.cpp
    Creatures/Orc.cpp
    Creatures/Player.cpp
    Creatures/Shaman.cpp
    Creatures/Skeleton.cpp
    Creatures/Vampire.cpp
    Creatures/Wizard.cpp
    Creatures/Zombie.cpp)

add_executable(
    ${PROJECT_NAME}
    ${SOURCES}
    main.cpp)

find_package(GTest REQUIRED)
enable_testing()

add_executable(
    ${PROJECT_NAME}-ut
    ${SOURCES}
    tests.cpp)

target_link_libraries(${PROJECT_NAME}-ut
                      GTest::GTest
                      GTest::gmock_main)

gtest_discover_tests(${PROJECT_NAME}-ut)