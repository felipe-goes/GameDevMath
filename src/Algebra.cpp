#include "Algebra.hpp"

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
  if (vector.size() == 2)
    return sqrt(vector[0] * vector[0] + vector[1] * vector[1]);
  else
    return sqrt(vector[0] * vector[0] + vector[1] * vector[1] +
                vector[2] * vector[2]);
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
  if (vectorA.size() == 2)
    return {vectorA[0] - vectorB[0], vectorA[1] - vectorB[1]};
  else
    return {vectorA[0] - vectorB[0], vectorA[1] - vectorB[1],
            vectorA[2] - vectorB[2]};
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

const std::vector<float> Algebra::crossProduct(std::vector<float> vectorA,
                                               std::vector<float> vectorB)
{
  return {vectorA[1] * vectorB[2] - vectorA[2] * vectorB[1],
          vectorA[2] * vectorB[0] - vectorA[0] * vectorB[2],
          vectorA[0] * vectorB[1] - vectorA[1] * vectorB[0]};
}

const float Algebra::area(std::vector<float> vectorA,
                          std::vector<float> vectorB)
{
  std::vector<float> crossProduct = Algebra::crossProduct(vectorA, vectorB);
  return std::abs(Algebra::length(crossProduct))/2;
}

const float Algebra::meshArea(UnityMesh mesh)
{
  float totalArea = 0;
  std::vector<std::vector<float>> vector3d(8, std::vector<float>(3)); 
  vector3d = mesh.getVector3d();

  std::vector<float> vectorA(3);
  std::vector<float> vectorB(3);
  std::vector<float> vectorC(3);

  std::vector<float> crossA;
  std::vector<float> crossB;

  for (int i = 0; i < mesh.getTrianglesIndices().size(); i++)
  {
    int remainder = i%3;
    if (i % 3 == 0)
    {
      vectorA[0] = vector3d[remainder][0];
      vectorA[1] = vector3d[remainder][1];
      vectorA[2] = vector3d[remainder][2];
    }
    else if (i % 3 == 1)
    {
      vectorB[0] = vector3d[remainder][0];
      vectorB[1] = vector3d[remainder][0];
      vectorB[2] = vector3d[remainder][0];
    }
    else
    {
      vectorC[0] = vector3d[remainder][0];
      vectorC[1] = vector3d[remainder][1];
      vectorC[2] = vector3d[remainder][2];

      crossA = Algebra::minus(vectorA, vectorB);
      crossB = Algebra::minus(vectorA, vectorC);

      totalArea += Algebra::area(crossA, crossB);
    }
  }

  return totalArea;
}
