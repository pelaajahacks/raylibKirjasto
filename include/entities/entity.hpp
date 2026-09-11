#pragma once

#include <entities/extra/nametag.hpp>
#include <string>
#include <raylib.h>
#include <string>
#include <vector>

enum class EntityType {
    Entity,
    Rocket,
    Platform
};

class Entity {
  public:
    Entity(std::string name, float x, float y, float w, float h, Texture2D* tex = nullptr, Color color = RED);
    virtual EntityType getType() const {
        return EntityType::Entity;
    }

    bool isPlayer = false;
    float speed = 400.0f;

    bool isAlive() const;

    std::string getName() const;
    Vector2 getPos() const;
    Vector2 getSize() const;

    int setPos(float x, float y);
    int destroy();


    Color getColor() const;
    int setColor(Color color);

    float getRotation() const;
    void setRotation(float rot);

    virtual int draw();
    Nametag& getNametag();
    virtual void input(float dt);
    virtual void update(float dt);
    virtual bool playerWon() const;
    bool checkWindowCollisions(int w, int h);

    virtual void onResize(int w, int h) {}

    Rectangle getBounds() const;

    bool collidesWith(const Entity& other) const;
    virtual void onCollision(Entity& other) {}

    static constexpr float gravity = 750.0f;
    static constexpr float terminalVelocity = 1250.0f;





  private:
    bool alive = true;
    Rectangle rect;
    std::string name = "entity";
    Texture2D* texture;
    Color color;
    float rotation = 0.0f;

    Nametag nametag;
};
