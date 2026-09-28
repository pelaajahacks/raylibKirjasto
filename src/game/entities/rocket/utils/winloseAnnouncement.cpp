#include "game/entities/rocket/utils/winloseAnnouncement.hpp"

void Announcement::draw(int w, int h) const
{
    int textWidth = MeasureText(getText().c_str(), FONTSIZE);

    int x = (w - textWidth) / 2;
    int y = (h - FONTSIZE) / 2;

    Text::draw(x, y);
}
