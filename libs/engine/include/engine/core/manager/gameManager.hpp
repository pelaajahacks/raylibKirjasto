#pragma once

#include <engine/state/stateMachine.hpp>


class GameManager {
  public:
     
    void update(float dt);
    void draw();

    void init(std::unique_ptr<State> initialState);
    void changeState(std::unique_ptr<State> state);

    void windowResized(int w, int h);

    bool isRunning() const;
    void stop();




  private:
   
    bool gameRunning = true;
    StateMachine stateMachine;
};
