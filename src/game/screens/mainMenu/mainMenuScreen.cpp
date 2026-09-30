#include "game/screens/mainMenu/mainMenuScreen.hpp"
#include "ui/Button.hpp"
#include "ui/Label.hpp"
#include "engine/core/manager/gameManager.hpp"

void MainMenuScreen::init(int w, int h) {
  canvas.add(std::make_unique<Button>("Testing"));
  canvas.add(std::make_unique<Button>("Testing"));
  canvas.add(std::make_unique<Button>("Testing"));
  canvas.add(std::make_unique<Button>("Testing"));
  canvas.add(std::make_unique<Button>("Testing"));
  canvas.add(std::make_unique<Button>("Testing"));
  canvas.add(std::make_unique<Button>("Testing"));
  canvas.add(std::make_unique<Button>("Testing"));
  canvas.add(std::make_unique<Button>("Testing"));
  canvas.add(std::make_unique<Button>("Testing"));
  canvas.add(std::make_unique<Button>("Testing"));
  canvas.add(std::make_unique<Button>("Testing"));
  canvas.add(std::make_unique<Button>("Testing"));
  canvas.add(std::make_unique<Button>("Testing"));
  canvas.add(std::make_unique<Button>("Testing"));
  canvas.add(std::make_unique<Button>("Testing"));
  canvas.add(std::make_unique<Button>("Testing"));
  canvas.add(std::make_unique<Button>("Testing"));
  canvas.add(std::make_unique<Button>("Testing"));
  canvas.add(std::make_unique<Button>("Testing"));
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
