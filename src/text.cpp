#include "text.hpp"

Text::Text(std::string text)
    : text(text)
{
}

void Text::setColor(Color fgColor)
{
    fg = fgColor;
}

void Text::setText(std::string newText)
{
    text = newText;
}
const std::string& Text::getText() const
{
    return text;
}

void Text::draw(int x, int y) const {
  DrawText(text.c_str(), x, y, fontSize, fg);
}
