#include "Enemy.h"

Enemy::Enemy(float x, float y)
{
    shape.setSize(sf::Vector2f(40, 20)); // Enemy size
    shape.setFillColor(sf::Color::Yellow);
    shape.setPosition(sf::Vector2f(x, y));
    speed = 2.0f;
}

void Enemy::move()
{
    shape.move(sf::Vector2f(speed, 0)); // Move horizontally
}

sf::FloatRect Enemy::getBounds()
{
    return shape.getGlobalBounds();
}
