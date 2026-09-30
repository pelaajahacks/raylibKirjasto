#pragma once

#include "engine/state/state.hpp"
#include "../styling/screenStyle.hpp"
#include "ui/Panel.hpp"
#include "ui/Button.hpp"
#include "ui/Layout.hpp"

#include <string>


class GameManager;

class MainMenuScreen : public State {
  public:
    MainMenuScreen(int w, int h)
      : w(w),
        h(h),
        canvas({
          .width = static_cast<float>(w),
          .height = static_cast<float>(h)
        })
  {};

    void draw() override;
    void update(float dt) override;

    void init(int w, int h) override;

    void reset() override;

    void onResize(float w, float h) override;




    static constexpr const char* playButtonText = "Play";
  private:
    Panel canvas;
    Layout layout;
    ScreenStyle style;

    int w, h;
};
