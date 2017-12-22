#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>

int main()
{
    constexpr int pointCount = 200;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({800, 600}), "Polar Rose",
        sf::Style::Default, settings);

    sf::Vector2f position = {400, 200};
    sf::ConvexShape rose;
    rose.setPosition(position);
    rose.setFillColor(sf::Color(0xE9, 0x01, 0xAD));

    float angle = 0;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        rose.setPointCount(pointCount);
        for (int pointNo = 0; pointNo < pointCount; ++pointNo)
        {
            float angle = float(2 * M_PI * pointNo) / float(pointCount);
            float radius = 100 * sin(6 * angle);
            sf::Vector2f point = {
                radius * std::sin(angle),
                radius * std::cos(angle)};
            rose.setPoint(pointNo, point);
        }

        angle += 0.01;
        position.x = position.x + std::cos(angle);
        position.y = position.y + std::sin(angle);
        rose.setPosition(position);

        window.clear();
        window.draw(rose);
        window.display();
    }
}