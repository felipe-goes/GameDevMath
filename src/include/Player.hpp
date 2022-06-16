#pragma once

#include <vector>

class Player
{
private:
  std::vector<float> center;
  float radius;
  bool looking;
  bool collided;

  std::vector<float> basisX;
  std::vector<float> basisY;

private:
  void initVariables(void);

public:
  Player();
  ~Player();
  Player(std::vector<float> center, float radius);
  Player(std::vector<float> center, float radius, std::vector<float> basisX,
         std::vector<float> basisY);

  void collide(std::vector<float> enemy);
  void updateLooking(std::vector<float> enemy, float threshold);

  // Accessors
  bool checkCollision(void) const;
  bool isLooking(void) const;
  std::vector<float> getBasisX(void) const;
  std::vector<float> getBasisY(void) const;
  std::vector<float> getCenter(void) const;
};
