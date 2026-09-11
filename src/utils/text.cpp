#include "utils/text.hpp"

Text::Text(std::string text, Color fg, int FONTSIZE)
    : text(text), fg(fg), FONTSIZE(FONTSIZE)
{
}

void Text::setColor(Color fgColor) {
    fg = fgColor;
}

void Text::setText(std::string newText) {
    text = newText;
}
const std::string& Text::getText() const {
    return text;
}

void Text::draw(int x, int y) const {
  DrawText(text.c_str(), x, y, FONTSIZE, fg);
}
