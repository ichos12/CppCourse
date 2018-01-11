#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

struct Eye
{
    sf::ConvexShape eye;
    sf::ConvexShape apple;
    sf::Vector2f position;
    float rotation = 0;
};

sf::Vector2f toEuclidean(float radiusX, float radiusY, float angle)
{
    return {
        radiusX * cos(angle),
        radiusY * sin(angle)};
}

void updateEyeElements(const sf::Vector2f &mousePosition, Eye &eyeRight, Eye &eyeLeft)
{
    eyeRight.eye.setPosition(eyeRight.position);
    sf::Vector2f appleOffsetRight = toEuclidean(20, 40, eyeRight.rotation);
    if ((pow((mousePosition.x - eyeRight.position.x), 2) / pow(appleOffsetRight.x, 2) + pow((mousePosition.y - eyeRight.position.y), 2) / pow(appleOffsetRight.y, 2)) > 1.f)
    {
        eyeRight.apple.setPosition(eyeRight.position + appleOffsetRight);
    }
    else
    {
        eyeRight.apple.setPosition(mousePosition);
    }

    eyeLeft.eye.setPosition(eyeLeft.position);
    sf::Vector2f appleOffsetLeft = toEuclidean(20, 40, eyeLeft.rotation);
    if ((pow((mousePosition.x - eyeLeft.position.x), 2) / pow(appleOffsetLeft.x, 2) + pow((mousePosition.y - eyeLeft.position.y), 2) / pow(appleOffsetLeft.y, 2)) > 1.f)
    {
        eyeLeft.apple.setPosition(eyeLeft.position + appleOffsetLeft);
    }
    else
    {
        eyeLeft.apple.setPosition(mousePosition);
    }
}

void initEye(sf::Vector2f &mousePosition, Eye &eyeLeft, Eye &eyeRight)
{
    const sf::Vector2f eyeRadius = {40.f, 80.f};
    const sf::Vector2f appleRadius = {10.f, 20.f};
    constexpr int pointCount = 200;

    eyeLeft.position = {200, 300};
    eyeLeft.eye.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    eyeLeft.eye.setPointCount(pointCount);
    for (int pointNo = 0; pointNo < pointCount; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);
        sf::Vector2f point = {
            eyeRadius.x * std::sin(angle),
            eyeRadius.y * std::cos(angle)};
        eyeLeft.eye.setPoint(pointNo, point);
    }

    eyeLeft.apple.setFillColor(sf::Color(0, 0, 0));
    eyeLeft.apple.setPointCount(pointCount);
    for (int pointNo = 0; pointNo < pointCount; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);
        sf::Vector2f point = {
            appleRadius.x * std::sin(angle),
            appleRadius.y * std::cos(angle)};
        eyeLeft.apple.setPoint(pointNo, point);
    }

    eyeRight.position = {300, 300};
    eyeRight.eye.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    eyeRight.eye.setPointCount(pointCount);
    for (int pointNo = 0; pointNo < pointCount; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);
        sf::Vector2f point = {
            eyeRadius.x * std::sin(angle),
            eyeRadius.y * std::cos(angle)};
        eyeRight.eye.setPoint(pointNo, point);
    }

    eyeRight.apple.setFillColor(sf::Color(0, 0, 0));
    eyeRight.apple.setPointCount(pointCount);
    for (int pointNo = 0; pointNo < pointCount; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);
        sf::Vector2f point = {
            appleRadius.x * std::sin(angle),
            appleRadius.y * std::cos(angle)};
        eyeRight.apple.setPoint(pointNo, point);
    }
}

void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
    std::cout << "mouse x=" << event.x << " mouse y=" << event.y << std::endl;
    mousePosition = {float(event.x), float(event.y)};
}

void pollEvents(sf::RenderWindow &window, sf::Vector2f &mousePosition)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::MouseMoved:
            onMouseMove(event.mouseMove, mousePosition);
            break;
        default:
            break;
        }
    }
}

void update(const sf::Vector2f &mousePosition, Eye &eyeLeft, Eye &eyeRight)
{
    const sf::Vector2f delta1 = mousePosition - eyeLeft.position;
    eyeLeft.rotation = atan2(delta1.y, delta1.x);

    const sf::Vector2f delta2 = mousePosition - eyeRight.position;
    eyeRight.rotation = atan2(delta2.y, delta2.x);
    updateEyeElements(mousePosition, eyeRight, eyeLeft);
}

void redrawFrame(sf::RenderWindow &window, Eye &eyeLeft, Eye &eyeRight)
{
    window.clear();
    window.draw(eyeLeft.eye);
    window.draw(eyeLeft.apple);
    window.draw(eyeRight.eye);
    window.draw(eyeRight.apple);
    window.display();
}

int main()
{
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
        "Eyes", sf::Style::Default, settings);

    Eye eyeLeft;
    Eye eyeRight;
    sf::Vector2f mousePosition;
    initEye(mousePosition, eyeLeft, eyeRight);

    while (window.isOpen())
    {
        pollEvents(window, mousePosition);
        update(mousePosition, eyeLeft, eyeRight);
        redrawFrame(window, eyeLeft, eyeRight);
    }
}