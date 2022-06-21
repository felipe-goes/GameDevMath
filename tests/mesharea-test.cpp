#include "Catch2.hpp"

#include "../src/include/Algebra.hpp"
// #include "../src/include/UnityMesh.hpp"
// #include <vector>

TEST_CASE("Test calculation of mesh areas.")
{
  SECTION("Unity quad example.")
  {
    // Arrange
    std::vector<std::vector<float>> vector3d(8, std::vector<float>(3));
    vector3d[0] = {0.f, 0.f, 1.f};
    vector3d[1] = {1.f, 0.f, 1.f};
    vector3d[2] = {0.f, 1.f, 1.f};
    vector3d[3] = {1.f, 1.f, 1.f};

    std::vector<int> trianglesIndices;
    trianglesIndices = {0, 1, 2, 0, 1, 3};

    UnityMesh mesh(vector3d, trianglesIndices);

    float totalArea = Algebra::meshArea(mesh);

    // Assert
    REQUIRE(totalArea == 1.f);
  }

  SECTION("Unity cube example.")
  {
    // Arrange
    std::vector<std::vector<float>> vector3d(8, std::vector<float>(3));
    vector3d[0] = {0.f, 0.f, 1.f};
    vector3d[1] = {1.f, 0.f, 1.f};
    vector3d[2] = {0.f, 1.f, 1.f};
    vector3d[3] = {1.f, 1.f, 1.f};

    vector3d[4] = {0.f, 0.f, 0.f};
    vector3d[5] = {1.f, 0.f, 0.f};
    vector3d[6] = {0.f, 1.f, 0.f};
    vector3d[7] = {1.f, 1.f, 0.f};

    std::vector<int> trianglesIndices;
    trianglesIndices = {
      0, 1, 3, 0, 1, 2,

      0, 1, 4, 0, 1, 5,

      0, 2, 4, 0, 4, 6,

      1, 3, 5, 1, 5, 7,

      2, 3, 6, 2, 3, 7,

      4, 5, 6, 4, 5, 7,
    };

    UnityMesh mesh(vector3d, trianglesIndices);

    float totalArea = Algebra::meshArea(mesh);

    // Assert
    REQUIRE(totalArea == 6.f);
  }
}
