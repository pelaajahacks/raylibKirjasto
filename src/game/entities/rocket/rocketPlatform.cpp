#include "game/entities/rocket/rocketPlatform.hpp"

RocketPlatform::RocketPlatform(Rectangle rect)
    : engine::Entity("", rect.x, rect.y, rect.width, rect.height, nullptr, BLACK)
{
}
