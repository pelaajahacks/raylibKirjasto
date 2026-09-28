#pragma once

#include "engine/entities/entity.hpp"

class RocketPlatform : public Entity {
  public:
    RocketPlatform(Rectangle rect);
    EntityType getType() const override {
      return EntityType::Platform;
    }

  private:

};
