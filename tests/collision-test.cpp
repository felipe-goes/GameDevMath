#include "Catch2.hpp"

#include "../src/include/Player.hpp"
#include <vector>

Player testCollision(std::vector<float> playerCenter, float radius,
                   std::vector<float> enemy)
{
  // Arrange
  Player player(playerCenter, radius);

  // Act
  player.collide(enemy);

  return player;
}

TEST_CASE("Collision between Player and Enemy.")
{
  // This test case is enough for studying purposes xD
  SECTION("Player center.")
  {
    // Set player position
    std::vector<float> playerCenter = {0.f, 0.f};

    SECTION("Enemy first quadrant.")
    {
      // Set enemy position
      std::vector<float> enemy = {3.f, 4.f};

      SECTION("No collision.")
      {
        Player player = testCollision(playerCenter, 1.1, enemy);
        // Assert
        REQUIRE(player.checkCollision() == false);
      }

      SECTION("Just collision.")
      {
        Player player = testCollision(playerCenter, 5, enemy);
        // Assert
        REQUIRE(player.checkCollision() == true);
      }

      SECTION("Collision inside.")
      {
        Player player = testCollision(playerCenter, 7.3, enemy);
        // Assert
        REQUIRE(player.checkCollision() == true);
      }
    }

    SECTION("Enemy second quadrant.")
    {
      // Set enemy position
      std::vector<float> enemy = {-3.f, 4.f};

      SECTION("No collision.")
      {
        Player player = testCollision(playerCenter, 1.1, enemy);
        // Assert
        REQUIRE(player.checkCollision() == false);
      }

      SECTION("Just collision.")
      {
        Player player = testCollision(playerCenter, 5, enemy);
        // Assert
        REQUIRE(player.checkCollision() == true);
      }

      SECTION("Collision inside.")
      {
        Player player = testCollision(playerCenter, 7.3, enemy);
        // Assert
        REQUIRE(player.checkCollision() == true);
      }
    }

    SECTION("Enemy third quadrant.")
    {
      // Set enemy position
      std::vector<float> enemy = {-3.f, -4.f};

      SECTION("No collision.")
      {
        Player player = testCollision(playerCenter, 1.1, enemy);
        // Assert
        REQUIRE(player.checkCollision() == false);
      }

      SECTION("Just collision.")
      {
        Player player = testCollision(playerCenter, 5, enemy);
        // Assert
        REQUIRE(player.checkCollision() == true);
      }

      SECTION("Collision inside.")
      {
        Player player = testCollision(playerCenter, 7.3, enemy);
        // Assert
        REQUIRE(player.checkCollision() == true);
      }
    }

    SECTION("Enemy fourth quadrant.")
    {
      // Set enemy position
      std::vector<float> enemy = {3.f, -4.f};

      SECTION("No collision.")
      {
        Player player = testCollision(playerCenter, 1.1, enemy);
        // Assert
        REQUIRE(player.checkCollision() == false);
      }

      SECTION("Just collision.")
      {
        Player player = testCollision(playerCenter, 5, enemy);
        // Assert
        REQUIRE(player.checkCollision() == true);
      }

      SECTION("Collision inside.")
      {
        Player player = testCollision(playerCenter, 7.3, enemy);
        // Assert
        REQUIRE(player.checkCollision() == true);
      }
    }

  }

}
