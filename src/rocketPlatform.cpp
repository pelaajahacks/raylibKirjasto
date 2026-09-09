#include "rocketPlatform.hpp"

RocketPlatform::RocketPlatform(Rectangle rect)
    : Entity("", rect.x, rect.y, rect.width, rect.height, nullptr, BLACK)
{
}
