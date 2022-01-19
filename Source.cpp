#include "player.h"

player p("assets/white_square.png");



int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My Window", sf::Style::Titlebar | sf::Style::Close);

    player myPlayer("assets/white_square.png");

    while (window.isOpen()) {
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color(25, 25, 25));
        p.drawPlayer(window);
        window.display();
    }


    return 0;
}