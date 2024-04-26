#include "searchBar.h"

void SearchBar::draw()
{
	graphics::Brush br;

	br.outline_opacity = 0.0f;
	SETCOLOR(br.outline_color, 0.5f, 0.5f, 0.5f);
	br.fill_opacity = 0.2f;
	graphics::drawRect(posX, posY, width, height, br);
	
	if (!getSearchClicked())
	{
		br.outline_opacity = 0.0f;
		SETCOLOR(br.outline_color, 0.2f, 0.1f, 0.1f);
		br.fill_opacity = 0.2f;
		graphics::drawRect(posX, posY, width, height, br);

		SETCOLOR(br.fill_color, 1.0f, 1.0f, 1.0f);
		br.fill_opacity = 0.8f;
		SETCOLOR(br.outline_color, 1.0f, 1.0f, 1.0f);
		graphics::drawText(posX - (width / 3), posY + 10, 30, "Search", br);
	}
	else
	{
		br.outline_opacity = 0.8f;
		SETCOLOR(br.outline_color, 0.2f, 0.1f, 0.1f);
		br.fill_opacity = 0.3f;
		graphics::drawRect(posX, posY, width, height, br);
	}
}

SearchBar::SearchBar()
{
}