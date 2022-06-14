#pragma once

#include "Player.hpp"
#include <iostream>
#include <vector>

class Game
{
private:
  Player player;
  std::vector<float> enemy;
  bool collided;

private:
  void initVariables(void);

public:
  Game();
  ~Game();

  void update(void);
  void render(void);

  bool checkCollision(void);
};
