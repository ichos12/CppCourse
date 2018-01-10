#include "main.hpp"

initials::initials(const sf::Vector2f position)
{
    initBall(position);
    initText(position);
}

void initials::initBall(const sf::Vector2f position)
{
    ball.setRadius(BALL_SIZE);
    ball.setPosition(position);
    ball.setOrigin(BALL_SIZE, BALL_SIZE);
    ball.setFillColor(sf::Color(0xFF, 0xBB, 0x1F));
    ball.setOutlineThickness(OUTLINE_SIZE);
    ball.setOutlineColor(sf::Color(0x00, 0x49, 0xA8));
    startY = position.y;
}

void initials::initText(const sf::Vector2f position)
{
    assert(font.loadFromFile("arial.ttf"));

    text.setFont(font);
    text.setString("GMV");
    text.setCharacterSize(TEXT_SIZE);
    text.setFillColor(sf::Color::Black);
    const sf::FloatRect textBounds = text.getLocalBounds();
    text.setOrigin({textBounds.width / 2, textBounds.height - OUTLINE_SIZE});
    text.setPosition(position);
}

void initials::update(float deltaTime)
{
    if (ball.getPosition().y >= startY)
    {
        time = 0;
    }
    time += deltaTime;
    float newY = startY - SPEED * time + GRAVITY * pow(time, 2) * 0.5;

    ball.setPosition(ball.getPosition().x, newY);
    text.setPosition(text.getPosition().x, newY);
}

void initials::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(ball, states);
    target.draw(text, states);
}