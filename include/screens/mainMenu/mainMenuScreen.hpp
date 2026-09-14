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
    Layout createTitleLayout();
    Layout createTitleChildrenLayout();

    void onResize(float w, float h) override;




    static constexpr const char* playButtonText = "Play";
  private:
    Panel canvas;
    Panel* titlePanel;
    Panel* menuPanel;
    Panel* footerPanel;

    Layout buttonLayout = [] {
        Layout layout;
        layout.width = SizeMode::Fill;
        layout.height = SizeMode::FitContent;
        layout.flexGrow = 1.0f;
        return layout;
    }();

    Layout labelLayout = [] {
        Layout layout;
        layout.width = SizeMode::FitContent;
        layout.height = SizeMode::FitContent;
        return layout;
    }();

    int w, h;
};
