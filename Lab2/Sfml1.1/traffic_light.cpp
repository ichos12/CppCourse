#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({200, 500}), "Traffic light");

    window.clear();

    sf::RectangleShape shape1;
    shape1.setSize({180, 480});
    shape1.setPosition({10, 10});
    shape1.setFillColor(sf::Color(67, 75, 77));
    window.draw(shape1);

    sf::CircleShape green(70);
    green.setPosition({30, 20});
    green.setFillColor(sf::Color(0, 225, 0));
    window.draw(green);

    sf::CircleShape yellow(70);
    yellow.setPosition({30, 180});
    yellow.setFillColor(sf::Color(225, 225, 0));
    window.draw(yellow);

    sf::CircleShape red(70);
    red.setPosition({30, 340});
    red.setFillColor(sf::Color(225, 0, 0));
    window.draw(red);

    window.display();

    sf::sleep(sf::seconds(10));
}