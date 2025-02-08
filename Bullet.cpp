#include "Bullet.h"

Bullet::Bullet(float x, float y)
{
    shape.setSize(sf::Vector2f(5, 10)); // Bullet size
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(sf::Vector2f(x, y));
    speed = 5.0f;
}

void Bullet::update()
{
    shape.move(sf::Vector2f(0, -speed)); // Move bullet upwards
}

sf::FloatRect Bullet::getBounds()
{
    return shape.getGlobalBounds();
}
