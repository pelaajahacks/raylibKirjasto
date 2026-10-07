#pragma once

#include "engine/state/state.hpp"
#include "../styling/screenStyle.hpp"
#include "ui/Panel.hpp"
#include "ui/Button.hpp"
#include "ui/Layout.hpp"

#include <string>


namespace game {

class MainMenuScreen : public engine::State {
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
    ui::Panel canvas;
    ui::Layout layout;
    ScreenStyle style;

    bool uiDirty = false;
    std::string buttonText = "Testing";
    ui::Button* btn = nullptr;

    int w, h;
};

} // namespace game
