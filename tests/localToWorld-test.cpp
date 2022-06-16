#include "Catch2.hpp"

#include "../src/include/Algebra.hpp"
#include "../src/include/Player.hpp"
#include <vector>

TEST_CASE("Check local to world transformation.")
{
  SECTION("Local and world bases are the same.")
  {
    // Arrange
    Player player({0.f, 0.f}, 1, {1.f, 0.f}, {0.f, 1.f});
    std::vector<float> enemy = {1.f, 1.f};

    std::vector<float> transformed = Algebra::localToWorld(player, enemy);

    // Assert
    REQUIRE(transformed[0] == enemy[0]);
    REQUIRE(transformed[1] == enemy[1]);
  }

  SECTION("Local base offsetted and rotated 45 degrees.")
  {
    // Arrange
    Player player({2.f, 3.f}, 1, {1.4142f, 1.4142f}, {-1.4142f, 1.4142f});
    std::vector<float> enemy = {2.f, 1.f};

    std::vector<float> transformed = Algebra::localToWorld(player, enemy);

    // Needed a tolarance due to float point approximation error
    float error = 0.01;
    bool assertX =
      (transformed[0] >= 4.8284f * (1-error)) || (transformed[0] <= 4.8284f * (1+error));
    bool assertY =
      (transformed[1] >= 4.4142f * (1-error)) || (transformed[1] <= 4.4142f * (1+error));

    // Assert
    REQUIRE(assertX);
    REQUIRE(assertY);
  }
}
