#include "gameManager.hpp"
#include <algorithm>
#include <raylib.h>

#include <iomanip>
#include <sstream>

void GameManager::addEntity(std::unique_ptr<Entity> e) {
    entities.push_back(std::move(e));
}

void GameManager::refreshEntities() {
  entities.erase(
        std::remove_if(
            entities.begin(),
            entities.end(),
            [](const std::unique_ptr<Entity>& e) {
                return !e->isAlive();
            }
        ),
        entities.end()
    );
}

void GameManager::checkResetBind() {
  if(IsKeyPressed(KEY_F2)) {
    resetReq = true;
  }

}

void GameManager::inputLoop(float dt) {
  for (auto& e : entities) {
    if (e->isPlayer)
        e->input(dt);
  }
  checkResetBind();
}

void GameManager::collisionLoop() {
  for (size_t i = 0; i < entities.size(); ++i) {
    for (size_t j = i + 1; j < entities.size(); ++j) {

      if (!entities[i]->collidesWith(*entities[j]))
        continue;

      entities[i]->onCollision(*entities[j]);
      entities[j]->onCollision(*entities[i]);
    }
  }

}

void GameManager::updateEntities(float dt) {
  for (auto& e : entities) {
    e->update(dt);
    if(e->checkWindowCollisions(w, h)) { resetReq = true; };
  }
  collisionLoop();

 
}

void GameManager::updateWindowSizeForEntities() {
  for (auto& e : entities) {
    e->onResize(w, h);
  }
}

void GameManager::update(float dt) {
    if(!checkPause()) {
      inputLoop(dt);
      updateEntities(dt);
      refreshEntities();
    }
    else {
      drawRoundedTimer();
    }
    startTimer -= dt;
}

void GameManager::draw() {
    for (auto& e : entities) {
       e->draw(); 
    }
}

int GameManager::init() {
    Rocket player("Terska Thruster", w/2, h/4, 40, 65, nullptr, PURPLE);
    player.isPlayer = true;
    entities.push_back(std::make_unique<Rocket>(player));

    float platformWidth = 300;
    float platformHeight = 30;

    std::unique_ptr<RocketPlatform> platform =
    std::make_unique<RocketPlatform>(
      Rectangle{
        (float)w / 2,
        (float)h / 1.2f,
        platformWidth,
        platformHeight
      }
    );

entities.push_back(std::move(platform));
    return 1;
}

bool GameManager::isRunning() const {
  return gameRunning;
}


bool GameManager::checkPause() const {
  return startTimer>0.0f;
}

void GameManager::stop() {
  gameRunning = false;
}

void GameManager::drawFPS() {
    DrawText(TextFormat("FPS: %d", GetFPS()), 10, 10, 20, PURPLE);
}

void GameManager::reset() {
  entities.clear();
  resetReq = false;

  startTimer = GameManager::gracePeriod;

}

bool GameManager::wantsReset() {
  return resetReq;
}

void GameManager::drawTimer(std::string text) {
  if (!timer) {
    timer = std::make_unique<StartTimer>();
  }
  timer->draw(text, w, h);
}
void GameManager::drawRoundedTimer() {
  std::stringstream ss;
  ss << std::fixed << std::setprecision(3) << startTimer;
  drawTimer(ss.str());
}


void GameManager::windowResized(int newW, int newH) {
  w = newW;
  h = newH;
  updateWindowSizeForEntities();
}
