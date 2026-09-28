#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

#define LAYOUT_IMPLEMENTATION
#include <layout.h>

#include <ui/ui.hpp>

namespace ui {
    void init()
    {
        GuiSetFont(GetFontDefault());
    }
}
