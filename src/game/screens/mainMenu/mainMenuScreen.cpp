#include "game/screens/mainMenu/mainMenuScreen.hpp"
#include "ui/Button.hpp"
#include "ui/Label.hpp"
#include "engine/core/manager/gameManager.hpp"

void MainMenuScreen::init(int w, int h) {
  GuiSetStyle(DEFAULT, TEXT_PADDING, 16);
  canvas.add(std::make_unique<Button>("Haloo"));
  onResize(w, h);
}

void MainMenuScreen::draw() {
  ClearBackground(WHITE);

  canvas.draw();
}

void MainMenuScreen::update(float dt) {
  canvas.update();
}

void MainMenuScreen::reset() {
  init(w, h);
}

void MainMenuScreen::onResize(float w, float h) {
  canvas.getLayout().width = w;
  canvas.getLayout().height = h;

  layout.calculate(canvas);
}
