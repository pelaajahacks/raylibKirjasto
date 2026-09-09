#pragma once

#include "screens/mainMenu/UI/core/UIElement.hpp"
#include <memory>

struct ButtonStyle
{
    Color normalColor = DARKGRAY;
    Color hoverColor = GRAY;
    Color pressedColor = LIGHTGRAY;

    Color textColor = WHITE;

    int fontSize = 20;

    float borderRadius = 0.0f;
    float borderWidth = 0.0f;
    Color borderColor = WHITE;
};

class Button : public UIElement {
public:
    Button(Rectangle bounds, const std::string& text);

    void update() override;
    void draw() override;

    void setStyle(const ButtonStyle& style);

    bool isClicked() const;

private:
    std::string text;
    ButtonStyle style;

    bool hovered = false;
    bool clicked = false;
};
