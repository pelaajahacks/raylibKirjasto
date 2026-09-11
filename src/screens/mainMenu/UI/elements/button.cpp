#include "screens/mainMenu/UI/elements/button.hpp"

Button::Button(Layout layout, const std::string& text)
    : UIElement({0, 0, 0, 0}, layout),
      text(text) {
}

void Button::update() {
    clicked = false;
}

void Button::draw() {
    if (GuiButton(bounds, text.c_str()))
        clicked = true;
}

bool Button::isClicked() const {
    return clicked;
}
