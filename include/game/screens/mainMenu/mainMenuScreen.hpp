#pragma once

#include "engine/state/state.hpp"

#include "ui/Button.hpp"
#include "ui/Layout.hpp"
#include "ui/Panel.hpp"

#include <memory>


class MainMenuScreen : public engine::State {
  public:
    MainMenuScreen(int w, int h);

    void draw() override;
    void update(float dt) override;

    void init(int w, int h) override;

    void reset() override;

    void onResize(float w, float h) override;

  private:
    Layout layout;                   // ui layout engine (owns the lay_context)
    std::unique_ptr<Panel> canvas;   // root element, rebuilt by init()
    Button* playButton = nullptr;    // owned by canvas

    int w, h;
};
