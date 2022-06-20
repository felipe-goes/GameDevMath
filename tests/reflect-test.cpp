#include "Catch2.hpp"

#include "../src/include/Player.hpp"
#include "../src/include/Algebra.hpp"
#include <vector>

TEST_CASE("Test reflect function.")
{
  SECTION("Origin vectors.")
  {
    // Arrange
    std::vector<float> object = {-1.f, -1.f};
    std::vector<float> surface = {0.f, 1.f};

    std::vector<float> reflectedObject = Algebra::reflect(object, surface);

    // Assert
    REQUIRE(reflectedObject[0] == -1.f);
    REQUIRE(reflectedObject[1] == 1.f);
  }

  SECTION("Origin vectors with offset.")
  {
    // Arrange
    std::vector<float> object = {-2.f, -2.f};
    std::vector<float> surface = {0.f, 1.f};

    std::vector<float> reflectedObject = Algebra::reflect(object, surface);

    // Assert
    REQUIRE(reflectedObject[0] == -2.f);
    REQUIRE(reflectedObject[1] == 2.f);
  }

  SECTION("Origin vectors with offset and surface rotated.")
  {
    // Arrange
    std::vector<float> object = {0.f, -1.f};
    std::vector<float> surface = {1.f, 1.f};

    std::vector<float> reflectedObject = Algebra::reflect(object, surface);

    // Assert
    REQUIRE(reflectedObject[0] == 2.f);
    REQUIRE(reflectedObject[1] == 1.f);
  }

}
