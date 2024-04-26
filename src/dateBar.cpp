#include "dateBar.h"

void DateBar::draw(std::set<std::string> decades)
{
	graphics::Brush br;
	br.outline_opacity = 0.0f;
	SETCOLOR(br.outline_color, 0.9f, 0.9f, 0.9f);
	SETCOLOR(br.fill_color, 0.2f, 0.4f, 0.4f);
	br.fill_opacity = 0.5f;
	graphics::drawRect(posX, posY + (height / 2) + (hoverHeight / 2), width, hoverHeight, br);

	float i = 0;
	for (auto decade : decades)
	{
		br.outline_opacity = 0.9f;
		SETCOLOR(br.outline_color, 0.9f, 0.9f, 0.9f);
		SETCOLOR(br.fill_color, 0.2f, 0.5f, 0.5f);
		br.fill_opacity = 0.5f;
		graphics::drawRect(posX, posY + height + (hoverHeight * (i / decades.size())), width, hoverHeight / decades.size(), br);
		i++;
	}
}

void DateBar::draw()
{
	graphics::Brush br;

	br.outline_opacity = 0.1f;
	SETCOLOR(br.outline_color, 0.4f, 0.5f, 0.9f);
	SETCOLOR(br.fill_color, 0.2f, 0.4f, 0.4f);
	br.fill_opacity = 0.4f;
	graphics::drawRect(posX, posY, width, height, br);

	br.outline_opacity = 1.0f;
	SETCOLOR(br.fill_color, 0.9f, 0.8f, 0.4f);
	graphics::drawText(posX - (textHeight / 2), posY + (textHeight / 2), 20, "Decade", br);
}

DateBar::DateBar()
{
}
