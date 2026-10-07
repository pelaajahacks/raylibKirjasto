#include "game/screens/mainMenu/mainMenuScreen.hpp"
#include "game/screens/gameScreen.hpp"

MainMenuScreen::MainMenuScreen(int w, int h)
    : w(w),
      h(h) {
}

// Rebuilds the whole menu. GameManager calls reset() the moment a state is
// installed, so this is the entry point for building widgets: they measure
// text against the default font, which does not exist until Game (and its
// InitWindow) has been constructed.
//
// Panel has no way to drop children, so the canvas is thrown away and made
// again instead of appended to -- otherwise every reset would stack another
// Play button on top of the last one.
void MainMenuScreen::init(int w, int h) {
    this->w = w;
    this->h = h;

    canvas = std::make_unique<Panel>(LayoutConfig{
        .width = static_cast<float>(w),
        .height = static_cast<float>(h),
        .mode = LayoutMode::Flex,
        .flex = FlexConfig{
            .justify = Justify::Center,
            .align = Align::Center}});

    auto play = std::make_unique<Button>("Play");
    playButton = play.get();
    canvas->add(std::move(play));

    // Fires from Button::draw(); GameManager::changeState only stashes the new
    // state, StateMachine applies it on the next update -- so the menu is
    // never yanked out from under its own draw call.
    playButton->setOnClick([this]() {
        changeState(std::make_unique<GameScreen>(this->w, this->h));
    });

    layout.calculate(*canvas);
}

void MainMenuScreen::draw() {
    DrawRectangleGradientV(0, 0, w, h, (Color){8, 10, 28, 255}, (Color){20, 26, 60, 255});
    if (canvas)
        canvas->draw();
}

void MainMenuScreen::update(float dt) {
    if (canvas)
        canvas->update();
}

void MainMenuScreen::reset() {
    init(w, h);
}

void MainMenuScreen::onResize(float w, float h) {
    this->w = w;
    this->h = h;

    if (!canvas)
        return;

    LayoutConfig& config = canvas->getLayout();
    config.width = static_cast<float>(w);
    config.height = static_cast<float>(h);
    layout.calculate(*canvas);
}
