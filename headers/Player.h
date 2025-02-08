#pragma once
#include <SFML/Graphics.hpp>

class Player
{
public:
    sf::RectangleShape shape;
    float speed;

    Player();
    void moveLeft();
    void moveRight();
    sf::FloatRect getBounds();
};
