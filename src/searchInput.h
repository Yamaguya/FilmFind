#pragma once
#include "searchBar.h"
#include <list>

class SearchInput : public SearchBar
{
	int textShift = 5;
	std::list<std::string> searchTerms;
	std::string search;
public:
	std::string getSearchText();
	void searchText(std::string term);
	void draw();

	SearchInput();
};