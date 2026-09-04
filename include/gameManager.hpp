#pragma once

#include <vector>
#include <memory>
#include <string>
#include "entity.hpp"
#include "startTimer.hpp"
#include "rocket.hpp"
#include "rocketPlatform.hpp"


class GameManager {
  public:
      
    void windowResized(int w, int h);
    void updateWindowSizeForEntities(); 
    void addEntity(std::unique_ptr<Entity> e);

    void update(float dt);
    void draw();
    void drawFPS();
    void drawTimer(std::string text);
    void drawRoundedTimer();

    int init();

    void inputLoop(float dt);
    void updateEntities(float dt);
    void refreshEntities();

    void collisionLoop();

    void reset();

    bool isRunning() const;
    bool checkPause() const;
    void stop();

    bool wantsReset();
    void checkResetBind();

    static constexpr float gracePeriod = 1.0f;

  private:
    std::vector<std::unique_ptr<Entity>> entities;
    std::unique_ptr<StartTimer> timer;

    std::unique_ptr<Rocket> player;
    std::unique_ptr<RocketPlatform> platform;

    bool gamePaused;
    bool gameRunning = true;
    bool resetReq = true;

    float startTimer;

    int w, h;
};
