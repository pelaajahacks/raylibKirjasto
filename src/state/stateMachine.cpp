#include "state/stateMachine.hpp"

void StateMachine::changeState(std::unique_ptr<State> state)
{
    currentState = std::move(state);
}

void StateMachine::update(float dt)
{
    if (currentState)
        currentState->update(dt);
}

void StateMachine::draw()
{
    if (currentState)
        currentState->draw();
}
void StateMachine::onResize(int w, int h)
{
    if (currentState)
        currentState->onResize(w, h);
}
