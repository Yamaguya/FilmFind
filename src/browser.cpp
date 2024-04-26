#include "browser.h"

graphics::MouseState mouse;
void graphics::getMouseState(MouseState& mouse);

void Browser::draw()
{
	graphics::Brush br;
	SETCOLOR(br.fill_color, 0.02f, 0.05f , 0.08f);
	br.fill_opacity = 0.9f;
	br.outline_opacity = 0.0f;
	br.texture = std::string(ASSET_PATH) + "bg.png";
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br); // Draw background
	
	m_screens.front()->draw(); 
	
	if (m_screens.front()->getFullscreen() == false)
	{
		leftButton->draw();
		rightButton->draw();
		navbar->draw();

		if (!datebar->getHover()) // Draw Decade bar
			datebar->draw();
		else
		{
			datebar->draw(decades);
			for (auto d : decadeButtons)
			{
				d->draw(d->getName());
			}
		}

		if (!genrebar->getHover()) // Draw Genre bar
			genrebar->draw();
		else
		{
			genrebar->draw(genres);
			for (auto b : genreButtons)
			{
				b->draw(b->getName());
			}
		}

		search->draw();
		searchIn->draw();
		searchBut->draw();

		m_thumbs.front()->draw();
		m_details.front()->draw();

		for (auto t : m_tags.front())
		{
			t->draw();
		}

	}
}

bool Browser::mouseHover(float leftx, float rightx, float topy, float boty)
{
	graphics::MouseState mouse;
	graphics::getMouseState(mouse);

	if (mouse.cur_pos_x >= leftx &&	mouse.cur_pos_x <= rightx && mouse.cur_pos_y >= topy &&	mouse.cur_pos_y <= boty)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Browser::filterTitle(std::string filter)
{
	std::string flag = films.front()->getTitle();

	std::string lowerFilm = films.front()->getTitle();
	std::transform(lowerFilm.begin(), lowerFilm.end(), lowerFilm.begin(), ::tolower);

	while (true)
	{
		films.push_front(films.back());
		films.pop_back();
		films.front()->setForeground(true);

		m_thumbs.push_front(m_thumbs.back());
		m_thumbs.pop_back();

		m_tags.push_front(m_tags.back());
		m_tags.pop_back();

		m_details.push_front(m_details.back());
		m_details.pop_back();

		m_screens.push_front(m_screens.back());
		m_screens.pop_back();

		lowerFilm = films.front()->getTitle();
		std::transform(lowerFilm.begin(), lowerFilm.end(), lowerFilm.begin(), ::tolower);

		if (lowerFilm.find(filter) != std::string::npos)
			break;

		if (films.front()->getTitle() == flag) // Use break so we don't change the films.front() if it isn't found
		{
			break;
		}
	}
}

void Browser::filterGenre(std::string filter)
{
	while (true) 
	{
		if (films.front()->getGenre().find(filter) != std::string::npos)
			break;
		films.push_front(films.back());
		films.pop_back();

		m_thumbs.push_front(m_thumbs.back());
		m_thumbs.pop_back();

		m_screens.push_front(m_screens.back());
		m_screens.pop_back();

		m_tags.push_front(m_tags.back());
		m_tags.pop_back();

		m_details.push_front(m_details.back());
		m_details.pop_back();
	}
}

void Browser::filterDate(std::string filter)
{
	std::string date = filter.substr(0, 3);
	while (true)
	{
		if (films.front()->getYear().find(date) != std::string::npos)
			break;
		films.push_front(films.back());
		films.pop_back();

		m_thumbs.push_front(m_thumbs.back());
		m_thumbs.pop_back();

		m_screens.push_front(m_screens.back());
		m_screens.pop_back();

		m_tags.push_front(m_tags.back());
		m_tags.pop_back();

		m_details.push_front(m_details.back());
		m_details.pop_back();
	}
}

void Browser::update()
{
	graphics::MouseState mouse;
	graphics::getMouseState(mouse);

	if (searchInput) {
		keyReg();
	}

	if (mouseHover(search->getPosX() - (search->getWidth() / 2), search->getPosX() + (search->getWidth() / 2), 
		search->getPosY() - (search->getHeight() / 2), search->getPosY() + (search->getHeight() / 2)))
	{
		if (mouse.button_left_released)
		{
			search->setSearchClicked(true);
			this->searchInput = true;
		}
		Sleep(10);
	}
	
	if (mouseHover(genrebar->getPosX() - (genrebar->getWidth() / 2), genrebar->getPosX() + (genrebar->getWidth() / 2), 
		genrebar->getPosY() - (genrebar->getHeight() / 2), genrebar->getPosY() + (genrebar->getHeight() / 2)))
	{
		if (!genrebar->getHover())
		{
			genrebar->setHover();
		}

		if (mouse.button_left_released)
		{
			this->searchInput = false;
		}
		Sleep(10);
	}

	if (genrebar->getHover())
	{
		if (mouseHover(genrebar->getPosX() - (genrebar->getWidth() / 2), genrebar->getPosX() + (genrebar->getWidth() / 2),
			genrebar->getPosY() - (genrebar->getHeight() / 2), genrebar->getPosY() + (genrebar->getHeight()/2) + (genrebar->getHoverHeight())))
		{

			for (auto genrebutton : genreButtons)
			{
				if (mouse.cur_pos_y >= genrebutton->getPosY() - (genrebar->getHeight() / 2) &&
					mouse.cur_pos_y <= genrebutton->getPosY() + (genrebar->getHeight() / 2))
				{
					if (mouse.button_left_released)
					{
						filterGenre(genrebutton->getName());
					}
				}
			}
			Sleep(10);
		}
		else
		{
			if (genrebar->getHover())
			{
				genrebar->setHover();
				genrebar->draw();
			}
		}
	}
	
	if (mouseHover(datebar->getPosX() - (datebar->getWidth() / 2), datebar->getPosX() + (datebar->getWidth() / 2), 
		datebar->getPosY() - (datebar->getHeight() / 2), datebar->getPosY() + (datebar->getHeight() / 2)))
	{
		if (!datebar->getHover())
		{
			datebar->setHover();
		}
		if (mouse.button_left_released)
		{
			this->searchInput = false;
		}
		Sleep(10);
	}

	if (datebar->getHover())
	{
		if (mouseHover(datebar->getPosX() - (datebar->getWidth() / 2), datebar->getPosX() + (datebar->getWidth() / 2),
			datebar->getPosY() - (datebar->getHeight() / 2), datebar->getPosY() + (datebar->getHeight()/2) + (datebar->getHoverHeight())))
		{
			for (auto decadeButton : decadeButtons)
			{
				if (mouse.cur_pos_y >= decadeButton->getPosY() - (datebar->getHeight() / 2) &&
					mouse.cur_pos_y <= decadeButton->getPosY() + (datebar->getHeight() / 2))
				{
					if (mouse.button_left_released)
					{
						filterDate(decadeButton->getName());
					}
				}
			}
			Sleep(10);
		}
		else
		{
			if (datebar->getHover())
			{
				datebar->setHover();
				datebar->draw();
			}
		}
	}

	if (mouseHover(searchBut->getPosX() - (searchBut->getWidth() / 2), searchBut->getPosX() + (searchBut->getWidth() / 2), 
		searchBut->getPosY() - (searchBut->getHeight() / 2), searchBut->getPosY() + (searchBut->getHeight() / 2)))
	{
		if (mouse.button_left_released)
		{
			filterTitle(searchIn->getSearchText());
			this->searchInput = false;
		}
		Sleep(10);
	}


	if (mouseHover(m_screens.front()->getPosX() - (m_screens.front()->getWidth() / 2), 
		m_screens.front()->getPosX() + (m_screens.front()->getWidth() / 2), 
		m_screens.front()->getPosY() - (m_screens.front()->getHeight() / 2), 
		m_screens.front()->getPosY() + (m_screens.front()->getHeight() / 2)))
	{
		if (mouse.button_left_released)
		{
			if (m_screens.front()->sizeAdjust()) // If it was regular size then it will now set fullscreen to true 
			{
				m_screens.front()->setPosX(CANVAS_WIDTH / 2);
				m_screens.front()->setPosY(CANVAS_HEIGHT / 2);
				m_screens.front()->setWidth(CANVAS_WIDTH);
				m_screens.front()->setHeight(CANVAS_HEIGHT);
			}
			else // If it was fullscreen then it will now set it to regular size
			{
				m_screens.front()->setPosX(CANVAS_WIDTH * 0.8);
				m_screens.front()->setPosY(CANVAS_HEIGHT * 0.8);
				m_screens.front()->setWidth(CANVAS_WIDTH * 0.18);
				m_screens.front()->setHeight((CANVAS_WIDTH * 0.18) * 0.67);
			}
			m_screens.front()->draw();
		}
		Sleep(10);
	}
	if (mouseHover(leftButton->getPosX() - (leftButton->getWidth() / 2), leftButton->getPosX() + (leftButton->getWidth() / 2), 
		leftButton->getPosY() - (leftButton->getHeight() / 2), leftButton->getPosY() + (leftButton->getHeight() / 2)))
	{
		if (mouse.button_left_released)
		{
			m_screens.front()->previous();
		}
		Sleep(10);
	}
	if (mouseHover(rightButton->getPosX() - (rightButton->getWidth() / 2), rightButton->getPosX() + (rightButton->getWidth() / 2), 
		rightButton->getPosY() - (rightButton->getHeight() / 2), rightButton->getPosY() + (rightButton->getHeight() / 2)))
	{
		if (mouse.button_left_released)
		{
			m_screens.front()->next();
		}
		Sleep(10);
	}

	if (graphics::getKeyState(graphics::SCANCODE_LEFT)) // Pressing left arrow key gets the previous film
	{
		films.push_front(films.back());
		films.pop_back();
		films.front()->setForeground(true);

		m_thumbs.push_front(m_thumbs.back());
		m_thumbs.pop_back();

		m_screens.push_front(m_screens.back());
		m_screens.pop_back();

		m_tags.push_front(m_tags.back());
		m_tags.pop_back();

		m_details.push_front(m_details.back());
		m_details.pop_back();

		Sleep(200);
	}

	if (graphics::getKeyState(graphics::SCANCODE_RIGHT)) // Pressing right arrow key gets the next film
	{
		films.push_back(films.front());
		films.pop_front();
		films.front()->setForeground(true);

		m_thumbs.push_back(m_thumbs.front());
		m_thumbs.pop_front();

		m_screens.push_back(m_screens.front());
		m_screens.pop_front();

		m_tags.push_back(m_tags.front());
		m_tags.pop_front();

		m_details.push_back(m_details.front());
		m_details.pop_front();

		Sleep(200);
	}
}

void Browser::init()
{
	FilmParser* filmParser = new FilmParser();
	std::list<Film*> films = filmParser->getFilms();
	this->films = films;

	for (auto film : films)
	{
		Thumbnail* t = new Thumbnail(film->getThumb(), 0, 0, film->getForeground()); // Initialize thumbnails
		t->setWidth(200);
		t->setHeight(320);
		m_thumbs.push_back(t);

		FilmDetails* md = new FilmDetails(film->getTitle(), film->getDirector(), film->getActors(), film->getYear(), film->getDesc()); // Initialize details
		md->setPosX(t->getPosX() + t->getWidth());
		md->setPosY(t->getPosY() - (t->getHeight()/2));
		md->setWidth(t->getWidth());
		md->setHeight(t->getHeight());
		m_details.push_back(md);

		std::string decade = film->getYear(); // Convert production year to decade
		decade[3] = '0';
		decades.insert(decade + 's');

		std::stringstream sstr(film->getGenre());
		while (sstr)
		{
			std::string substr;
			getline(sstr, substr, ',');
			substr.erase(remove(substr.begin(), substr.end(), ' '), substr.end());
			if (substr.size()>1)
				tags.push_back(substr);
		}

		int i = 0;
		for (auto tt : tags)
		{
			Tag* tag = new Tag(); // Initialize tags
			tag->setTagName(tt);
			tag->setPosX(t->getPosX() + i - (t->getWidth() / 2));
			tag->setPosY(t->getPosY() + (t->getHeight() / 2) + 20);
			tag->setWidth(tt.size() * 10);
			tag->setHeight(20);
			tag->setFrameX(tag->getPosX() + (tag->getWidth() / 2));
			tag->setFrameY(tag->getPosY() - (tag->getHeight() / 2));
			tagList.push_back(tag);
			i = i + (tt.size() * 10);
			std::string::iterator end_pos = std::remove(tt.begin(), tt.end(), ' ');
			tt.erase(end_pos, tt.end());
			genres.insert(tt);
		}
		m_tags.push_back(tagList);
		tags.clear(); // Clear lists for next film
		tagList.clear();

		ScreencapPreview* sc = new ScreencapPreview(film->getScreencaps()); // Initialize screencaps
		sc->setPosX(CANVAS_WIDTH * 0.8);
		sc->setPosY(CANVAS_HEIGHT * 0.8);
		sc->setWidth(CANVAS_WIDTH * 0.18);
		sc->setHeight((CANVAS_WIDTH * 0.18) * 0.67);
		m_screens.push_back(sc);
	}

	Button* lbutton = new Button(); // Initialize left button
	lbutton->setWidth(100);
	lbutton->setHeight(35);
	lbutton->setPosX(m_screens.front()->getPosX() - (m_screens.front()->getWidth() / 2) - (lbutton->getWidth() / 2));
	lbutton->setPosY(m_screens.front()->getPosY());
	this->leftButton = lbutton;

	Button* rbutton = new Button(); // Initialize right button
	rbutton->rotate();
	rbutton->setWidth(100);
	rbutton->setHeight(35);
	rbutton->setPosX(m_screens.front()->getPosX() + (m_screens.front()->getWidth() / 2) + (rbutton->getWidth() / 2));
	rbutton->setPosY(m_screens.front()->getPosY());
	this->rightButton = rbutton;

	Navbar* navbar = new Navbar(); // Initialize navbar
	navbar->setWidth(CANVAS_WIDTH);
	navbar->setHeight(CANVAS_HEIGHT * 0.05);
	navbar->setPosX(CANVAS_WIDTH / 2);
	navbar->setPosY(navbar->getHeight());
	this->navbar = navbar;

	SearchButton* searchBut = new SearchButton(); // Initialize search button
	searchBut->setWidth(navbar->getWidth()/10);
	searchBut->setHeight(navbar->getHeight());
	searchBut->setPosX((navbar->getPosX() + (navbar->getWidth()/2)) - (searchBut->getWidth()/2));
	searchBut->setPosY(navbar->getPosY());
	this->searchBut = searchBut;

	SearchBar* search = new SearchBar(); // Initialize search bar
	search->setWidth((navbar->getWidth() * 0.33) - searchBut->getWidth());
	search->setHeight(navbar->getHeight());
	search->setPosX((navbar->getPosX() + (navbar->getWidth() / 2)) - ((search->getWidth() / 2 + searchBut->getWidth())));
	search->setPosY(navbar->getPosY());
	this->search = search;

	SearchInput* searchIn = new SearchInput(); // Initialize search input
	searchIn->setPosX(search->getPosX() - (search->getWidth() / 2));
	searchIn->setPosY(search->getPosY());
	this->searchIn = searchIn;

	DateBar* datebar = new DateBar(); // Initialize production date bar
	datebar->setWidth(navbar->getWidth() * 0.19);
	datebar->setHeight(navbar->getHeight());
	datebar->setPosX(datebar->getWidth()/2);
	datebar->setPosY(navbar->getPosY());
	datebar->setHoverHeight(datebar->getHeight(), decades.size());
	this->datebar = datebar;

	GenreBar* genrebar = new GenreBar(); // Initialize genre bar
	genrebar->setWidth(navbar->getWidth() * 0.19);
	genrebar->setHeight(navbar->getHeight());
	genrebar->setPosX(datebar->getPosX() + (genrebar->getWidth()));
	genrebar->setPosY(navbar->getPosY());
	genrebar->setHoverHeight(genrebar->getHeight(), genres.size());
	this->genrebar = genrebar;

	graphics::Brush br;
	float i = 0;
	for (auto genre : genres)
	{
		Button* genreButton = new Button(genre);
		genreButton->setHeight(20);
		genreButton->setPosX(genrebar->getPosX());
		genreButton->setPosY(genrebar->getPosY() + genrebar->getHeight() + (genrebar->getHoverHeight() * (i / genres.size())));
		genreButtons.push_back(genreButton);
		i++;
	}

	i = 0;
	for (auto decade : decades)
	{
		Button* decadeButton = new Button(decade);
		decadeButton->setHeight(20);
		decadeButton->setPosX(datebar->getPosX());
		decadeButton->setPosY(datebar->getPosY() + datebar->getHeight() + (datebar->getHoverHeight() * (i / decades.size())));
		decadeButtons.push_back(decadeButton);
		i++;
	}
}

void Browser::keyReg()
{
	if (graphics::getKeyState(graphics::SCANCODE_A))
	{
		searchIn->searchText("a");
		Sleep(50);
		searchIn->draw();
		Sleep(100);
	}
	if (graphics::getKeyState(graphics::SCANCODE_B))
	{
		searchIn->searchText("b");
		Sleep(50);
		searchIn->draw();
		Sleep(100);
	}
	if (graphics::getKeyState(graphics::SCANCODE_C))
	{
		searchIn->searchText("c");
		Sleep(50);
		searchIn->draw();
		Sleep(100);
	}
	if (graphics::getKeyState(graphics::SCANCODE_D))
	{
		searchIn->searchText("d");
		Sleep(50);
		searchIn->draw();
		Sleep(100);
	}
	if (graphics::getKeyState(graphics::SCANCODE_E))
	{
		searchIn->searchText("e");
		Sleep(50);
		searchIn->draw();
		Sleep(100);
	}
	if (graphics::getKeyState(graphics::SCANCODE_F))
	{
		searchIn->searchText("f");
		Sleep(50);
		searchIn->draw();
		Sleep(100);
	}
	if (graphics::getKeyState(graphics::SCANCODE_G))
	{
		searchIn->searchText("g");
		Sleep(50);
		searchIn->draw();
		Sleep(100);
	}
	if (graphics::getKeyState(graphics::SCANCODE_H))
	{
		searchIn->searchText("h");
		Sleep(50);
		searchIn->draw();
		Sleep(100);
	}
	if (graphics::getKeyState(graphics::SCANCODE_I))
	{
		searchIn->searchText("i");
		Sleep(50);
		searchIn->draw();
		Sleep(100);
	}
	if (graphics::getKeyState(graphics::SCANCODE_J))
	{
		searchIn->searchText("j");
		Sleep(50);
		searchIn->draw();
		Sleep(100);
	}
	if (graphics::getKeyState(graphics::SCANCODE_K))
	{
		searchIn->searchText("k");
		Sleep(50);
		searchIn->draw();
		Sleep(100);
	}
	if (graphics::getKeyState(graphics::SCANCODE_L))
	{
		searchIn->searchText("l");
		Sleep(50);
		searchIn->draw();
		Sleep(100);
	}
	if (graphics::getKeyState(graphics::SCANCODE_M))
	{
		searchIn->searchText("m");
		Sleep(50);
		searchIn->draw();
		Sleep(100);
	}
	if (graphics::getKeyState(graphics::SCANCODE_N))
	{
		searchIn->searchText("n");
		Sleep(50);
		searchIn->draw();
		Sleep(100);
	}
	if (graphics::getKeyState(graphics::SCANCODE_O))
	{
		searchIn->searchText("o");
		Sleep(50);
		searchIn->draw();
		Sleep(100);
	}
	if (graphics::getKeyState(graphics::SCANCODE_P))
	{
		searchIn->searchText("p");
		Sleep(50);
		searchIn->draw();
		Sleep(100);
	}
	if (graphics::getKeyState(graphics::SCANCODE_Q))
	{
		searchIn->searchText("q");
		Sleep(50);
		searchIn->draw();
		Sleep(100);
	}
	if (graphics::getKeyState(graphics::SCANCODE_R))
	{
		searchIn->searchText("r");
		Sleep(50);
		searchIn->draw();
		Sleep(100);
	}
	if (graphics::getKeyState(graphics::SCANCODE_S))
	{
		searchIn->searchText("s");
		Sleep(50);
		searchIn->draw();
		Sleep(100);
	}
	if (graphics::getKeyState(graphics::SCANCODE_T))
	{
		searchIn->searchText("t");
		Sleep(50);
		searchIn->draw();
		Sleep(100);
	}
	if (graphics::getKeyState(graphics::SCANCODE_U))
	{
		searchIn->searchText("u");
		Sleep(50);
		searchIn->draw();
		Sleep(100);
	}
	if (graphics::getKeyState(graphics::SCANCODE_V))
	{
		searchIn->searchText("v");
		Sleep(50);
		searchIn->draw();
		Sleep(100);
	}
	if (graphics::getKeyState(graphics::SCANCODE_W))
	{
		searchIn->searchText("w");
		Sleep(50);
		searchIn->draw();
		Sleep(100);
	}
	if (graphics::getKeyState(graphics::SCANCODE_X))
	{
		searchIn->searchText("x");
		Sleep(50);
		searchIn->draw();
		Sleep(100);
	}
	if (graphics::getKeyState(graphics::SCANCODE_Y))
	{
		searchIn->searchText("y");
		Sleep(50);
		searchIn->draw();
		Sleep(100);
	}
	if (graphics::getKeyState(graphics::SCANCODE_Z))
	{
		searchIn->searchText("z");
		Sleep(50);
		searchIn->draw();
		Sleep(100);
	}
	if (graphics::getKeyState(graphics::SCANCODE_SPACE))
	{
		searchIn->searchText("space");
		Sleep(200);
		searchIn->draw();
		Sleep(100);
	}
	if (graphics::getKeyState(graphics::SCANCODE_BACKSPACE))
	{
		searchIn->searchText("erase");
		Sleep(100);
		searchIn->draw();
		Sleep(100);
	}
}

Browser* Browser::getInstance()
{
	if (!m_instance)
		m_instance = new Browser();
	return m_instance;
}

Browser::~Browser()
{
	for (auto th : m_thumbs)
	{
		delete th;
	}
	m_thumbs.clear();

	for (auto sc : m_screens)
	{
		delete sc;
	}
	m_screens.clear();

	for (auto f : films)
	{
		delete f;
	}
	films.clear();

	for (auto g : genreButtons)
	{
		delete g;
	}
	genreButtons.clear();

	for (auto d : decadeButtons)
	{
		delete d;
	}
	decadeButtons.clear();

	delete leftButton;
	delete rightButton;
	delete search;
	delete searchIn;
	delete tag;
}

Browser* Browser::m_instance = nullptr;