#include "screens/mainMenu/mainMenuScreen.hpp"
#include "screens/mainMenu/UI/elements/button.hpp"

MainMenuScreen::MainMenuScreen(int w, int h) : w(w), h(h), menuPanel({ 490, 285, 300, 150 }, createMenuLayout()) {}

void MainMenuScreen::draw() { menuPanel.draw(); }

void MainMenuScreen::update(float dt) { menuPanel.update(); }

void MainMenuScreen::init(int w, int h) {
    menuPanel.add(std::make_unique<Button>(Rectangle{ 0, 0, 200, 50 }, "Play"));
    menuPanel.add(std::make_unique<Button>(Rectangle{ 0, 0, 200, 50 }, "Settings"));

}
void MainMenuScreen::reset() {
  init(w, h);

}
Layout MainMenuScreen::createMenuLayout() {
    Layout layout;
    layout.width = SizeMode::Fixed;
    layout.height = SizeMode::Fixed;
    layout.widthValue = 300;
    layout.heightValue = 150;
    layout.padding = 20;
    layout.spacing = 10;
    layout.alignment = Alignment::Center;
    return layout;
}
