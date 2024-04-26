#include "screencapPreview.h"

void ScreencapPreview::draw()
{
	graphics::Brush br;
	
	br.outline_opacity = 0.7f;
	br.outline_width = 1;
	SETCOLOR(br.outline_color, 1.0f, 0.5f, 0.0f);
	br.texture = std::string(SCREENCAP_PATH) + screencaps.front();
	graphics::drawRect(posX, posY, width, height, br);
}

void ScreencapPreview::next()
{
	screencaps.push_back(screencaps.front());
	screencaps.pop_front();
}

void ScreencapPreview::previous()
{
	screencaps.push_front(screencaps.back());
	screencaps.pop_back();
}

bool ScreencapPreview::getFullscreen()
{
	return this->fullscreen;
}

bool ScreencapPreview::sizeAdjust()
{
	if (!fullscreen)
	{
		this->fullscreen = true;
	}
	else
	{
		this->fullscreen = false;
	}
	return fullscreen;
}

ScreencapPreview::ScreencapPreview(std::list<std::string> screens)
{
	this->screencaps = screens;
}

ScreencapPreview::ScreencapPreview()
{
}