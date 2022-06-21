#pragma once

#include <vector>

// Trying to simulate Unity Mesh concept as understood from the video
// https://www.youtube.com/watch?v=1NLekEd770w&list=PLImQaTpSAdsD88wprTConznD1OY1EfK_V&index=3
class UnityMesh
{
private:
  std::vector<std::vector<float>> vector3d;
  std::vector<int> trianglesIndices;

public:
  UnityMesh(std::vector<std::vector<float>> vector3d,
            std::vector<int> trianglesIndices);
  ~UnityMesh();

  // Accessors
  const std::vector<std::vector<float>> getVector3d(void);
  const std::vector<int> getTrianglesIndices(void);
};
