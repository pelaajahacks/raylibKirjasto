#pragma once

#include "engine/state/state.hpp"
#include "engine/utils/startTimer.hpp"
#include "game/entities/rocket/rocket.hpp"
#include "game/entities/rocket/rocketPlatform.hpp"

#include "styling/screenStyle.hpp"

#include <vector>
#include <memory>
#include <string>


#include <iomanip>



class GameScreen : public State {
  public:
    GameScreen(int w, int h);

    void update(float dt) override;
    void draw() override;

    void updateWindowSizeForEntities(); 
    void addEntity(std::unique_ptr<Entity> e);

    void drawFPS();
    void drawTimer(std::string text);
    void drawRoundedTimer();

    void init(int w, int h);

    void inputLoop(float dt);
    void updateEntities(float dt);
    void refreshEntities();

    void collisionLoop();
    void checkBounds();

    bool checkPause() const;
    
    bool wantsReset();
    void reset();
    void checkResetBind();

    void onResize(float w, float h) override;

    static constexpr float gracePeriod = 1.0f;





  private:
    std::vector<std::unique_ptr<Entity>> entities;
    std::unique_ptr<StartTimer> timer;

    Rocket* player = nullptr;

    float startTimer;
    bool resetReq = true;
    bool gamePaused;

    int w, h;

    Color bg = RAYWHITE;
    ScreenStyle style;

};
