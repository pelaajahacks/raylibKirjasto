#include <memory>

#include <engine/core/game.hpp>
#include <engine/core/manager/gameManager.hpp>

#include "game/screens/mainMenu/mainMenuScreen.hpp"

#include <ui/ui.hpp>

int main()
{
    GameManager manager;
    manager.init(std::make_unique<MainMenuScreen>(1280, 720));
    Game game("Lunar Lander", 1280, 720, manager);
    ui::init();

    game.run();

    return 0;
}
