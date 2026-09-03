#include "rocket.hpp"
#include <raylib.h>
#include <cmath>

Rocket::Rocket(std::string name, float x, float y, float w, float h,
               Texture2D* tex, Color color)
    : Entity(name, x, y, w, h, tex, color),
      fuel(maxFuel) {
} 

template <size_t N>
bool isAnyKeyDown(const std::array<int, N>& keys)
{
    for (int key : keys)
    {
        if (IsKeyDown(key))
            return true;
    }

    return false;
}

int Rocket::draw() {
  Entity::draw();
  fuelBar.draw(fuel, maxFuel);
  return 1;
}



void Rocket::steer(float dt, float steerPower) {
  setRotation(getRotation()+steerPower*dt);

}

void Rocket::input(float dt) {

  if(isAnyKeyDown(flyKeys)) { Rocket::fly(dt); }
  if(isAnyKeyDown(leftKeys)) { Rocket::steer(dt, -rotationPower); }
  if(isAnyKeyDown(rightKeys)) { Rocket::steer(dt, rotationPower); }
    
}

float Rocket::getFuel() const {
  return fuel;
}

void Rocket::setFuel(float newFuel) {
  fuel = newFuel;
}


void Rocket::fly(float dt)
{
  if(fuel>0.0f) {
    float rad = getRotation() * DEG2RAD;
    Vector2 force = {
      sinf(rad),
      -cosf(rad)
    };

    velocity.y += force.y * thrustPower * dt;
    velocity.x += force.x * thrustPower * dt;

    fuel -= fuelDeprecation * dt;
  }

}

void Rocket::update(float dt) {
  velocity.y += gravity * dt;
  
  if (velocity.y > terminalVelocity)
      velocity.y = terminalVelocity;
  if (velocity.y < -terminalVelocity)
    velocity.y = -terminalVelocity;
  setPos(getPos().x + velocity.x * dt, getPos().y + velocity.y * dt);
}

void Rocket::onResize(int w, int h) {
  fuelBar.setBarRect(fuelBarRect(w, h));
}
