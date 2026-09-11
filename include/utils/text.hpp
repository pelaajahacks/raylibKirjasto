#pragma once

#include <raylib.h>
#include <string>

class Text {
  public:
    Text(std::string text, Color fg = BLACK, int FONTSIZE = 16.0f);
    virtual void setColor(Color fg);
    void setText(std::string text);
    const std::string& getText() const;

    virtual void draw(int x, int y) const;

  private:
    std::string text = "text";
    int FONTSIZE;
  protected:
    Color fg;
};
