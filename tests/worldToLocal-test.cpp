#include "Catch2.hpp"

#include "../src/include/Algebra.hpp"
#include "../src/include/Player.hpp"
#include <vector>

TEST_CASE("Check world to local space transformation.")
{
  SECTION("Local and world bases are the same.")
  {
    // Arrange
    Player player({0.f, 0.f}, 1, {1.f, 0.f}, {0.f, 1.f});
    std::vector<float> enemy = {1.f, 1.f};

    std::vector<float> transformed = Algebra::worldToLocal(player, enemy);

    // Assert
    REQUIRE(transformed[0] == enemy[0]);
    REQUIRE(transformed[1] == enemy[1]);
  }

  SECTION("Local base offsetted and rotated 45 degrees.")
  {
    // Arrange
    Player player({2.f, 3.f}, 1, {1.4142/2, 1.4142/2}, {-1.4142/2, 1.4142/2});
    std::vector<float> enemy = {4.f, 4.f};

    std::vector<float> transformed = Algebra::worldToLocal(player, enemy);

    // Needed a tolarance due to float point approximation error
    float error = 0.05;
    bool assertX =
      (transformed[0] >= 2.8284f * (1-error)) || (transformed[0] <= 2.8284f * (1+error));
    bool assertY =
      (transformed[1] >= 0 * (1-error)) || (transformed[1] <= 0 * (1+error));

    // Assert
    REQUIRE(assertX);
    REQUIRE(assertY);
  }
}

