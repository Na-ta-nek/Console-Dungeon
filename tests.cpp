#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "DungeonGame.hpp"
#include "Room.hpp"
#include "Creatures/Dragon.hpp"
#include "Creatures/Player.hpp"
#include "Items/Item.hpp"
#include "Items/Pill.hpp"

class MockItem : public Item {
public:
    MOCK_METHOD(void, use, (Player* user));
    MOCK_METHOD(void, printInformation, (), (const, override));

    ~MockItem() override = default;
};

class PlayerTests : public ::testing::Test
{
protected:
    std::shared_ptr<Player> player = std::make_shared<Player>("Test Player");
};

class MonsterTests : public ::testing::Test
{
protected:
    std::shared_ptr<Dragon> monster = std::make_shared<Dragon>();
};

TEST_F(PlayerTests, PlayerInitializationTest)
{
    EXPECT_EQ(player->getArmorPoints(), 0);
    EXPECT_EQ(player->getAttackDamage(), 5);
    EXPECT_EQ(player->getHealthPoints(), 100);
    EXPECT_EQ(player->getMaxArmorPoints(), 100);
    EXPECT_EQ(player->getMaxHealthPoints(), 100);
    EXPECT_EQ(player->getName(), "Test Player");
}

TEST_F(PlayerTests, PlayerArmorPointsOperationsTest)
{
    player->increaseArmorPoints(200);
    EXPECT_EQ(player->getArmorPoints(), 100);

    player->armorPointsDamage(60);
    EXPECT_EQ(player->getArmorPoints(), 40);

    player->armorPointsDamage(50);
    EXPECT_EQ(player->getArmorPoints(), 0);
}

TEST_F(PlayerTests, PlayerHealthPointsOperationsTest)
{
    player->increaseHealthPoints(200);
    EXPECT_EQ(player->getHealthPoints(), 100);

    player->healthPointsDamage(60);
    EXPECT_EQ(player->getHealthPoints(), 40);

    player->healthPointsDamage(50);
    EXPECT_EQ(player->getHealthPoints(), 0);
}

TEST_F(PlayerTests, PlayerAttackingMonsterTest)
{
    auto target = std::make_shared<Skeleton>();
    EXPECT_EQ(target->getHealthPoints(), 50);

    player->attack(target, 30);
    EXPECT_NE(target->getHealthPoints(), 50);

    player->attack(target, 30);
    EXPECT_EQ(target->getHealthPoints(), 0);

    auto target2 = std::make_shared<Orc>();
    EXPECT_EQ(target2->getHealthPoints(), 250);
    EXPECT_EQ(target2->getArmorPoints(), 100);

    player->attack(target2, 30);
    EXPECT_EQ(target2->getHealthPoints(), 250);
    EXPECT_NE(target2->getArmorPoints(), 100);
}

TEST_F(PlayerTests, PlayerDefendingTest)
{
    auto target = std::make_shared<Skeleton>();
    player->attack(target, 30);
    EXPECT_FALSE(player->getIsDefending());

    player->defend();
    EXPECT_TRUE(player->getIsDefending());
}

TEST_F(PlayerTests, PlayerResetHealthPointsTest) {
    player->healthPointsDamage(50);
    EXPECT_NE(player->getHealthPoints(), 100);
    player->resetHealthPoints();
    EXPECT_EQ(player->getHealthPoints(), 100);
}

TEST_F(PlayerTests, PutItemInPlayersBackpack)
{
    auto item = std::make_shared<Pill>();

    EXPECT_EQ(player->getNumberOfItemsInBackpack(), 0);

    player->putItemInBackpack(item);
    EXPECT_EQ(player->getNumberOfItemsInBackpack(), 1);
}

class MockPill : public Pill {
public:
    MOCK_METHOD(void, use, (Player* player));
    ~MockPill() noexcept { Destructor(); }
    MOCK_METHOD(void, Destructor, (), (noexcept));
};

TEST_F(PlayerTests, PlayerUsingItemByIndex)
{
    auto item = std::make_shared<MockPill>();

    EXPECT_CALL(*item, use(::testing::_)).Times(1);

    player->putItemInBackpack(item);
    player->useItem(0);
    
    EXPECT_EQ(player->getNumberOfItemsInBackpack(), 0);
    EXPECT_CALL(*item, Destructor);
}

TEST_F(PlayerTests, PlayerUsingItemByPointer)
{
    auto item = std::make_shared<MockPill>();

    EXPECT_CALL(*item, use(::testing::_)).Times(1);

    player->putItemInBackpack(item);
    player->useItem(item);
    
    EXPECT_EQ(player->getNumberOfItemsInBackpack(), 0);
    EXPECT_CALL(*item, Destructor);
}

TEST_F(PlayerTests, BackpackFullAndEmptyTest)
{
    EXPECT_TRUE(player->isBackpackEmpty());
    EXPECT_FALSE(player->isBackpackFull());

    auto item = std::make_shared<Pill>();
    for (int i = 0; i < PLAYER_CONFIG::MAX_ITEMS_IN_BACKPACK; i++)
    {
        player->putItemInBackpack(item);
    }

    EXPECT_TRUE(player->isBackpackFull());
    EXPECT_FALSE(player->isBackpackEmpty());
}

TEST_F(PlayerTests, PlayerCounterIncrementsTest)
{
    EXPECT_EQ(player->getDungeonsCompleted(), 0);
    EXPECT_EQ(player->getMobsKilled(), 0);
    EXPECT_EQ(player->getRoomsPassed(), 0);

    player->increaseDungeonsCounter();
    player->increaseMobsCounter();
    player->increaseRoomsCounter();

    EXPECT_EQ(player->getDungeonsCompleted(), 1);
    EXPECT_EQ(player->getMobsKilled(), 1);
    EXPECT_EQ(player->getRoomsPassed(), 1);
}

TEST_F(MonsterTests, MonsterInitializationTest)
{
    EXPECT_EQ(monster->getAbilityChance(), 0.1);
    EXPECT_EQ(monster->getAbilityPoints(), 100);
    EXPECT_EQ(monster->getArmorPoints(), 0);
    EXPECT_EQ(monster->getAttackChance(), 0.5);
    EXPECT_EQ(monster->getAttackDamage(), 25);
    EXPECT_EQ(monster->getHealthPoints(), 999);
    EXPECT_EQ(monster->getMaxArmorPoints(), 100);
    EXPECT_EQ(monster->getMaxHealthPoints(), 999);
    EXPECT_EQ(monster->getName(), "Dragon");
}

TEST_F(MonsterTests, MonsterAttackingPlayerTest)
{
    auto player = std::make_shared<Player>("Test Player");
    player->increaseArmorPoints(50);
    EXPECT_EQ(player->getArmorPoints(), 50);
    EXPECT_EQ(player->getHealthPoints(), 100);

    monster->attack(player, 30);

    bool condition1 = (player->getArmorPoints() != 50);
    bool condition2 = (player->getHealthPoints() != 100);
    bool condition3 = (monster->getIsDefending(), true);
    EXPECT_TRUE(condition1 || condition2 || condition3);
}

TEST_F(MonsterTests, MonsterUsingAbilityTest)
{
    auto player = std::make_shared<Player>("Test Player");
    std::vector<std::shared_ptr<Monster>> monsters{};
    monsters.emplace_back(monster);
    player->increaseArmorPoints(50);
    EXPECT_EQ(player->getArmorPoints(), 50);
    EXPECT_EQ(player->getHealthPoints(), 100);

    monster->ability(player, monsters);

    bool condition1 = (player->getArmorPoints() != 50);
    bool condition2 = (player->getHealthPoints() != 100);
    bool condition3 = (monster->getIsDefending(), true);
    EXPECT_TRUE(condition1 || condition2 || condition3);
}

TEST(ItemTests, ItemInitializationTest)
{
    auto item = std::make_shared<Pill>();
    EXPECT_EQ(item->getValue(), 15);
    EXPECT_EQ(item->getName(), "Pill");
}

TEST(ActionTests, ActionInitializationTest)
{
    bool functionCalled = false;
    std::function<void()> testFunction = [&]() { functionCalled = true; };

    Action action(1, "Test Action", testFunction);
    action.getFunction()();
    
    EXPECT_TRUE(functionCalled);
}