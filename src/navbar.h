#pragma once
#include "widget.h"
#include <set>

class Navbar : public Widget
{
protected:
	bool hover = false;
	float hoverHeight;
	float textHeight = 20;
public:
	void draw() override;
	void setHoverHeight(float height, float adjust) { hoverHeight = height * adjust; }
	void setHover() 
	{ 
		if (!hover)
			hover = true;
		else
			hover = false;
	}
	float getHoverHeight() { return hoverHeight; }
	bool getHover() { return hover; }
	Navbar();
};