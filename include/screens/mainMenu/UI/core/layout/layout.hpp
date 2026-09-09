#pragma once

#include <memory>


enum class SizeMode {
    Fixed,
    FitContent,
    Fill
};

enum class Alignment {
    Start,
    Center,
    End
};

struct Layout {
    SizeMode width = SizeMode::Fixed;
    SizeMode height = SizeMode::Fixed;

    float widthValue = 0.0f;
    float heightValue = 0.0f;

    float padding = 0.0f;
    float spacing = 0.0f;

    Alignment alignment = Alignment::Start;
};
