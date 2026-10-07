#include <memory>

#include <engine/core/game.hpp>
#include <engine/core/manager/gameManager.hpp>

#include "game/screens/mainMenu/mainMenuScreen.hpp"

int main()
{
    engine::GameManager manager;
    engine::Game game("Lunar Lander", 1280, 720, manager);
    manager.init(std::make_unique<game::MainMenuScreen>(1280, 720));

    game.run();

    return 0;
}
