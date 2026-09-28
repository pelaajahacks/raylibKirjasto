#include "core/manager/gameManager.hpp"

void GameManager::changeState(std::unique_ptr<State> state) {
    state->changeState = [this](std::unique_ptr<State> next) {
        this->changeState(std::move(next));
    };

    state->quit = [this]() {
        this->stop();
    };

    state->reset();
    stateMachine.changeState(std::move(state));
}

void GameManager::init(std::unique_ptr<State> state) {
    changeState(std::move(state));
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
