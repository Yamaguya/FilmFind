#pragma once
#include "widget.h"

class Button : public Widget
{
	std::string name;
	int deg;
public:
	std::string getName() { return name; }
	void rotate();
	void draw(std::string name);
	void draw() override;
	Button(std::string name);
	Button();
};