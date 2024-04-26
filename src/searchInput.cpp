#include "searchInput.h"
#include <iostream>

std::string SearchInput::getSearchText()
{
	search = "";
	for (auto term : searchTerms)
		search += term;
	return search;
}

void SearchInput::searchText(std::string term)
{
	if (term.compare("space") == 0)
		this->searchTerms.push_back(" ");
	else if (term.compare("erase") == 0)
	{
		if (!searchTerms.empty())
			this->searchTerms.pop_back();
	}
	else
		this->searchTerms.push_back(term);
}

void SearchInput::draw()
{
	graphics::Brush br;
	if (!searchTerms.empty())
	{
		for (auto term : searchTerms)
		{
			SETCOLOR(br.fill_color, 1.0f, 1.0f, 1.0f);
			SETCOLOR(br.outline_color, 1.0f, 1.0f, 1.0f);
			graphics::drawText(posX + textShift, posY + 10, 20, term, br);
			textShift = textShift + 10;
		}
	}
	textShift = 5;
}

SearchInput::SearchInput()
{
}
