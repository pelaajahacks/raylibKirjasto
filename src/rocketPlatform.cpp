#include "rocketPlatform.hpp"

RocketPlatform::RocketPlatform(Rectangle rect)
    : Entity("Rocket Platform", rect.x, rect.y, rect.width, rect.height, nullptr, BLACK)
{
}
