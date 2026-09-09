#pragma once

class State
{
public:
    virtual ~State() = default;

    virtual void update(float dt) = 0;
    virtual void draw() = 0;

    virtual void onResize(float w, float h) {}
};
