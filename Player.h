#pragma once
#include <SFML/Graphics.hpp>


class Player
{
private:
	sf::Sprite sprite;
	sf::Texture spriteSheet;

	void initTexture();
	void initSprite();


	//Animation

	//Movement


	//Player status



public:
	Player();
	~Player();



	//Methods

	void Update();
	void Render(sf::RenderTarget& target);






};