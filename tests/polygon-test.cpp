#include "Catch2.hpp"

#include "../src/include/Algebra.hpp"
#include <cmath>
#include <vector>

TEST_CASE("Polygon creation test. Density = 1.")
{
  const float pi = 3.14159265359f;
  const unsigned int density = 1;
  float alpha = 0.f;

  SECTION("Invalid.")
  {
    unsigned int sides = 0;

    std::vector<std::vector<float>> sideVectors(sides, std::vector<float>(2));
    sideVectors = Algebra::drawPolygon(sides, density);

    std::vector<std::vector<float>> expected = {{}};

    REQUIRE(sideVectors == expected);
  }

  SECTION("Triangle.")
  {
    unsigned int sides = 3;
    const float pace = 2 * pi / sides;

    std::vector<std::vector<float>> sideVectors(sides, std::vector<float>(2));
    sideVectors = Algebra::drawPolygon(sides, density);


    std::vector<std::vector<float>> vertices(sides, std::vector<float>(2));
    vertices[0] = {std::cos(alpha+0*pace), std::sin(alpha+0*pace)};
    vertices[1] = {std::cos(alpha+1*pace), std::sin(alpha+1*pace)};
    vertices[2] = {std::cos(alpha+2*pace), std::sin(alpha+2*pace)};

    std::vector<std::vector<float>> expected(sides, std::vector<float>(2));
    expected[0] = Algebra::minus(vertices[1], vertices[0]);
    expected[1] = Algebra::minus(vertices[2], vertices[1]);
    expected[2] = Algebra::minus(vertices[0], vertices[2]);

    REQUIRE(sideVectors == expected);
  }

  SECTION("Hexagon.")
  {
    unsigned int sides = 6;
    const float pace = 2 * pi / sides;

    std::vector<std::vector<float>> sideVectors(sides, std::vector<float>(2));
    sideVectors = Algebra::drawPolygon(sides, density);

    std::vector<std::vector<float>> vertices(sides, std::vector<float>(2));
    vertices[0] = {std::cos(alpha+0*pace), std::sin(alpha+0*pace)};
    vertices[1] = {std::cos(alpha+1*pace), std::sin(alpha+1*pace)};
    vertices[2] = {std::cos(alpha+2*pace), std::sin(alpha+2*pace)};
    vertices[3] = {std::cos(alpha+3*pace), std::sin(alpha+3*pace)};
    vertices[4] = {std::cos(alpha+4*pace), std::sin(alpha+4*pace)};
    vertices[5] = {std::cos(alpha+5*pace), std::sin(alpha+5*pace)};

    std::vector<std::vector<float>> expected(sides, std::vector<float>(2));
    expected[0] = Algebra::minus(vertices[1], vertices[0]);
    expected[1] = Algebra::minus(vertices[2], vertices[1]);
    expected[2] = Algebra::minus(vertices[3], vertices[2]);
    expected[3] = Algebra::minus(vertices[4], vertices[3]);
    expected[4] = Algebra::minus(vertices[5], vertices[4]);
    expected[5] = Algebra::minus(vertices[0], vertices[5]);

    REQUIRE(sideVectors == expected);
  }
}
