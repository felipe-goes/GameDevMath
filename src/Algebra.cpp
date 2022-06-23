#include "Algebra.hpp"
#include <cmath>
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
  if (vector.size() == 2)
    return std::sqrt(vector[0] * vector[0] + vector[1] * vector[1]);
  else
    return std::sqrt(vector[0] * vector[0] + vector[1] * vector[1] +
                     vector[2] * vector[2]);
}

const std::vector<float> Algebra::normalize(std::vector<float> vector)
{
  float length = Algebra::length(vector);
  float error = 0.0001f;

  if (length != 0)
  {
    if (length >= (1 - error) && length <= (1 + error))
      return vector;

    if (vector.size() == 2)
    {
      return {vector[0] / length, vector[1] / length};
    }
    else
    {
      return {(vector[0] / length), (vector[1] / length), (vector[2] / length)};
    }
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
  return std::abs(Algebra::length(crossProduct)) / 2;
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
    int remainder = i % 3;
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

const signed char Algebra::sign(float value)
{
  if (value > 0)
    return 1;
  else if (value < 0)
    return -1;
  else
    return 0;
}

const std::vector<std::vector<float>>
Algebra::turrentPlacement(std::vector<float> normal, std::vector<float> ray)
{
  unsigned char count = 0;
  count = Algebra::sign(ray[0]) < Algebra::sign(normal[0]) ? count + 1 : count;
  count = Algebra::sign(ray[1]) < Algebra::sign(normal[1]) ? count + 1 : count;
  count = Algebra::sign(ray[2]) < Algebra::sign(normal[2]) ? count + 1 : count;

  std::vector<float> x, z;

  if (count < 2)
  {
    z = Algebra::crossProduct(ray, normal);
    z = Algebra::normalize(z);

    x = Algebra::crossProduct(normal, z);
    x = Algebra::normalize(x);
  }
  else
  {
    z = Algebra::crossProduct(normal, ray);
    z = Algebra::normalize(z);

    x = Algebra::crossProduct(z, normal);
    x = Algebra::normalize(x);
  }

  return {x, Algebra::normalize(normal), z};
}

const std::vector<float> Algebra::localToWorldMatrix(
  std::vector<std::vector<float>> transformationMatrix,
  std::vector<float> vector)
{
  return {transformationMatrix[0][0] * vector[0] +
            transformationMatrix[0][1] * vector[1] +
            transformationMatrix[0][2] * vector[2] +
            transformationMatrix[0][3] * vector[3],

          transformationMatrix[1][0] * vector[0] +
            transformationMatrix[1][1] * vector[1] +
            transformationMatrix[1][2] * vector[2] +
            transformationMatrix[1][3] * vector[3],

          transformationMatrix[2][0] * vector[0] +
            transformationMatrix[2][1] * vector[1] +
            transformationMatrix[2][2] * vector[2] +
            transformationMatrix[2][3] * vector[3],
          1};
}
