cmake_minimum_required(VERSION 3.14)
project(Console-Dungeon)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    Action.cpp
    DungeonGame.cpp
    GameConfig.cpp
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
    Creatures/Zombie.cpp
    Items/Bandage.cpp
    Items/Chestplate.cpp
    Items/Dagger.cpp
    Items/FirstAidKit.cpp
    Items/Gear.cpp
    Items/Helmet.cpp
    Items/Item.cpp
    Items/Medicine.cpp
    Items/Pill.cpp
    Items/Shield.cpp
    Items/Spear.cpp
    Items/Sword.cpp
    Items/Weapon.cpp)

add_executable(${PROJECT_NAME}
               ${SOURCES}
               main.cpp)

target_include_directories(${PROJECT_NAME}
                           PRIVATE
                           ${PROJECT_SOURCE_DIR}/Creatures)
target_include_directories(${PROJECT_NAME}
                           PRIVATE
                           ${PROJECT_SOURCE_DIR}/Items)
    
find_package(GTest REQUIRED)
enable_testing()

add_executable(${PROJECT_NAME}-ut
               ${SOURCES}
               tests.cpp)

target_link_libraries(${PROJECT_NAME}-ut
                      GTest::GTest
                      GTest::gmock_main)

gtest_discover_tests(${PROJECT_NAME}-ut)