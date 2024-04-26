#pragma once
#include "widget.h"
#include <list>

class ScreencapPreview : public Widget
{
	std::list <std::string> screencaps;
	bool fullscreen = false;
public:
	void draw() override;
	void next();
	void previous();
	bool sizeAdjust();
	ScreencapPreview(std::list<std::string> screens);
	ScreencapPreview();
};