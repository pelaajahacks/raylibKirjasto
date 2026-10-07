#include "engine/entities/entity.hpp"
#include "extra/bar.hpp"
#include "utils/winloseAnnouncement.hpp"
#include <vector>
#include <raylib.h>
#include <string>
#include <array>
#include <memory>

class Rocket : public engine::Entity
{
public:
    Rocket(std::string name, float x, float y, float w, float h,
           Texture2D* tex = nullptr, Color color = RED);
    engine::EntityType getType() const override {
      return engine::EntityType::Rocket;
    }
    void fly(float dt);
    
    float getFuel() const;
    void setFuel(float newFuel);

    void input(float dt) override;
    void update(float dt) override;

    void steer(float dt, float steerPower);

    int draw() override;
    void drawThrustVisual();
    void onResize(int newW, int newH) override;
    void onCollision(engine::Entity& other) override;

    bool checkIfWinCondition();
    bool playerWon() const override;
    void onLand();

    bool hasLanded() const;

    
    static constexpr float thrustPower = 2000.0f;
    static constexpr float rotationPower = 100.0f;

    static constexpr float maxFuel = 1.0f;
    static constexpr float fuelDeprecation = 1.20f;

    static constexpr float winVelocityCap = 100.0f;

    static constexpr float AUTORESETTIME = 2.0f;

    Vector2 thrustVisualSize = {10, 15};
    Color thrustVisualColor = RED;

private:
    std::unique_ptr<Announcement> announcement;
    bool flying;

    float fuel = maxFuel;
    Bar fuelBar{PURPLE, Fade(BLACK, 0.5f)};

    Vector2 padding = {20.0f, 20.0f};
    Vector2 barWH = {20, 200};

    bool rocketLanded = false;

    bool rocketLandedSmoothly = false;

    // Define the positioning for fuelBar here
    Rectangle fuelBarRect(int w, int h) const {
        return {
            (float)w - padding.x - barWH.x, // x
            (float)h - padding.y - barWH.y,            // y
            barWH.x,            // width
            barWH.y              // height
        };
    }

    Vector2 velocity = {0.0f, 0.0f};
    float rotationVelocity;

    float resetTimer = AUTORESETTIME;

    int w, h;

    const std::array<int, 3> flyKeys  = { KEY_W, KEY_SPACE, KEY_UP };
    const std::array<int, 2>  leftKeys = { KEY_A, KEY_LEFT };
    const std::array <int, 2> rightKeys = { KEY_D, KEY_RIGHT };
};
