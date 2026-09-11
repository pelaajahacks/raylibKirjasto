#include "screens/mainMenu/UI/elements/label.hpp"
#include "raylib.h"

Label::Label(Rectangle bounds, Layout layout, const std::string& text, Color color, int fontSize)
    : UIElement(bounds, layout),
      text(text),
      fontSize(fontSize),
      color(color) {
}

void Label::draw()
{
    DrawText(
        text.c_str(),
        static_cast<int>(bounds.x),
        static_cast<int>(bounds.y),
        fontSize,
        color
    );
}

void Label::setText(const std::string& newText)
{
    text = newText;
}

const std::string& Label::GetText() const
{
    return text;
}
