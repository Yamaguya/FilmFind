#include "browser.h"

// The window content drawing function.
void draw()
{
    Browser* browser = Browser::getInstance();
    browser->draw();
}

// The custom callback function that the library calls 
// to check for and set the current application state.
void update(float ms)
{
    Browser* browser = Browser::getInstance();
    browser->update();
}

int main(int argc, char ** argv)
{
    graphics::createWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Film Finder");

    Browser* browser = Browser::getInstance();
    
    browser->init();

    graphics::preloadBitmaps(THUMB_PATH);
    graphics::preloadBitmaps(SCREENCAP_PATH);

    graphics::setDrawFunction(draw);
    graphics::setUpdateFunction(update);

    graphics::setCanvasSize(CANVAS_WIDTH, CANVAS_HEIGHT);
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);

    graphics::setFont(std::string(ASSET_PATH) + "Lekton-Regular.ttf");

    graphics::startMessageLoop();

    delete browser;

    return 0;
}
