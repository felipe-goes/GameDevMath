#include "Player.hpp"
#include <vector>

Player::Player() { initVariables(); }
Player::Player(std::vector<float> center, float radius)
  : center(center), radius(radius)
{
}

Player::~Player() {}

// Init functions
void Player::initVariables(void)
{
  center = {5.f, 15.f}; // X, Y
  radius = 5.f;
}

// Public Functions
bool Player::collide(std::vector<float> enemy)
{
  float distance = Algebra::distance(this->center, enemy);
  return distance <= radius;
}
