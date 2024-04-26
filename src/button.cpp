#include "button.h"

void Button::rotate() 
{
	this->deg = 180;
}

void Button::draw(std::string name)
{
	graphics::Brush br;

	br.outline_opacity = 1.0f;
	SETCOLOR(br.fill_color, 0.4f, 0.8f, 0.4f);
	graphics::drawText(posX, posY, height, name, br);
}

void Button::draw()
{
	graphics::Brush br;
	graphics::setOrientation(deg);
	br.outline_opacity = 0.0f;
	br.fill_opacity = 0.7;
	br.texture = std::string(ASSET_PATH) + "arrow.png";
	graphics::drawRect(posX, posY, width, height, br);
	graphics::resetPose();
}

Button::Button(std::string name)
{
	this->name = name;
}

Button::Button()
{
	this->deg = 0;
}
