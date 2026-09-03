#pragma once

#include <raylib.h>

class Bar {
  public:
    Bar(Color barColor = BLACK, Color bgColor = DARKGRAY);
    void draw(float progress, float maxValue) const;

    void setBarRect(Rectangle newRect);


  private:
    Color barColor;
    Color bgColor;

    Rectangle rect;

    
};
