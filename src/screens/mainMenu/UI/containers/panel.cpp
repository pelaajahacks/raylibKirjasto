#include "screens/mainMenu/UI/containers/panel.hpp"
#include "raylib.h"

Panel::Panel(Rectangle bounds, Layout layout) : layout(layout) {
    this->bounds = bounds;
}

void Panel::add(std::unique_ptr<UIElement> child) {
    children.push_back(std::move(child));
}

void Panel::update() {
    float contentWidth = 0;
    float contentHeight = 0;

    for (auto& child : children) {
        Rectangle childBounds = child->getBounds();
        contentWidth = std::max(contentWidth, childBounds.width);
        contentHeight += childBounds.height;
    }

    if (!children.empty())
        contentHeight += layout.spacing * (children.size() - 1);

    if (layout.width == SizeMode::Fixed)
        bounds.width = layout.widthValue;
    else if (layout.width == SizeMode::FitContent)
        bounds.width = contentWidth + layout.padding * 2;
    else if (layout.width == SizeMode::Fill)
        bounds.width = GetScreenWidth();

    if (layout.height == SizeMode::Fixed)
        bounds.height = layout.heightValue;
    else if (layout.height == SizeMode::FitContent)
        bounds.height = contentHeight + layout.padding * 2;
    else if (layout.height == SizeMode::Fill)
        bounds.height = GetScreenHeight();

    float y = bounds.y + layout.padding;

    for (auto& child : children) {
        Rectangle childBounds = child->getBounds();

        if (layout.alignment == Alignment::Start)
            childBounds.x = bounds.x + layout.padding;
        else if (layout.alignment == Alignment::Center)
            childBounds.x = bounds.x + (bounds.width - childBounds.width) / 2.0f;
        else if (layout.alignment == Alignment::End)
            childBounds.x = bounds.x + bounds.width - childBounds.width - layout.padding;

        childBounds.y = y;

        child->setBounds(childBounds);
        child->update();

        y += childBounds.height + layout.spacing;
    }
}

void Panel::draw() {
    DrawRectangleRec(bounds, DARKGRAY);

    for (auto& child : children)
        child->draw();
}
