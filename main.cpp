#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <iostream>
#include "headers/Bullet.h"
#include "headers/Player.h"
#include "headers/Enemy.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Space Invaders");

    // Create player, bullets, and enemies
    Player player;
    std::vector<Bullet> bullets;
    std::vector<Enemy> enemies;

    // Create a grid of enemies
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            enemies.push_back(Enemy(60 * j + 50, 40 * i + 50));
        }
    }

    bool gameOver = false;
    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Time deltaTime = clock.restart();

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        // Player movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        {
            player.moveLeft();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        {
            player.moveRight();
        }

        // Shooting bullets
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
        {
            bullets.push_back(Bullet(player.shape.getPosition().x + 22, player.shape.getPosition().y));
        }

        // Update bullets
        for (auto &bullet : bullets)
        {
            bullet.update();
        }

        // Update enemies
        for (auto &enemy : enemies)
        {
            enemy.move();
            if (enemy.shape.getPosition().x > 750 || enemy.shape.getPosition().x < 0)
            {
                enemy.speed = -enemy.speed; // Reverse direction when hitting edge
            }
        }

        // Collision detection between bullets and enemies
        for (auto it = bullets.begin(); it != bullets.end();)
        {
            bool eraseBullet = false;
            for (auto et = enemies.begin(); et != enemies.end();)
            {
                // if (it->getBounds().intersects(et->getBounds()))
                if (const std::optional intersection = it->getBounds().findIntersection(et->getBounds()))
                {
                    it = bullets.erase(it); // Remove the bullet
                    et = enemies.erase(et); // Remove the enemy
                    eraseBullet = true;
                    break;
                }
                else
                {
                    ++et;
                }
            }
            if (!eraseBullet)
            {
                ++it;
            }
        }

        // Check for collisions between player and enemy bullets
        // Here you can add enemy bullets and player bullet collisions if desired.

        // Drawing everything
        window.clear();

        window.draw(player.shape);
        for (auto &bullet : bullets)
        {
            window.draw(bullet.shape);
        }
        for (auto &enemy : enemies)
        {
            window.draw(enemy.shape);
        }

        window.display();
    }

    return 0;
}
