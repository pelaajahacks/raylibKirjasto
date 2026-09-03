#include "entity.hpp"
#include "bar.hpp"
#include <vector>
#include <raylib.h>
#include <string>
#include <array>

class Rocket : public Entity
{
public:
    Rocket(std::string name, float x, float y, float w, float h,
           Texture2D* tex = nullptr, Color color = RED);
    void fly(float dt);
    
    float getFuel() const;
    void setFuel(float newFuel);

    void input(float dt) override;
    void update(float dt) override;

    void steer(float dt, float steerPower);

    int draw() override;
    void onResize(int w, int h) override;

    static constexpr float gravity = 750.0f;
    static constexpr float terminalVelocity = 1250.0f;

    static constexpr float thrustPower = 2000.0f;
    static constexpr float rotationPower = 100.0f;

    static constexpr float maxFuel = 100.0f;
    static constexpr float fuelDeprecation = 100.0f;

private:
    
    float fuel = maxFuel;
    Bar fuelBar{PURPLE, Fade(BLACK, 0.5f)};

    Vector2 padding = {20.0f, 20.0f};
    Vector2 barWH = {20, 200};

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

    const std::array<int, 3> flyKeys  = { KEY_W, KEY_SPACE, KEY_UP };
    const std::array<int, 2>  leftKeys = { KEY_A, KEY_LEFT };
    const std::array <int, 2> rightKeys = { KEY_D, KEY_RIGHT };
};
