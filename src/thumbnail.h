#pragma once
#include "widget.h"

class Thumbnail : public Widget
{
	std::string thumbName;
public:
	void draw() override;
	
	Thumbnail(std::string thumbN, float driftX, float driftY, bool foreground);
	Thumbnail();
};