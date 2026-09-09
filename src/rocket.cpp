#include "rocket.hpp"
#include <raylib.h>
#include <cmath>

#include <stdio.h>
#include <iostream>

Rocket::Rocket(std::string name, float x, float y, float w, float h,
               Texture2D* tex, Color color)
    : Entity(name, x, y, w, h, tex, color),
      fuel(maxFuel) {
} 

template <size_t N>
bool isAnyKeyDown(const std::array<int, N>& keys) {
    for (int key : keys) {
        if (IsKeyDown(key))
            return true;
    }

    return false;
}

void Rocket::drawThrustVisual() {
    if (!flying)
        return;

    Vector2 pos = getPos();
    Vector2 size = getSize();
    float rot = getRotation();

    float distance = size.y / 2.0f + thrustVisualSize.y / 2.0f;

    Vector2 offset = {
        -sinf(rot * DEG2RAD) * distance,
         cosf(rot * DEG2RAD) * distance
    };

    Vector2 thrustPos = {
        pos.x + offset.x,
        pos.y + offset.y
    };

    DrawRectanglePro(
        {
            thrustPos.x,
            thrustPos.y,
            thrustVisualSize.x,
            thrustVisualSize.y
        },
        {
            thrustVisualSize.x / 2.0f,
            thrustVisualSize.y / 2.0f
        },
        rot,
        thrustVisualColor
    );
}
int Rocket::draw() {
  Vector2 pos = getPos();
  Vector2 size = getSize();
  Entity::draw();
  drawThrustVisual();
  fuelBar.draw(fuel, maxFuel);
  return 1;
}



void Rocket::steer(float dt, float steerPower) {
  setRotation(getRotation()+steerPower*dt);

}

void Rocket::input(float dt) {

  if(isAnyKeyDown(flyKeys)) { Rocket::fly(dt); }
  else { flying = false;}
  if(!rocketLanded) {
    if(isAnyKeyDown(leftKeys)) { Rocket::steer(dt, -rotationPower); }
    if(isAnyKeyDown(rightKeys)) { Rocket::steer(dt, rotationPower); }
  }
    
}

float Rocket::getFuel() const {
  return fuel;
}

void Rocket::setFuel(float newFuel) {
  fuel = newFuel;
}


void Rocket::fly(float dt) {
  if(fuel>0.0f && !rocketLanded) {
    float rad = getRotation() * DEG2RAD;
    Vector2 force = {
      sinf(rad),
      -cosf(rad)
    };

    velocity.y += force.y * thrustPower * dt;
    velocity.x += force.x * thrustPower * dt;

    fuel -= fuelDeprecation * dt;

    flying = true;
  }

}

bool Rocket::hasLanded() const { return rocketLanded; }
bool Rocket::playerWon() const { return rocketLandedSmoothly; }

void Rocket::update(float dt) {
  velocity.y += gravity * dt;
  
  if (velocity.y > terminalVelocity)
      velocity.y = terminalVelocity;
  if (velocity.y < -terminalVelocity)
    velocity.y = -terminalVelocity;
  setPos(getPos().x + velocity.x * dt, getPos().y + velocity.y * dt);
}

void Rocket::onResize(int newW, int newH) {
  fuelBar.setBarRect(fuelBarRect(newW, newH));
  w = newW;
  h = newH;
}

void Rocket::checkIfWinCondition() {
  if(velocity.y<winVelocityCap) {
    rocketLandedSmoothly = true;
  }
}

void Rocket::onCollision(Entity& other) {
    if (other.getType() == EntityType::Platform) {
        if(!rocketLanded) {
          checkIfWinCondition();
          if(rocketLandedSmoothly) {
            std::cout << "Player won" << std::endl;
          }
          else {
            std::cout << "Player lost" << std::endl;
          }
        } 
        rocketLanded = true;
        Rectangle platform = other.getBounds();
        Rectangle rocket = getBounds();

        Vector2 pos = getPos();

        float newY = platform.y - rocket.height / 2.0f;

        setPos(pos.x, newY);
        velocity.y = 0.0f;
        velocity.x *= 0.8f;
    }
}
