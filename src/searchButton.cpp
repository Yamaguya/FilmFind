#include "searchButton.h"

void SearchButton::draw()
{
	graphics::Brush br;

	br.outline_opacity = 0.0f;
	br.fill_opacity = 0.2f;
	SETCOLOR(br.fill_color, 0.4, 0.4, 0.4);
	graphics::drawRect(posX, posY, width, height, br);

	br.fill_opacity = 0.8f;
	br.texture = std::string(ASSET_PATH) + "search.png";
	graphics::drawRect(posX, posY, 30, 30, br);
}

SearchButton::SearchButton()
{
}
