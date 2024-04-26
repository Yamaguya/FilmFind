#include "thumbnail.h"

bool foreground;

void Thumbnail::draw()
{
	graphics::Brush br;
	br.outline_opacity = 0.7f;
	SETCOLOR(br.outline_color, 0.4f, 0.8f, 0.4f);
	br.texture = std::string(THUMB_PATH) + thumbName;
	graphics::drawRect(posX, posY, width, height, br);
}

Thumbnail::Thumbnail(std::string thumbN, float driftX, float driftY, bool foreground)
{
	driftX = CANVAS_WIDTH / 2;
	driftY = CANVAS_HEIGHT / 2;
	this->thumbName = thumbN;
	this->posX = driftX;
	this->posY = driftY;
}

Thumbnail::Thumbnail()
{
}
