#include <memory>

#include <engine/core/game.hpp>
#include <engine/core/manager/gameManager.hpp>

#include "game/screens/mainMenu/mainMenuScreen.hpp"

int main()
{
    engine::GameManager manager;

    // Game calls InitWindow, so it has to exist before the first state:
    // GameManager refuses states before that, because widgets measure text
    // against a font that only exists once there is a window.
    engine::Game game("Lunar Lander", 1280, 720, manager);

    manager.init(std::make_unique<MainMenuScreen>(1280, 720));

    game.run();

    return 0;
}
