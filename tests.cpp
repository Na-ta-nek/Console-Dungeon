#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "DungeonGame.hpp"
#include "Player.hpp"

class MockPlayer : public Player {
public:
    MOCK_METHOD(void, Die, ());
    virtual ~MockPlayer() { Die(); }
};

TEST(PlayerClassTests, CreateDefaultPlayer) {
  MockPlayer p1{};

  EXPECT_EQ(p1.getName(), "Player");
  EXPECT_EQ(p1.getHealthPoints(), 100);
  EXPECT_EQ(p1.getArmorPoints(), 0);
  EXPECT_CALL(p1, Die());
}

TEST(PlayerClassTests, CreatePlayerWithName) {
  Player p1{"Player1"};

  EXPECT_EQ(p1.getName(), "Player1");
  EXPECT_EQ(p1.getHealthPoints(), 100);
  EXPECT_EQ(p1.getArmorPoints(), 0);
}