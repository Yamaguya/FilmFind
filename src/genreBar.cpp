#include "genreBar.h"

void GenreBar::draw(std::set<std::string> genres)
{
	graphics::Brush br;
	br.outline_opacity = 0.0f;
	SETCOLOR(br.outline_color, 0.9f, 0.9f, 0.9f);
	SETCOLOR(br.fill_color, 0.2f, 0.4f, 0.4f);
	br.fill_opacity = 0.5f;
	graphics::drawRect(posX, posY + (height / 2) + (hoverHeight / 2), width, hoverHeight, br);
	
	float i = 0;
	for (auto genre : genres)
	{
		br.outline_opacity = 0.9f;
		SETCOLOR(br.outline_color, 0.9f, 0.9f, 0.9f);
		SETCOLOR(br.fill_color, 0.2f, 0.5f, 0.5f);
		br.fill_opacity = 0.5f;
		graphics::drawRect(posX, posY + height + (hoverHeight * (i / genres.size())), width, hoverHeight / genres.size(), br);
		i++;
	}
}

void GenreBar::draw()
{
	graphics::Brush br;

	br.outline_opacity = 0.1f;
	SETCOLOR(br.fill_color, 0.2f, 0.4f, 0.4f);
	br.fill_opacity = 0.4f;
	graphics::drawRect(posX, posY, width, height, br);

	br.outline_opacity = 1.0f;
	SETCOLOR(br.fill_color, 0.9f, 0.8f, 0.4f);
	graphics::drawText(posX - (textHeight / 2), posY + (textHeight/2), 20, "Genre", br);
}

GenreBar::GenreBar()
{
}
