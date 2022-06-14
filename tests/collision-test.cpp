#include "Catch2.hpp"

#include "../src/include/Player.hpp"
#include <vector>

bool testCollision(std::vector<float> playerCenter, float radius,
                   std::vector<float> enemy)
{
  // Arrange
  Player player(playerCenter, radius);

  // Act
  return player.collide(enemy);
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
        bool collided = testCollision(playerCenter, 1.1, enemy);
        // Assert
        REQUIRE(collided == false);
      }

      SECTION("Just collision.")
      {
        bool collided = testCollision(playerCenter, 5, enemy);
        // Assert
        REQUIRE(collided == true);
      }

      SECTION("Collision inside.")
      {
        bool collided = testCollision(playerCenter, 7.3, enemy);
        // Assert
        REQUIRE(collided == true);
      }
    }

    SECTION("Enemy second quadrant.")
    {
      // Set enemy position
      std::vector<float> enemy = {-3.f, 4.f};

      SECTION("No collision.")
      {
        bool collided = testCollision(playerCenter, 1.1, enemy);
        // Assert
        REQUIRE(collided == false);
      }

      SECTION("Just collision.")
      {
        bool collided = testCollision(playerCenter, 5, enemy);
        // Assert
        REQUIRE(collided == true);
      }

      SECTION("Collision inside.")
      {
        bool collided = testCollision(playerCenter, 7.3, enemy);
        // Assert
        REQUIRE(collided == true);
      }
    }

    SECTION("Enemy third quadrant.")
    {
      // Set enemy position
      std::vector<float> enemy = {-3.f, -4.f};

      SECTION("No collision.")
      {
        bool collided = testCollision(playerCenter, 1.1, enemy);
        // Assert
        REQUIRE(collided == false);
      }

      SECTION("Just collision.")
      {
        bool collided = testCollision(playerCenter, 5, enemy);
        // Assert
        REQUIRE(collided == true);
      }

      SECTION("Collision inside.")
      {
        bool collided = testCollision(playerCenter, 7.3, enemy);
        // Assert
        REQUIRE(collided == true);
      }
    }

    SECTION("Enemy fourth quadrant.")
    {
      // Set enemy position
      std::vector<float> enemy = {3.f, -4.f};

      SECTION("No collision.")
      {
        bool collided = testCollision(playerCenter, 1.1, enemy);
        // Assert
        REQUIRE(collided == false);
      }

      SECTION("Just collision.")
      {
        bool collided = testCollision(playerCenter, 5, enemy);
        // Assert
        REQUIRE(collided == true);
      }

      SECTION("Collision inside.")
      {
        bool collided = testCollision(playerCenter, 7.3, enemy);
        // Assert
        REQUIRE(collided == true);
      }
    }

  }

}
