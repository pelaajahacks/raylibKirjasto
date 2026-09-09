#include "gameManager.hpp"

void GameManager::init(int w, int h) {
  auto screen = std::make_unique<MainMenuScreen>(w, h);
  screen->reset();
  stateMachine.changeState(std::move(screen));
}

void GameManager::update(float dt) {
    stateMachine.update(dt);
}

void GameManager::draw() {
    stateMachine.draw();
}

bool GameManager::isRunning() const {
  return gameRunning;
}

void GameManager::stop() {
  gameRunning = false;
}

void GameManager::windowResized(int w, int h) {
    stateMachine.onResize(w, h);
}
