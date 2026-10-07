#pragma once

#include "engine/utils/text.hpp"

struct ResultStyle {
    const char* text;
    Color color;
};



class Announcement : public engine::Text {
public:
    static constexpr float FONTSIZE = 128.0f;

    static constexpr ResultStyle won{"You Won!", GREEN};
    static constexpr ResultStyle lost{"You Lost!", RED};

    void draw(int w, int h) const override;

    Announcement(bool landedSmoothly)
        : engine::Text(getStyle(landedSmoothly).text, getStyle(landedSmoothly).color, FONTSIZE)
    {}

private:
    static constexpr const ResultStyle& getStyle(bool landedSmoothly) {
        return landedSmoothly ? won : lost;
    }
};
