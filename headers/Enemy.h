#pragma once
#include <SFML/Graphics.hpp>

class Enemy
{
public:
    sf::RectangleShape shape;
    float speed;

    Enemy(float x, float y);
    void move();
    sf::FloatRect getBounds();
};
