#include "screens/mainMenu/UI/elements/button.hpp"
#include "raylib.h"

Button::Button(Rectangle bounds, const std::string& text)
    : text(text)
{
    this->bounds = bounds;
}

void Button::update() {
    Vector2 mousePosition = GetMousePosition();

    hovered = CheckCollisionPointRec(mousePosition, bounds);

    clicked = hovered && IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
}

void Button::draw()
{
    Color color = style.normalColor;

    if (hovered)
        color = style.hoverColor;

    if (hovered && IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        color = style.pressedColor;

    DrawRectangleRec(bounds, color);

    int textWidth = MeasureText(text.c_str(), style.fontSize);
    int textX = static_cast<int>(bounds.x + (bounds.width - textWidth) / 2);
    int textY = static_cast<int>(bounds.y + (bounds.height - style.fontSize) / 2);

    DrawText(text.c_str(), textX, textY, style.fontSize, style.textColor);
}
bool Button::isClicked() const {
    return clicked;
}
