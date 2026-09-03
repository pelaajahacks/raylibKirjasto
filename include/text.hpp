#pragma once

#include <raylib.h>
#include <string>

class Text {
  public:
    Text(std::string text);
    virtual void setColor(Color fg);
    void setText(std::string text);
    const std::string& getText() const;

    virtual void draw(int x, int y) const;

    int fontSize = 16.0f;
  private:
    std::string text = "text";
  protected:
    Color fg = BLACK;

};
