#pragma once

#include "raylib.h"
#include <string>

class UIElement {
public:
    virtual ~UIElement() = default;

    virtual void update() = 0;
    virtual void draw() = 0;

    Rectangle getBounds() const { return bounds; };
    void setBounds(Rectangle newBounds) { bounds = newBounds; };

protected:
    Rectangle bounds{};
};
