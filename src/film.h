#pragma once
#include <list>
#include <string>
#include <iostream>

class Film
{
	std::string title;
	std::string director;
	std::string actors;
	std::string genre;
	std::string year;
	std::string thumb;
	std::string description;
	std::list<std::string> screencaps;
	bool foreground;
public:
	std::string getTitle() { return title; }
	std::string getDirector() { return director; }
	std::string getActors() { return actors; }
	std::string getGenre() { return genre; }
	std::string getYear() { return year; }
	std::string getThumb() { return thumb; }
	std::string getDesc() { return description; }
	std::list<std::string> getScreencaps() { return screencaps; }
	bool getForeground() { return foreground; }

	void setTitle(std::string t) { title = t; }
	void setDirector(std::string d) { director = d; }
	void setActors(std::string a) { actors = a; }
	void setGenre(std::string g) { genre = g; }
	void setYear(std::string y) { year = y; }
	void setThumb(std::string th) { thumb = th; }
	void setDesc(std::string desc) { description = desc; }
	void setScreencaps(std::list<std::string> sc) { screencaps = sc; }
	void setForeground(bool fore) { foreground = fore; }

	Film(std::string title, std::string director, std::string actors, std::string genre, std::string year, std::string thumb, std::string description, std::list<std::string>  screencaps);
	Film();
};