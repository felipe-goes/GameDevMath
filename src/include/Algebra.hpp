#pragma once

#include <cmath>
#include <vector>

class Algebra
{
public:
  Algebra();
  ~Algebra();

  const static float distance(const std::vector<float> player,
                              const std::vector<float> enemy);
};
