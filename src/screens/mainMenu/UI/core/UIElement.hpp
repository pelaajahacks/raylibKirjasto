#pragma once

#include <raylib.h>

class UIElement {
public:
    virtual ~UIElement() = default;

    virtual void Update() = 0;
    virtual void Draw() = 0;

    Rectangle GetBounds() const {
        return bounds;
    }

protected:
    Rectangle bounds{};
};
