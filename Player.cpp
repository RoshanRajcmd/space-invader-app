#include "Player.h"

Player::Player()
{
    shape.setSize(sf::Vector2f(50, 20)); // Player size
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(sf::Vector2f(375, 550)); // Start position at the bottom of the screen
    speed = 6.0f;
}

void Player::moveLeft()
{
    if (shape.getPosition().x > 0)
    {
        shape.move(sf::Vector2f(-speed, 0));
    }
}

void Player::moveRight()
{
    if (shape.getPosition().x < 750)
    {
        shape.move(sf::Vector2f(speed, 0));
    }
}

sf::FloatRect Player::getBounds()
{
    return shape.getGlobalBounds();
}
