#include "utils/startTimer.hpp"

StartTimer::StartTimer(std::string text)
  : Text(text) {
}

void StartTimer::draw(std::string text, int w, int h) const {
  float textWidth = MeasureText(text.c_str(), FONTSIZE);
  DrawText(text.c_str(), (w/2)-(textWidth*0.5f), h/2, FONTSIZE, fg);
}
