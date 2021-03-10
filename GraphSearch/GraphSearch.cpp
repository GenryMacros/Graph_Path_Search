#include <iostream>
#include "MouseEvent.h"
int main()
{
    unsigned int height = 400;
    unsigned int width = 400;
    sf::RenderWindow win(sf::VideoMode(1050,800), "PathSearcher");
    win.setFramerateLimit(5);
  
    MouseEvents ms(height, width,win);
    sf::Event event;
    win.display();
    while (win.isOpen()) {
        while (win.pollEvent(event)) {
            if (event.type == sf::Event::Closed) win.close();
            else if (event.type == sf::Event::MouseButtonPressed) {
                ms.ProcessClick(win);
          
            }
        }    
    }
}
