#include "nametag.hpp"

Nametag::Nametag(std::string text)
    : text(text)
{
}

int Nametag::setColor(Color fgColor, Color bgColor)
{
    fg = fgColor;
    bg = bgColor;
    return 0;
}

int Nametag::setText(std::string newText)
{
    text = newText;
    return 0;
}

void Nametag::draw(float x, float y, float entityWidth, float entityHeight) const
{
    int fontSize = 20;

    float textWidth = MeasureText(text.c_str(), fontSize);

    float padding = 4.0f;

    float drawX = x + (entityWidth * 0.5f) - (textWidth * 0.5f);

    float topY = y - (entityHeight * 0.5f);
    float drawY = topY - YPADDING;

    Rectangle bgRect = {
        drawX - padding,
        drawY - padding,
        textWidth + padding * 2.0f,
        fontSize + padding * 2.0f
    };

    DrawRectangleRec(bgRect, bg);
    DrawText(text.c_str(), (int)drawX, (int)drawY, fontSize, fg);
}
