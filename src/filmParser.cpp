#include "filmParser.h"

void FilmParser::init()
{
    // Open the XML file for reading
    std::ifstream file("assets\\films.xml");

    // Read the file line by line
    std::string line;
    while (std::getline(file, line))
    {
        Film* f = new Film();

        size_t titlePos = line.find("title=");
        if (titlePos != std::string::npos)
        {
            size_t titleEndPos = line.find('"', titlePos + 7);
            if (titleEndPos != std::string::npos)
            {
                std::string title = line.substr(titlePos + 7, titleEndPos - titlePos - 7);
                if (!title.empty())
                {
                    f->setTitle(title);
                }
            }
        }

        size_t directorPos = line.find("directors=");
        if (directorPos != std::string::npos)
        {
            size_t directorEndPos = line.find('"', directorPos + 11);
            if (directorEndPos != std::string::npos)
            {
                std::string director = line.substr(directorPos + 11, directorEndPos - directorPos - 11);
                f->setDirector(director);
            }
        }

        size_t actorsPos = line.find("actors=");
        if (actorsPos != std::string::npos)
        {
            size_t actorsEndPos = line.find('"', actorsPos + 8);
            if (actorsEndPos != std::string::npos)
            {
                std::string actors = line.substr(actorsPos + 8, actorsEndPos - actorsPos - 8);
                f->setActors(actors);
            }
        }

        size_t genrePos = line.find("genre=");
        if (genrePos != std::string::npos)
        {
            size_t genreEndPos = line.find('"', genrePos + 7);
            if (genreEndPos != std::string::npos)
            {
                std::string genre = line.substr(genrePos + 7, genreEndPos - genrePos - 7);
                f->setGenre(genre);
            }
        }

        size_t yearPos = line.find("year=");
        if (yearPos != std::string::npos)
        {
            size_t yearEndPos = line.find('"', yearPos + 6);
            if (yearEndPos != std::string::npos)
            {
                std::string year = line.substr(yearPos + 6, yearEndPos - yearPos - 6);
                f->setYear(year);
            }
        }

        size_t thumbnailPos = line.find("thumbnail=");
        if (thumbnailPos != std::string::npos)
        {
            size_t thumbnailEndPos = line.find('"', thumbnailPos + 11);
            if (thumbnailEndPos != std::string::npos)
            {
                std::string thumbnail = line.substr(thumbnailPos + 11, thumbnailEndPos - thumbnailPos - 11);
                f->setThumb(thumbnail);
            }
        }

        size_t descPos = line.find("description=");
        if (descPos != std::string::npos)
        {
            size_t descEndPos = line.find('"', descPos + 13);
            if (descEndPos != std::string::npos)
            {
                std::string description = line.substr(descPos + 13, descEndPos - descPos - 13);
                f->setDesc(description);

                for (int i = 0; i < 3; i++)
                {
                    std::getline(file, line);
                    size_t imagePos = line.find("image=");
                    if (imagePos != std::string::npos)
                    {
                        size_t imageEndPos = line.find('"', imagePos + 7);
                        if (imageEndPos != std::string::npos)
                        {
                            std::string screen = line.substr(imagePos + 7, imageEndPos - imagePos - 7);
                            screencaps.push_back(screen);
                        }
                    }
                    f->setScreencaps(screencaps);
                }
                m_films.push_back(f);
                screencaps.erase(screencaps.begin(), screencaps.end());
            }
        }

    }
}

std::list<Film*> FilmParser::getFilms()
{
    return m_films;
}

FilmParser::FilmParser()
{
    init();
}