#pragma once

#include "screens/mainMenu/UI/core/UIElement.hpp"
#include "screens/mainMenu/UI/core/layout/layout.hpp"
#include <vector>
#include <memory>


class Panel : public UIElement {
public:
    Panel(Rectangle bounds, Layout layout);

    void add(std::unique_ptr<UIElement> child);

    void update() override;
    void draw() override;

private:
    Layout layout;

    std::vector<std::unique_ptr<UIElement>> children;
};
