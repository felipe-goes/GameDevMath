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

TEST_CASE("Turrent box test.")
{
  SECTION("Local box given by the question.")
  {
    // Arrange
    std::vector<std::vector<float>> transformationMatrix(4,
                                                         std::vector<float>(4));
    transformationMatrix = {{-0.707106781187f, 0, -0.707106781187f, 0},
                            {0, 1, 0, 0},
                            {-0.707106781187f, 0, 0.707106781187f, 0},
                            {0, 0, 0, 1}};

    std::vector<std::vector<float>> box(8, std::vector<float>(4));
    box = {
      {1, 0, 1, 1}, {-1, 0, 1, 1}, {-1, 0, -1, 1}, {1, 0, -1, 1},
      {1, 2, 1, 1}, {-1, 2, 1, 1}, {-1, 2, -1, 1}, {1, 2, -1, 1},
    };

    std::vector<std::vector<float>> boxTransformed(8, std::vector<float>(3));
    boxTransformed[0] =
      Algebra::localToWorldMatrix(transformationMatrix, box[0]);
    boxTransformed[1] =
      Algebra::localToWorldMatrix(transformationMatrix, box[1]);
    boxTransformed[2] =
      Algebra::localToWorldMatrix(transformationMatrix, box[2]);
    boxTransformed[3] =
      Algebra::localToWorldMatrix(transformationMatrix, box[3]);
    boxTransformed[4] =
      Algebra::localToWorldMatrix(transformationMatrix, box[4]);
    boxTransformed[5] =
      Algebra::localToWorldMatrix(transformationMatrix, box[5]);
    boxTransformed[6] =
      Algebra::localToWorldMatrix(transformationMatrix, box[6]);
    boxTransformed[7] =
      Algebra::localToWorldMatrix(transformationMatrix, box[7]);

    std::vector<std::vector<float>> expected(8, std::vector<float>(3));
    expected[0] = {-1.41421356237f, 0.f, 0.f, 1.f};
    expected[1] = {0.f, 0.f, 1.41421356237f, 1.f};
    expected[2] = {1.41421356237f, 0.f, 0.f, 1.f};
    expected[3] = {0.f, 0.f, -1.41421356237f, 1.f};
    expected[4] = {-1.41421356237f, 2.f, 0.f, 1.f};
    expected[5] = {0.f, 2.f, 1.41421356237f, 1.f};
    expected[6] = {1.41421356237f, 2.f, 0.f, 1.f};
    expected[7] = {0.f, 2.f, -1.41421356237f, 1.f};

    // Assert
    REQUIRE(boxTransformed == expected);
  }
}

TEST_CASE("Guns placement test.")
{
  SECTION("Using vectors from last example.")
  {
    // Arrange
    std::vector<std::vector<float>> transformationMatrix(4,
                                                         std::vector<float>(4));
    transformationMatrix = {{-0.707106781187f, 0, -0.707106781187f, 0},
                            {0, 1, 0, 0},
                            {-0.707106781187f, 0, 0.707106781187f, 0},
                            {0, 0, 0, 1}};

    std::vector<std::vector<float>> box(8, std::vector<float>(4));
    box = {
      {1, 0, 1, 1}, {-1, 0, 1, 1}, {-1, 0, -1, 1}, {1, 0, -1, 1},
      {1, 2, 1, 1}, {-1, 2, 1, 1}, {-1, 2, -1, 1}, {1, 2, -1, 1},
    };

    std::vector<std::vector<float>> guns(2, std::vector<float>(4));

    guns = Algebra::gunPosition(0.2f, 0.3f, 0.2f, transformationMatrix, box);

    std::vector<float> leftGun(4);
    std::vector<float> rightGun(4);

    leftGun= {-1.01823376491f, 1.59999990463f, 1.81019335984f, 1.f};
    rightGun = {-1.81019335984f, 1.59999990463f, 1.01823376491f, 1.f};

    std::vector<std::vector<float>> expected(2, std::vector<float>(4));
    expected = {leftGun, rightGun};

    // Assert
    REQUIRE(guns == expected);
  }
}
