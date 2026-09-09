#pragma once

#include <memory>
#include "state.hpp"

class StateMachine {
public:
    void changeState(std::unique_ptr<State> state);

    void onResize(int w, int h);

    void update(float dt);
    void draw();

private:
    std::unique_ptr<State> currentState;
};
