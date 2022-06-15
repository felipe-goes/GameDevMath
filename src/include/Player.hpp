#pragma once

#include "Algebra.hpp"
#include <vector>

class Player
{
private:
  std::vector<float> center;
  float radius;
  bool looking;
  bool collided;

private:
  void initVariables(void);

public:
  Player();
  ~Player();
  Player(std::vector<float> center, float radius);

  void collide(std::vector<float> enemy);
  bool isLooking(std::vector<float> enemy, float threshold);

  // Accessors
  bool checkCollision(void);
};
