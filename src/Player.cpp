#include "Player.hpp"
#include "Algebra.hpp"

Player::Player() { initVariables(); }
Player::Player(std::vector<float> center, float radius)
  : center(center), radius(radius)
{
  basisX = {1.4142f, 1.4142f};
  basisY = {-1.4142f, 1.4142f};
}
Player::Player(std::vector<float> center, float radius,
               std::vector<float> basisX, std::vector<float> basisY)
  : center(center), radius(radius), basisX(basisX), basisY(basisY)
{
}

Player::~Player() {}

// Init functions
void Player::initVariables(void)
{
  center = {5.f, 15.f}; // X, Y
  radius = 5.f;
}

// Private functions
void Player::updateLooking(std::vector<float> enemy, float threshold)
{
  std::vector<float> playerNormalized = Algebra::normalize(center);
  std::vector<float> enemyNormalized = Algebra::normalize(enemy);

  float projection = Algebra::dotProduct(playerNormalized, enemyNormalized);

  looking = projection >= threshold;
}

// Public Functions
void Player::collide(std::vector<float> enemy)
{
  float distance = Algebra::distance(this->center, enemy);
  collided = distance <= radius;
}

// Accessors
bool Player::checkCollision(void) const { return collided; }
bool Player::isLooking(void) const { return looking; }
std::vector<float> Player::getBasisX(void) const { return basisX; }
std::vector<float> Player::getBasisY(void) const { return basisY; }
std::vector<float> Player::getCenter(void) const { return center; }
