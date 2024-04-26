#pragma once
#include "navbar.h"

class DateBar : public Navbar
{
	std::string decade;
public:
	void draw(std::set<std::string> decaddes);
	void draw() override;

	DateBar();
};