#pragma once

#include "text.hpp"
#include <raylib.h>
#include <string>

class StartTimer : public Text {
  public:
    StartTimer(std::string text = "timer");
    void draw(std::string, int w, int h) const;
    static constexpr float FONTSIZE = 64.0f;


  private:


};
