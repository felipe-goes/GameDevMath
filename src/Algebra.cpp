#include "Algebra.hpp"
#include <vector>

Algebra::Algebra() {}
Algebra::~Algebra() {}

const float Algebra::distance(const std::vector<float> player,
                              const std::vector<float> enemy)
{
  float distance = sqrt((enemy[0] - player[0]) * (enemy[0] - player[0]) +
                        (enemy[1] - player[1]) * (enemy[1] - player[1]));

  return distance;
}

const float Algebra::length(std::vector<float> vector)
{
  return sqrt(vector[0] * vector[0] + vector[1] * vector[1]);
}

const std::vector<float> Algebra::normalize(std::vector<float> vector)
{
  float length = Algebra::length(vector);

  if (length != 0)
  {
    std::vector<float> normalizedVector = {vector[0] / length,
                                           vector[1] / length};
    return normalizedVector;
  }
  else
  {
    return {0.f, 0.f};
  }
}

const float Algebra::dotProduct(std::vector<float> vectorA,
                                std::vector<float> vectorB)
{
  return (vectorA[0] * vectorB[0] + vectorA[1] * vectorB[1]);
}
