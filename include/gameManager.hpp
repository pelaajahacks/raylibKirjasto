#pragma once

#include <state/stateMachine.hpp>
#include <screens/gameScreen.hpp>


class GameManager {
  public:
     
    void update(float dt);
    void draw();

    void init(int w, int h);

    void windowResized(int w, int h);

    bool isRunning() const;
    void stop();




  private:
   
    bool gameRunning = true;
    StateMachine stateMachine;
};
