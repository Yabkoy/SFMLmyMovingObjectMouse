#include <iostream>
#include <SFML/Graphics.hpp>

void moveOBJ(sf::CircleShape &CS, const double& mainX, const double& mainY, double speed=1)
{
    CS.move((mainX - CS.getPosition().x)/speed , (mainY - CS.getPosition().y)/speed);
    CS.rotate(speed/10000);
}

int main()
{
    sf::RenderWindow RW(sf::VideoMode(800, 600), "Moving");

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
        }

        moveOBJ(mainObject, sf::Mouse::getPosition(RW).x, sf::Mouse::getPosition(RW).y, 500);
        std::cout<<mainObject.getPosition().x<<" - "<<mainObject.getPosition().y<<std::endl;

        RW.clear(sf::Color::Black);
        RW.draw(mainObject);
        RW.display();

    }
    return 0;
}
