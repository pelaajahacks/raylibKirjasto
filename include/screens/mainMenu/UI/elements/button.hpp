#pragma once

#include "screens/mainMenu/UI/core/UIElement.hpp"

#include "raygui.h"

#include <memory>
#include <string>


class Button : public UIElement {
public:
    Button(Layout layout, const std::string& text);

    void update() override;
    void draw() override;

    bool isClicked() const;

private:
    std::string text;

    bool hovered = false;
    bool clicked = false;
};
