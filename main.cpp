#include <iostream>
#include <SFML/Graphics.hpp>
#include "Box2D/Box2D.h"

using std::cout;
using std::endl;
using std::string;

void moveOBJ(sf::CircleShape &CS, double mainX, double mainY, double speed=1)
{
    double objX = CS.getPosition().x;
    double objY = CS.getPosition().y;

    CS.move((mainX - objX)/speed , (mainY - objY)/speed);
}


int main()
{
    sf::RenderWindow RW(sf::VideoMode(1920, 1080), "Moving", sf::Style::Fullscreen);

    sf::CircleShape mainObject(50, 8);
    mainObject.setOrigin(sf::Vector2f(50, 50));
    mainObject.setPosition(sf::Vector2f(150, 150));
    mainObject.setFillColor(sf::Color::Red);

    while(RW.isOpen())
    {
        sf::Event mainEvent;
        if(RW.pollEvent(mainEvent))
        {
            if(mainEvent.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                RW.close();
            }
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                ;
            }
        }

        moveOBJ(mainObject, sf::Mouse::getPosition(RW).x, sf::Mouse::getPosition(RW).y, 500);
        cout<<mainObject.getPosition().x<<" - "<<mainObject.getPosition().y<<endl;

        RW.clear(sf::Color::Black);
        RW.draw(mainObject);
        RW.display();

    }

    return 0;
}
