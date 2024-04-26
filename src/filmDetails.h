#pragma once
#include "widget.h"

class FilmDetails : public Widget
{
	float textHeight = 25;
	std::string title, director, actors, year, description;
public:
	void draw() override;
	FilmDetails(std::string title, std::string director, std::string actors, std::string year, std::string description);
	FilmDetails();
};