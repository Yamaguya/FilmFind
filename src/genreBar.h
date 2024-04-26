#pragma once
#include "navbar.h"

class GenreBar : public Navbar
{
	std::string decade;
public:
	void draw(std::set<std::string> genres);
	void draw() override;

	GenreBar();
};