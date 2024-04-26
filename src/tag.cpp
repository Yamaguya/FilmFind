#include "tag.h"

void Tag::draw()
{
	graphics::Brush br;

	SETCOLOR(br.outline_color, 0.9f, 0.9f, 0.9f);
	br.outline_opacity = 1.0f;
	br.fill_opacity = 0.0f;
	graphics::drawRect(frameX, frameY, width, height, br);

	br.fill_opacity = 0.8f;
	SETCOLOR(br.fill_color, 0.9f, 0.9f, 0.9f);
	graphics::drawText(posX + 2, posY - 5, height, tagName, br);
}

Tag::Tag()
{
}
