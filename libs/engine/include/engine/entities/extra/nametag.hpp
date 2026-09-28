#pragma once

#include "engine/utils/text.hpp"

class Nametag: public Text {
  public:
    Nametag(std::string text);

    void setColor(Color fg, Color bg);
    
    void draw(float x, float y, float entityHeight, float entityWidth) const;

    static constexpr float YPADDING = 8.0f;
    static constexpr int fontSize = 20;
    static constexpr float padding = 4.0f;
    

  private:
    Rectangle rect;

  protected:
      Color bg = GRAY;
      Color fg = RAYWHITE;


};
