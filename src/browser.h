#pragma once
#include "config.h"
#include "graphics.h"
#include "filmParser.h"
#include "film.h"
#include "filmDetails.h"
#include "screencapPreview.h"
#include "thumbnail.h"
#include "button.h"
#include "searchBar.h"
#include "searchInput.h"
#include "searchButton.h"
#include "tag.h"
#include "dateBar.h"
#include "genreBar.h"
#include <list>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <set>
#include <algorithm>
#include <windows.h>

class Browser
{
	static Browser* m_instance;

	std::list<Thumbnail*> m_thumbs;
	std::list<std::list<Tag*>> m_tags;
	std::list<Button*> genreButtons;
	std::list<Button*> decadeButtons;
	std::set<std::string> genres;
	std::set<std::string> decades;
	std::list<Film*> films;
	std::list<FilmDetails*> m_details;
	std::string thumbName;
	std::list<ScreencapPreview*> m_screens;

	Button* leftButton;
	Button* rightButton;
	Navbar* navbar;
	DateBar* datebar;
	GenreBar* genrebar;
	SearchBar* search;
	SearchInput* searchIn;
	SearchButton* searchBut;
	Button* genreButton;
	Button* decadeButton;
	Tag* tag;

	bool caps = false;
	bool searchInput = false; // If true then it starts registering the typing

	std::list<Tag*> tagList;
	std::list<std::string> tags;

	Browser() {}
public:
	void draw();
	bool mouseHover(float leftx, float rightx, float topy, float boty);
	void filterTitle(std::string filter);
	void filterGenre(std::string filter);
	void filterDate(std::string filter);
	void keyReg();
	void update();
	void init();

	~Browser();

	static Browser* getInstance();
};