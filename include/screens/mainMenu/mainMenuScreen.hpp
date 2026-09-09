#pragma once

#include "state/state.hpp"
#include "screens/mainMenu/UI/containers/panel.hpp"
#include "screens/mainMenu/UI/core/layout/layout.hpp"

#include <string>


class MainMenuScreen : public State {
  public:
    MainMenuScreen(int w, int h);

    void draw() override;
    void update(float dt) override;

    void init(int w, int h) override;

    void reset() override;

    Layout createMenuLayout();




    static constexpr const char* playButtonText = "Play";
  private:
    Panel menuPanel;

    int w, h;
};
