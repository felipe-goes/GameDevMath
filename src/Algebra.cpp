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
