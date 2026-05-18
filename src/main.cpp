#include <game.hpp>

int main()
{
    Game game("My Raylib Game", 1280, 720);

    game.spawnEntity("player", nullptr, 100, 100, 50, 50, RED);
    game.run();

    return 0;
}
