#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({500, 200}), "Initials");

    window.clear();

    sf::RectangleShape shapeG1;
    shapeG1.setSize({10, 130});
    shapeG1.setPosition({80, 40});
    window.draw(shapeG1);

    sf::RectangleShape shapeG2;
    shapeG2.setSize({10, 90});
    shapeG2.setRotation({-90});
    shapeG2.setPosition({90, 40});
    window.draw(shapeG2);

    sf::RectangleShape shapeG3;
    shapeG3.setSize({10, 90});
    shapeG3.setRotation({-90});
    shapeG3.setPosition({90, 180});
    window.draw(shapeG3);

    sf::RectangleShape shapeG4;
    shapeG4.setSize({10, 60});
    shapeG4.setPosition({180, 110});
    window.draw(shapeG4);

    sf::RectangleShape shapeG5;
    shapeG5.setSize({10, 40});
    shapeG5.setRotation({90});
    shapeG5.setPosition({180, 100});
    window.draw(shapeG5);

    sf::RectangleShape shapeM1;
    shapeM1.setSize({10, 150});
    shapeM1.setPosition({200, 30});
    window.draw(shapeM1);

    sf::RectangleShape shapeM2;
    shapeM2.setSize({10, 150});
    shapeM2.setRotation(-15);
    shapeM2.setPosition({200, 30});
    window.draw(shapeM2);

    sf::RectangleShape shapeM3;
    shapeM3.setSize({10, 150});
    shapeM3.setRotation(15);
    shapeM3.setPosition({280, 30});
    window.draw(shapeM3);

    sf::RectangleShape shapeM4;
    shapeM4.setSize({10, 150});
    shapeM4.setPosition({280, 30});
    window.draw(shapeM4);

    sf::RectangleShape shapeV1;
    shapeV1.setSize({10, 150});
    shapeV1.setRotation(-15);
    shapeV1.setPosition({300, 30});
    window.draw(shapeV1);

    sf::RectangleShape shapeV2;
    shapeV2.setSize({10, 150});
    shapeV2.setRotation(15);
    shapeV2.setPosition({380, 30});
    window.draw(shapeV2);

    window.display();

    sf::sleep(sf::seconds(5));
}