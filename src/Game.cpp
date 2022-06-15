#include "Game.hpp"

Game::Game() { initVariables(); }

Game::~Game() {}

// Init functions
void Game::initVariables(void)
{
  enemy = {10.f, 10.f}; // X, Y
}

void Game::update(void) { player.collide(enemy); }

void Game::render(void)
{
  std::cout << "Collided: " << player.checkCollision() << std::endl;
}
