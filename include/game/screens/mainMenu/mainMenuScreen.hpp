#pragma once

#include "engine/state/state.hpp"
#include "../styling/screenStyle.hpp"
#include "ui/Panel.hpp"
#include "ui/Button.hpp"
#include "ui/layout.hpp"

#include <string>


class GameManager;

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

    Button* startButton = nullptr;
    Button* settingsButton = nullptr;
    Button* quitButton = nullptr;

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

    ScreenStyle style;

    int w, h;
};
