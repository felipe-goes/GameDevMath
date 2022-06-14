#pragma once

#include "Algebra.hpp"
#include <vector>

class Player
{
private:
  std::vector<float> center;
  float radius;

private:
  void initVariables(void);

public:
  Player();
  ~Player();
  Player(std::vector<float> center, float radius);

  bool collide(std::vector<float> enemy);
};
