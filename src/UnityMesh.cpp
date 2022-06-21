#include "UnityMesh.hpp"
#include <vector>

UnityMesh::UnityMesh(std::vector<std::vector<float>> vector3d,
                     std::vector<int> trianglesIndices)
{
  this->vector3d = std::vector<std::vector<float>>(8, std::vector<float>(3));
  this->vector3d = vector3d;
  this->trianglesIndices = trianglesIndices;
}

UnityMesh::~UnityMesh() {}

// Accessors
const std::vector<std::vector<float>> UnityMesh::getVector3d(void)
{
  return vector3d;
}
const std::vector<int> UnityMesh::getTrianglesIndices(void)
{
  return trianglesIndices;
}
