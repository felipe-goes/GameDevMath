#include "Game.hpp"

Game::Game() { initVariables(); }

Game::~Game() {}

// Init functions
void Game::initVariables(void)
{
  enemy = {10.f, 10.f}; // X, Y
  player = Player();
}

void Game::update(void)
{
  player.collide(enemy);
  player.updateLooking(enemy, 0.8);
}

void Game::render(void)
{
  std::cout << "Collided: " << player.checkCollision() << std::endl;
  std::cout << "Is looking: " << player.isLooking() << std::endl;
}
