#include "game/screens/mainMenu/mainMenuScreen.hpp"
#include "ui/Button.hpp"
#include "ui/Label.hpp"
#include "ui/VBox.hpp"
#include "engine/core/manager/gameManager.hpp"

namespace game {

void MainMenuScreen::init(int w, int h) {
  GuiSetStyle(DEFAULT, TEXT_PADDING, 16);

  auto testPanel = std::make_unique<ui::VBox>();
  auto button = std::make_unique<ui::Button>(buttonText);
  btn = button.get();
  btn->setOnClick([this]() { uiDirty = true; });
  testPanel->add(std::move(button));
  canvas.add(std::move(testPanel));

  onResize(w, h);
}

void MainMenuScreen::draw() {
  ClearBackground(WHITE);

  canvas.draw();
}

void MainMenuScreen::update(float dt) {
  canvas.update();

  if (uiDirty) {
    uiDirty = false;
    btn->setText(buttonText);
    layout.calculate(canvas);
  }
}

void MainMenuScreen::reset() {
  init(w, h);
}

void MainMenuScreen::onResize(float w, float h) {
  canvas.getLayout().width = w;
  canvas.getLayout().height = h;

  layout.calculate(canvas);
}

} // namespace game
