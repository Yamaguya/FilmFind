#include "filmDetails.h"

void FilmDetails::draw()
{
	graphics::Brush br;

	br.fill_opacity = 1.0f;
	SETCOLOR(br.fill_color, 1.0f, 0.1f, 0.1f);
	graphics::drawText(posX, posY, textHeight, title, br);

	br.fill_opacity = 1.0f;
	SETCOLOR(br.fill_color, 1.0f, 0.1f, 0.1f);
	graphics::drawText(posX, posY + textHeight, textHeight, director, br);

	br.fill_opacity = 1.0f;
	SETCOLOR(br.fill_color, 1.0f, 0.1f, 0.1f);
	graphics::drawText(posX, posY + (textHeight*2), textHeight, actors, br);

	br.fill_opacity = 1.0f;
	SETCOLOR(br.fill_color, 1.0f, 0.1f, 0.1f);
	graphics::drawText(posX, posY + (textHeight * 3), textHeight, year, br);

	float i = 0;
	while (i <= description.length())
	{
		br.fill_opacity = 1.0f;
		SETCOLOR(br.fill_color, 1.0f, 0.1f, 0.1f);
		graphics::drawText(posX, posY + (textHeight * 4) + ((i/ 65)*textHeight), textHeight - 5, description.substr(i, 65), br);
		i += 65;
	}
}

FilmDetails::FilmDetails(std::string title, std::string director, std::string actors, std::string year, std::string description)
{
	this->title = title;
	this->director = director;
	this->actors = actors;
	this->year = year;
	this->description = description;
}

FilmDetails::FilmDetails()
{
}
