#pragma once
#include <SFML/Graphics.hpp>

class Bullet
{
public:
    sf::RectangleShape shape;
    float speed;

    Bullet(float x, float y);
    void update();
    sf::FloatRect getBounds();
};
