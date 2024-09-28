#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "DungeonGame.hpp"
#include "Creatures/Creature.hpp"
#include "Creatures/Player.hpp"
#include "Room.hpp"

TEST(PlayerClassTests, CreateDefaultPlayer) {
  Player p1{};

  EXPECT_EQ(p1.getName(), "Player");
  EXPECT_EQ(p1.getHealthPoints(), 100);
  EXPECT_EQ(p1.getArmorPoints(), 0);
}

TEST(PlayerClassTests, CreatePlayerWithName) {
  Player p1{"Player1"};

  EXPECT_EQ(p1.getName(), "Player1");
  EXPECT_EQ(p1.getHealthPoints(), 100);
  EXPECT_EQ(p1.getArmorPoints(), 0);
}