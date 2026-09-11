#include "screens/mainMenu/UI/containers/panel.hpp"

#include <algorithm>
Panel::Panel(Layout layout, FlexLayout flexLayout)
    : UIElement({0, 0, 0, 0}, layout),
      flexLayout(flexLayout)
{
    lay_init_context(&ctx);
    lay_reserve_items_capacity(&ctx, 256);
}

void Panel::runLayout()
{
    lay_reset_context(&ctx);

    layoutId = lay_item(&ctx);

    lay_set_size_xy(
        &ctx,
        layoutId,
        static_cast<int>(bounds.width),
        static_cast<int>(bounds.height)
    );

    lay_set_contain(
        &ctx,
        layoutId,
        flexLayout.direction == FlexDirection::Row
            ? LAY_ROW
            : LAY_COLUMN
    );

    for (auto& child : children)
        createChildLayout(*child);

    lay_run_context(&ctx);

    for (auto& child : children) {
        lay_vec4 r = lay_get_rect(&ctx, child->getLayoutId());

        Rectangle childBounds{
            static_cast<float>(r[0]),
            static_cast<float>(r[1]),
            static_cast<float>(r[2]),
            static_cast<float>(r[3])
        };

        childBounds.x += bounds.x;
        childBounds.y += bounds.y;

        child->setBounds(childBounds);
    }
}
void Panel::draw() {
    runLayout();

    GuiPanel(bounds, nullptr);

    for (auto& child : children)
        child->draw();
}

void Panel::createChildLayout(UIElement& child)
{
    lay_id id = lay_item(&ctx);

    child.setLayoutId(id);

    lay_insert(&ctx, layoutId, id);

    const Layout& layout = child.getLayout();

    if (layout.width == SizeMode::Fixed &&
        layout.height == SizeMode::Fixed) {
        lay_set_size_xy(
            &ctx,
            id,
            static_cast<int>(layout.widthValue),
            static_cast<int>(layout.heightValue)
        );
    }
}
