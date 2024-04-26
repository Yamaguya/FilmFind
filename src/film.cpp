#include "film.h"

Film::Film(std::string title, std::string director, std::string actors, std::string genre, std::string year, std::string thumb, std::string description, std::list<std::string> screencaps)
{
	this->title = title;
	this->director = director;
	this->actors = actors;
	this->genre = genre;
	this->year = year;
	this->thumb = thumb;
	this->description = description;
	this->screencaps = screencaps;
}

Film::Film() {

}