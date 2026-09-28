#pragma once

#include <functional>
#include <memory>


class State {
  public:
    virtual ~State() = default;

    virtual void update(float dt) = 0;
    virtual void draw() = 0;
    virtual void init(int w, int h) = 0;

    virtual void reset() = 0;

    virtual void onResize(float w, float h) {}
    
    std::function<void(std::unique_ptr<State>)> changeState;
    std::function<void()> quit;

};
