#include "game/screens/gameScreen.hpp"

#include <algorithm>
#include <iomanip>
#include <sstream>

GameScreen::GameScreen(int w, int h)
  : w(w), h(h) {
}
void GameScreen::init(int w, int h) {
    style.background = bg;

    auto rocket = std::make_unique<Rocket>(
        "Lunaarinen Ländääjä",
        w / 2.0f,
        h / 4.0f,
        40,
        65,
        nullptr,
        PURPLE
    );

    rocket->isPlayer = true;

    player = rocket.get();

    entities.push_back(std::move(rocket));

    entities.push_back(
        std::make_unique<RocketPlatform>(
            Rectangle{
                w / 2.0f,
                h / 1.2f,
                300.0f,
                30.0f
            }
        )
    );

}

void GameScreen::drawFPS() {
    DrawText(TextFormat("FPS: %d", GetFPS()), 10, 10, 20, PURPLE);
}

void GameScreen::drawTimer(std::string text) {
  timer->draw(text, w, h);
}
void GameScreen::drawRoundedTimer() {
  std::stringstream ss;
  ss << std::fixed << std::setprecision(3) << startTimer;
  drawTimer(ss.str());
}

void GameScreen::draw()
{
    ClearBackground(style.background);
    for (auto& entity : entities)
        entity->draw();
    drawFPS();
}
void GameScreen::inputLoop(float dt) {
  for (auto& e : entities) {
    if (e->isPlayer)
        e->input(dt);
  }
  checkResetBind();
}


void GameScreen::collisionLoop() {
  for (size_t i = 0; i < entities.size(); ++i) {
    for (size_t j = i + 1; j < entities.size(); ++j) {

      if (!entities[i]->collidesWith(*entities[j]))
        continue;

      entities[i]->onCollision(*entities[j]);
      entities[j]->onCollision(*entities[i]);
    }
  }

}

void GameScreen::refreshEntities() {
  entities.erase(
        std::remove_if(
            entities.begin(),
            entities.end(),
            [](const std::unique_ptr<engine::Entity>& e) {
                return !e->isAlive();
            }
        ),
        entities.end()
    );
}


void GameScreen::onResize(float w, float h)
{
    this->w = w;
    this->h = h;

    updateWindowSizeForEntities();
}

void GameScreen::updateWindowSizeForEntities() {
  for (auto& e : entities) {
    e->onResize(w, h);
  }
}
void GameScreen::updateEntities(float dt) {
  for (auto& e : entities) {
    e->update(dt);
    if(e->checkWindowCollisions(w, h)) { reset(); };
  }
  collisionLoop();
}

void GameScreen::update(float dt) {
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

bool GameScreen::wantsReset() {
  return resetReq;
}
bool GameScreen::checkPause() const {
  return startTimer>0.0f;
}

void GameScreen::checkResetBind() {
  if(IsKeyPressed(KEY_F2)) {
    reset();
  }
}

void GameScreen::reset() {
  entities.clear();
  timer = std::make_unique<engine::StartTimer>();
  player = nullptr;
  init(w, h);
  resetReq = false;
  startTimer = gracePeriod;
  updateWindowSizeForEntities();
}
