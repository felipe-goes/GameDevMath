#pragma once

#include "Player.hpp"
#include <cmath>
#include <vector>

class Algebra
{
public:
  Algebra();
  ~Algebra();

  const static float distance(const std::vector<float> player,
                              const std::vector<float> enemy);

  const static float length(std::vector<float> vector);
  const static std::vector<float> normalize(std::vector<float> vector);
  const static float dotProduct(std::vector<float> vectorA,
                                std::vector<float> vectorB);

  const static std::vector<float> minus(std::vector<float> vectorA,
                                        std::vector<float> vectorB);
  const static std::vector<float> localToWorld(Player referenceVector,
                                               std::vector<float> localVector);
  const static std::vector<float> worldToLocal(Player referenceVector,
                                               std::vector<float> worldVector);
  const static std::vector<float> reflect(std::vector<float> object,
                                          std::vector<float> surface);
};
