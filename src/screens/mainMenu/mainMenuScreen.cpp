#include "screens/mainMenu/mainMenuScreen.hpp"
#include "ui/Button.hpp"
#include "ui/Label.hpp"
#include "core/gameManager.hpp"

MainMenuScreen::MainMenuScreen(GameManager* manager, int w, int h)
    : manager(manager),
      w(w),
      h(h),
      canvas(
        Layout{
          .width = SizeMode::Fixed,
          .height = SizeMode::Fixed,
          .widthValue = static_cast<float>(w),
          .heightValue = static_cast<float>(h)},
        FlexLayout{
          .direction = FlexDirection::Column,
          .padding = 20,
          .spacing = 30,
          .horizontalAlignment = Alignment::Center,
          .verticalAlignment = Alignment::Center}),
      titlePanel(nullptr),
      menuPanel(nullptr),
      footerPanel(nullptr){
        canvas.setDrawBackground(false);

        Layout titleLayout{
    .width = SizeMode::Fixed,
    .height = SizeMode::Fixed,
    .widthValue = 460,
    .heightValue = 110
};

FlexLayout titleChildrenLayout{
    .direction = FlexDirection::Column,
    .spacing = 6,
    .horizontalAlignment = Alignment::Center,
    .verticalAlignment = Alignment::Center
};

        titlePanel = canvas.add<Panel>(titleLayout, titleChildrenLayout);
        titlePanel->add<Label>(labelLayout, "LUNAR LANDER", GOLD, 42);
        titlePanel->add<Label>(labelLayout, "A raylib moonshot", LIGHTGRAY, 14);

        Layout menuLayout{
    .width = SizeMode::Fixed,
    .height = SizeMode::Fixed,
    .widthValue = 300,
    .heightValue = 220
};

FlexLayout menuChildrenLayout{
    .direction = FlexDirection::Column,
    .padding = 20,
    .spacing = 12,
    .horizontalAlignment = Alignment::Center,
    .verticalAlignment = Alignment::Center
};

        menuPanel = canvas.add<Panel>(menuLayout, menuChildrenLayout);

        Layout footerLayout{
    .width = SizeMode::Fixed,
    .height = SizeMode::Fixed,
    .widthValue = 300,
    .heightValue = 36,
    .offsetY = -10
};

FlexLayout footerChildrenLayout{
    .direction = FlexDirection::Row,
    .padding = 8,
    .spacing = 24,
    .horizontalAlignment = Alignment::Center,
    .verticalAlignment = Alignment::Center
};

        footerPanel = canvas.add<Panel>(footerLayout, footerChildrenLayout);
      }

void MainMenuScreen::init(int w, int h) {
  onResize(w, h);

  startButton = menuPanel->add<Button>(buttonLayout, "Start Flight");
  settingsButton = menuPanel->add<Button>(buttonLayout, "Settings");
  quitButton = menuPanel->add<Button>(buttonLayout, "Quit");

  footerPanel->add<Label>(labelLayout, "v1.0.0", DARKGRAY, 14);
  footerPanel->add<Label>(labelLayout, "FUEL: FULL", GREEN, 14);
}

void MainMenuScreen::draw() {
  DrawRectangleGradientV(0, 0, w, h, (Color){8, 10, 28, 255}, (Color){20, 26, 60, 255});
  canvas.draw();
}

void MainMenuScreen::update(float dt) {
  if (startButton && startButton->isClicked()) {
    manager->startGame(w, h);
    return;
  }

  if (quitButton && quitButton->isClicked())
    manager->stop();

  canvas.update();
}

void MainMenuScreen::reset() {
  init(w, h);
}

void MainMenuScreen::onResize(float w, float h) {
  canvas.setBounds({0, 0, w, h});
}