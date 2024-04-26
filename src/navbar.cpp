#include "navbar.h"

void Navbar::draw()
{
	graphics::Brush br;
	br.outline_opacity = 0.0f; 
	SETCOLOR(br.fill_color, 0.2f, 0.4f, 0.4f);
	br.fill_opacity = 1.0f;
	graphics::drawRect(posX, posY, width, height, br);
}

Navbar::Navbar()
{
}
