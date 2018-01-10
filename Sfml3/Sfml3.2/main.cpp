#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

struct EyeLeft
{
    sf::ConvexShape eyeLeft;
    sf::ConvexShape appleLeft;
    sf::Vector2f position;
    float rotation = 0;
};

struct EyeRight
{
    sf::ConvexShape eyeRight;
    sf::ConvexShape appleRight;
    sf::Vector2f position;
    float rotation = 0;
};

sf::Vector2f toEuclidean(float radiusX, float radiusY, float angle)
{
    return {
        radiusX * cos(angle),
        radiusY * sin(angle)};
}

void updateEyeLeftElements(EyeLeft &EyeLeft)
{
    EyeLeft.eyeLeft.setPosition(EyeLeft.position);
    const sf::Vector2f appleLeft0ffset = toEuclidean(20, 40, EyeLeft.rotation);
    EyeLeft.appleLeft.setPosition(EyeLeft.position + appleLeft0ffset);
}

void initEyeLeft(EyeLeft &EyeLeft)
{
    const sf::Vector2f eyeLeftRadius = {40.f, 80.f};
    const sf::Vector2f appleLeftRadius = {10.f, 20.f};
    constexpr int pointCount = 200;
    EyeLeft.position = {200, 300};

    EyeLeft.eyeLeft.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    EyeLeft.eyeLeft.setPointCount(pointCount);
    for (int pointNo = 0; pointNo < pointCount; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);
        sf::Vector2f point = {
            eyeLeftRadius.x * std::sin(angle),
            eyeLeftRadius.y * std::cos(angle)};
        EyeLeft.eyeLeft.setPoint(pointNo, point);
    }

    EyeLeft.appleLeft.setFillColor(sf::Color(0, 0, 0));
    EyeLeft.appleLeft.setPointCount(pointCount);
    for (int pointNo = 0; pointNo < pointCount; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);
        sf::Vector2f point = {
            appleLeftRadius.x * std::sin(angle),
            appleLeftRadius.y * std::cos(angle)};
        EyeLeft.appleLeft.setPoint(pointNo, point);
    }

    updateEyeLeftElements(EyeLeft);
}

void updateEyeRightElements(EyeRight &EyeRight)
{
    EyeRight.eyeRight.setPosition(EyeRight.position);
    const sf::Vector2f appleRight0ffset = toEuclidean(20, 40, EyeRight.rotation);
    EyeRight.appleRight.setPosition(EyeRight.position + appleRight0ffset);
}

void initEyeRight(EyeRight &EyeRight)
{
    const sf::Vector2f eyeRightRadius = {40.f, 80.f};
    const sf::Vector2f appleRightRadius = {10.f, 20.f};
    constexpr int pointCount = 200;
    EyeRight.position = {300, 300};

    EyeRight.eyeRight.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    EyeRight.eyeRight.setPointCount(pointCount);
    for (int pointNo = 0; pointNo < pointCount; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);
        sf::Vector2f point = {
            eyeRightRadius.x * std::sin(angle),
            eyeRightRadius.y * std::cos(angle)};
        EyeRight.eyeRight.setPoint(pointNo, point);
    }

    EyeRight.appleRight.setFillColor(sf::Color(0, 0, 0));
    EyeRight.appleRight.setPointCount(pointCount);
    for (int pointNo = 0; pointNo < pointCount; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);
        sf::Vector2f point = {
            appleRightRadius.x * std::sin(angle),
            appleRightRadius.y * std::cos(angle)};
        EyeRight.appleRight.setPoint(pointNo, point);
    }

    updateEyeRightElements(EyeRight);
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

void update(const sf::Vector2f &mousePosition, EyeLeft &EyeLeft, EyeRight &EyeRight)
{
    const sf::Vector2f delta1 = mousePosition - EyeLeft.position;
    EyeLeft.rotation = atan2(delta1.y, delta1.x);
    updateEyeLeftElements(EyeLeft);

    const sf::Vector2f delta2 = mousePosition - EyeRight.position;
    EyeRight.rotation = atan2(delta2.y, delta2.x);
    updateEyeRightElements(EyeRight);
}

void redrawFrame(sf::RenderWindow &window, EyeLeft &EyeLeft, EyeRight &EyeRight)
{
    window.clear();
    window.draw(EyeLeft.eyeLeft);
    window.draw(EyeLeft.appleLeft);
    window.draw(EyeRight.eyeRight);
    window.draw(EyeRight.appleRight);
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

    EyeLeft EyeLeft;
    EyeRight EyeRight;
    initEyeLeft(EyeLeft);
    initEyeRight(EyeRight);
    sf::Vector2f mousePosition;

    while (window.isOpen())
    {
        pollEvents(window, mousePosition);
        update(mousePosition, EyeLeft, EyeRight);
        redrawFrame(window, EyeLeft, EyeRight);
    }
}