//
// Created by Predator on 11.05.2026.
//

#ifndef PLANE_H
#define PLANE_H
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>


class Airplane {
public:
    Airplane();
    ~Airplane();
    sf::Texture airplaneTexture;
    sf::Sprite airplaneSprite;
    sf::RectangleShape airplaneCollisionShape;
    float airplaneX;
    float airplaneY;
    int airplaneHealth;
    float airplaneSpeed;
};


#endif //PLANE_H
