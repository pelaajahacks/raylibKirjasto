#include "screens/mainMenu/mainMenuScreen.hpp"
#include "screens/mainMenu/UI/elements/button.hpp"
#include "screens/mainMenu/UI/elements/label.hpp"

MainMenuScreen::MainMenuScreen(int w, int h)
    : w(w),
      h(h),
      canvas(
        Layout{
          .width = SizeMode::Fixed,
          .height = SizeMode::Fixed,
          .widthValue = static_cast<float>(w),
          .heightValue = static_cast<float>(h)},
        FlexLayout{}),
      menuPanel(nullptr),
      titlePanel(nullptr){
        Layout menuLayout{
    .width = SizeMode::Fixed,
    .height = SizeMode::Fixed,
    .widthValue = 300,
    .heightValue = 200
};

FlexLayout menuChildrenLayout{
    .direction = FlexDirection::Column,
    .padding = 20,
    .spacing = 10,
    .horizontalAlignment = Alignment::Center,
    .verticalAlignment = Alignment::Center
};

        menuPanel = canvas.add<Panel>(menuLayout, menuChildrenLayout);
      }

void MainMenuScreen::draw() { canvas.draw(); }

void MainMenuScreen::update(float dt) {  }

void MainMenuScreen::init(int w, int h) {
    
  menuPanel->add<Button>(buttonLayout, "Play");
  menuPanel->add<Button>(buttonLayout, "Settings");
  menuPanel->add<Button>(buttonLayout, "Quit");


}
void MainMenuScreen::reset() {
  init(w, h);
}

void MainMenuScreen::onResize(float w, float h) {
  canvas.setBounds({0, 0, w, h});
}
