#pragma once
#include "config.h"
#include "graphics.h"
#include "film.h"
#include <list>
#include <iostream>
#include <fstream>
#include <string>

class FilmParser
{
	std::list<Film*> m_films;
    std::list<std::string> screencaps;
public:
	std::list<Film*> getFilms();
	void init();
	FilmParser();
};