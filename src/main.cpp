#include <memory>

#include <engine/core/game.hpp>
#include <engine/core/manager/gameManager.hpp>

#include "game/screens/mainMenu/mainMenuScreen.hpp"

int main()
{
    GameManager manager;
    Game game("Lunar Lander", 1280, 720, manager);
    manager.init(std::make_unique<MainMenuScreen>(1280, 720));

    game.run();

    return 0;
}
