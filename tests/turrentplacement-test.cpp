#include "Catch2.hpp"

#include "../src/include/Algebra.hpp"
#include <vector>

TEST_CASE("Turrent placement test.")
{
  SECTION("Ray on z=0 and negative Y.")
  {
    SECTION("Ray on positive X.")
    {
      // Arrange
      std::vector<float> normal3d(3);
      std::vector<float> ray3d(3);

      normal3d = {0.f, 1.f, 0.f};
      ray3d = {1.f, -1.f, 0.f};

      std::vector<std::vector<float>> turrentPlaced(3, std::vector<float>(3));
      turrentPlaced = Algebra::turrentPlacement(normal3d, ray3d);

      std::vector<std::vector<float>> expectedVector(3, std::vector<float>(3));
      expectedVector = {{1.f, 0.f, 0.f}, {normal3d}, {0.f, 0.f, 1.f}};

      // Assert
      REQUIRE(turrentPlaced == expectedVector);
    }

    SECTION("Ray on negative X.")
    {
      // Arrange
      std::vector<float> normal3d(3);
      std::vector<float> ray3d(3);

      normal3d = {0.f, 1.f, 0.f};
      ray3d = {-1.f, -1.f, 0.f};

      std::vector<std::vector<float>> turrentPlaced(3, std::vector<float>(3));
      turrentPlaced = Algebra::turrentPlacement(normal3d, ray3d);

      std::vector<std::vector<float>> expectedVector(3, std::vector<float>(3));
      expectedVector = {{-1.f, 0.f, 0.f}, {normal3d}, {0.f, 0.f, 1.f}};

      // Assert
      REQUIRE(turrentPlaced == expectedVector);
    }
  }

  SECTION("Ray on z!=0 and negative Y.")
  {
    SECTION("Ray on positive X.")
    {
      // Arrange
      std::vector<float> normal3d(3);
      std::vector<float> ray3d(3);

      normal3d = {0.f, 1.f, 0.f};
      ray3d = {1.f, -1.f, 1.f};

      std::vector<std::vector<float>> turrentPlaced(3, std::vector<float>(3));
      turrentPlaced = Algebra::turrentPlacement(normal3d, ray3d);

      std::vector<std::vector<float>> expectedVector(3, std::vector<float>(3));
      expectedVector = {{0.707106781187f, 0.f, 0.707106781187f},
                        {normal3d},
                        {-0.707106781187f, 0.f, 0.707106781187f}};

      // Assert
      REQUIRE(turrentPlaced == expectedVector);
    }

    SECTION("Ray on negative X.")
    {
      // Arrange
      std::vector<float> normal3d(3);
      std::vector<float> ray3d(3);

      normal3d = {0.f, 1.f, 0.f};
      ray3d = {-1.f, -1.f, -1.f};

      std::vector<std::vector<float>> turrentPlaced(3, std::vector<float>(3));
      turrentPlaced = Algebra::turrentPlacement(normal3d, ray3d);

      std::vector<std::vector<float>> expectedVector(3, std::vector<float>(3));
      expectedVector = {{-0.707106781187f, 0.f, -0.707106781187f},
                        {normal3d},
                        {-0.707106781187f, 0.f, 0.707106781187f}};

      // Assert
      REQUIRE(turrentPlaced == expectedVector);
    }
  }
}
