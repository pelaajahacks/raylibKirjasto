#pragma once

#include <raylib.h>
#include <string>

class Nametag {
  public:
    Nametag(std::string text);
    int setColor(Color fg, Color bg);
    int setText(std::string text);

    void draw(float x, float y, float entityHeight, float entityWidth) const;

    static constexpr float YPADDING = 8.0f;
    

  private:
    Rectangle rect;
    std::string text = "nametag";
    Color bg = GRAY;
    Color fg = RAYWHITE;


};
