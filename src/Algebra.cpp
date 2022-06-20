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

const std::vector<float> Algebra::localToWorld(Player referenceVector,
                                               std::vector<float> localVector)
{
  std::vector<float> scaledBasisSum = {
    referenceVector.getBasisX()[0] * localVector[0],
    referenceVector.getBasisY()[1] * localVector[1]};

  return {scaledBasisSum[0] + referenceVector.getCenter()[0],
          scaledBasisSum[1] + referenceVector.getCenter()[1]};
}

const std::vector<float> Algebra::minus(std::vector<float> vectorA,
                                        std::vector<float> vectorB)
{
  return {vectorA[0] - vectorB[0], vectorA[1] - vectorB[1]};
}

const std::vector<float> Algebra::worldToLocal(Player referenceVector,
                                               std::vector<float> worldVector)
{
  std::vector<float> subtraction =
    Algebra::minus(worldVector, referenceVector.getCenter());

  return {Algebra::dotProduct(subtraction, referenceVector.getBasisX()),
          Algebra::dotProduct(subtraction, referenceVector.getBasisY())};
}

const std::vector<float> Algebra::reflect(std::vector<float> object,
                                          std::vector<float> surface)
{
  std::vector<float> reflectScaled = {
    Algebra::dotProduct(object, surface) * 2 * surface[0],
    Algebra::dotProduct(object, surface) * 2 * surface[1]};

  return Algebra::minus(object, reflectScaled);
}
