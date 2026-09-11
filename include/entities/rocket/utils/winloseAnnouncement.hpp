#pragma once

#include "utils/text.hpp"

struct ResultStyle {
    const char* text;
    Color color;
};



class Announcement : public Text {
public:
    static constexpr float FONTSIZE = 128.0f;

    static constexpr ResultStyle won{"You Won!", GREEN};
    static constexpr ResultStyle lost{"You Lost!", RED};

    void draw(int w, int h) const override;

    Announcement(bool landedSmoothly)
        : Text(getStyle(landedSmoothly).text, getStyle(landedSmoothly).color, FONTSIZE)
    {}

private:
    static constexpr const ResultStyle& getStyle(bool landedSmoothly) {
        return landedSmoothly ? won : lost;
    }
};
