#pragma once
#include "widget.h"

class Tag : public Widget
{
	std::string tagName;
	float frameX, frameY;
public:
	void draw() override;
	void setFrameX(float x) { frameX = x; }
	void setFrameY(float y) { frameY = y; }
	void setTagName(std::string tag) { tagName = tag; }
	float getFrameX() { return frameX; }
	float getFrameY() { return frameY; }
	std::string getTagName() { return tagName; }
	Tag();
};