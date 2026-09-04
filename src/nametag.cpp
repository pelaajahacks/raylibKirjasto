#include "nametag.hpp"

Nametag::Nametag(std::string text)
    : Text(text)
{
}

void Nametag::setColor(Color fgColor, Color bgColor)
{
    fg = fgColor;
    bg = bgColor;
}

void Nametag::draw(float x, float y, float entityWidth, float entityHeight) const {

    float textWidth = MeasureText(getText().c_str(), fontSize);
    float drawX = x - (textWidth * 0.5f);

    float drawY = y - entityHeight/2 - fontSize - YPADDING;

    Rectangle bgRect = {
        drawX - padding,
        drawY - padding,
        textWidth + padding * 2.0f,
        fontSize + padding * 2.0f
    };

    DrawRectangleRec(bgRect, bg);
    DrawText(getText().c_str(), (int)drawX, (int)drawY, fontSize, fg);
}
