#pragma once
#include "SFML/Graphics.hpp"
class Animation
{
public:
    sf::Sprite sprite;
    sf::Texture spritesheet;
    sf::IntRect coordinates;
    int startPoint, endPoint;

  
};

