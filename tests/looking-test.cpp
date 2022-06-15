#include "Catch2.hpp"

#include "../src/include/Player.hpp"
#include <vector>

Player setup(std::vector<float> playerCenter, float radius, std::vector<float> enemy, float threshold)
{
  Player player(playerCenter, radius);
  player.updateLooking(enemy, threshold);

  return player;
}

TEST_CASE("Check if Player is looking at Enemy.")
{
  std::vector<float> enemy = {12.f, 2.f};
  float threshold = 0.8;
  float radius = 1.f;

  // These test cases are enough for studying purposes xD
  SECTION("Player first quadrant.")
  {
    // Arrange
    std::vector<float> playerCenter = {0.5, 0.5};
    Player player = setup(playerCenter, radius, enemy, threshold);

    // Assert
    REQUIRE(player.isLooking() == true);
  }

  SECTION("Player first quadrant.")
  {
    // Arrange
    std::vector<float> playerCenter = {0.1, 5.f};
    Player player = setup(playerCenter, radius, enemy, threshold);

    // Assert
    REQUIRE(player.isLooking() == false);
  }

  SECTION("Player second quadrant.")
  {
    // Arrange
    std::vector<float> playerCenter = {-0.5, 0.5};
    Player player = setup(playerCenter, radius, enemy, threshold);

    // Assert
    REQUIRE(player.isLooking() == false);
  }

  SECTION("Player third quadrant.")
  {
    // Arrange
    std::vector<float> playerCenter = {-0.5, -0.5};
    Player player = setup(playerCenter, radius, enemy, threshold);

    // Assert
    REQUIRE(player.isLooking() == false);
  }

  SECTION("Player fourth quadrant.")
  {
    // Arrange
    std::vector<float> playerCenter = {0.5, -0.5};
    Player player = setup(playerCenter, radius, enemy, threshold);

    // Assert
    REQUIRE(player.isLooking() == false);
  }

}

