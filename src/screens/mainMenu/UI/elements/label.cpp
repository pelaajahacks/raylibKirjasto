#include "screens/mainMenu/UI/elements/label.hpp"
#include "raylib.h"

Label::Label(const std::string& text, Vector2 position, Color color, int fontSize)
    : text(text), color(color), fontSize(fontSize)
{
    bounds = {
        position.x,
        position.y,
        static_cast<float>(MeasureText(text.c_str(), fontSize)),
        static_cast<float>(fontSize)
    };
}

void Label::update()
{
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
