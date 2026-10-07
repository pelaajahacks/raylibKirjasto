#pragma once

#include "engine/entities/entity.hpp"

class RocketPlatform : public engine::Entity {
  public:
    RocketPlatform(Rectangle rect);
    engine::EntityType getType() const override {
      return engine::EntityType::Platform;
    }

  private:

};
