#include "screen.h"

void Screen::setup(const string& setTitle, const Vector2u& setSize){
    title = setTitle;
    size = setSize;
    fullScreen = false;
    create();
}


void Screen::create(){
    auto style = fullScreen ? Style::Fullscreen : Style::Default;
    screen.create({ size.x, size.y, 32}, title, style);
}


void Screen::destroy(){
    screen.close();
}

// Public
Screen::Screen(){
    setup("Game Window", Vector2u(640, 480));
}


Screen::Screen(const string& setTitle, const Vector2u& setSize){ 
    setup(setTitle, setSize);
}


Screen::~Screen(){ 
    destroy();
}


bool Screen::isOpen() { 
    return screen.isOpen();
}


bool Screen::isFullScreen() { 
    return fullScreen;
}


Vector2u Screen::getScreenSize() { 
    return size;
}


void Screen::beginDraw() { 
    screen.clear(Color::Black);
}


void Screen::endDraw() { 
    screen.display();
}


void Screen::update(){
    Event event;
    while(screen.pollEvent(event)){
        if(event.type == Event::Closed){
            screen.close();
        }

        if(event.type == Event::KeyPressed && event.key.code == Keyboard::F5){
            toggleFullScreen();
        }
    }
}


void Screen::draw(Drawable& object) { 
    screen.draw(object);
}
        

void Screen::toggleFullScreen(){
    fullScreen = !fullScreen;
    destroy();
    create();
}

        