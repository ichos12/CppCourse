#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RectangleShape walls;
    walls.setFillColor(sf::Color(168, 98, 0));
    walls.setPosition({90, 220});
    walls.setSize({420, 180});

    sf::RectangleShape door;
    door.setFillColor(sf::Color(125, 125, 125));
    door.setPosition({150, 280});
    door.setSize({60, 120});

    sf::ConvexShape roof;
    roof.setFillColor(sf::Color(160, 0, 0));
    roof.setPosition(30, 100);
    roof.setPointCount(4);
    roof.setPoint(0, {120, 0});
    roof.setPoint(1, {420, 0});
    roof.setPoint(2, {540, 120});
    roof.setPoint(3, {0, 120});

    sf::RectangleShape tube1;
    tube1.setFillColor(sf::Color(125, 125, 125));
    tube1.setPosition({390, 80});
    tube1.setSize({30, 90});

    sf::RectangleShape tube2;
    tube2.setFillColor(sf::Color(125, 125, 125));
    tube2.setPosition({375, 50});
    tube2.setSize({60, 30});

    sf::CircleShape smoke(10);
    smoke.setFillColor(sf::Color(219, 219, 219));
    smoke.setPosition({400, 30});

    sf::CircleShape smoke1(15);
    smoke1.setFillColor(sf::Color(219, 219, 219));
    smoke1.setPosition({410, 10});

    sf::CircleShape smoke2(15);
    smoke2.setFillColor(sf::Color(219, 219, 219));
    smoke2.setPosition({420, 0});

    sf::RenderWindow window(sf::VideoMode({600, 400}), "House");
    window.clear();
    window.draw(walls);
    window.draw(door);
    window.draw(roof);
    window.draw(tube1);
    window.draw(tube2);
    window.draw(smoke);
    window.draw(smoke1);
    window.draw(smoke2);
    window.display();

    sf::sleep(sf::seconds(5));
}
