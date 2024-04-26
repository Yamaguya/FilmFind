#pragma once
#include "navbar.h"

class SearchBar : public Navbar
{
protected:
	bool searchClicked = false;
public:
	void draw() override;
	void setSearchClicked(bool clicked) { searchClicked = clicked; } // If clicked the Search placeholder text is erased
	bool getSearchClicked() { return searchClicked; }
	SearchBar();
};