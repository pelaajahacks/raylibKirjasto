#include "bar.hpp"

Bar::Bar(Color barColor, Color bgColor)
  : barColor(barColor),
    bgColor(bgColor) {
}

void Bar::draw(float progress, float maxValue) const {
  DrawRectangleRec(rect, bgColor);
  float fillHeight = rect.height * (progress / maxValue);

  Rectangle fill = {
        rect.x,
        rect.y + rect.height - fillHeight,
        rect.width,
        fillHeight
    };

    DrawRectangleRec(fill, barColor);

}

void Bar::setBarRect(Rectangle newRect) {
  rect = newRect;
}
