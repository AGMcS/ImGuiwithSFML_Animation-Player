// ImGuiwithSFML.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Player.h"
#include "imgui.h"
#include "imgui-SFML.h"
#include "SFML/Graphics.hpp"

#define winWidth 800
#define winHeight 600

void dwarveAnimated(sf::Sprite &sprite, sf::IntRect &coordinates, int startPoint, int endPoint, sf::Clock &clock, int incrementFrame) {
    if (coordinates.left == endPoint) {
        coordinates.left = startPoint;
    }
        coordinates.left += incrementFrame;

    sprite.setTextureRect(coordinates);
    clock.restart();
}

void enemyAnimated(sf::Sprite &sprite, sf::IntRect &coordinates, int startPoint, int endPoint, sf::Clock &clock, int incrementFrame) {
    if (coordinates.left == endPoint) {
        coordinates.left = startPoint;
    }
    coordinates.left += incrementFrame;

    sprite.setTextureRect(coordinates);
    clock.restart();
}

int main() {
    sf::RenderWindow window(sf::VideoMode(winWidth, winHeight), "Test");
    window.setFramerateLimit(10);
    ImGui::SFML::Init(window);
    sf::Event event;

    sf::Texture txt_dwarve;
    txt_dwarve.loadFromFile("dwarves.png");

    sf::Texture txt_enemy;
    txt_enemy.loadFromFile("minotaurus_spritesheet_frost.png");
    sf::Texture txt_minatour;
    txt_minatour.loadFromFile("preview-red(1).png");
    
    

    int start, finish;
    int row = 0;
    bool flipCharacter = false;

    bool flipEnemy = true; 

    //dwarve animations
    //https://opengameart.org/content/delve-deeper-dwarves "Lunar Giant!
    sf::IntRect dwarveIdleImage(0, 0, 100, 80);
    sf::IntRect dwarveAttackImage(1000, 0, 100, 80);
    sf::IntRect dwarveWalkingImage(400, 0, 100, 80);

    //enemy animations
    //https://opengameart.org/content/minotaur-with-axe "Bonsaiheldin" 
    sf::IntRect enemyIdleImage(0, 0, 96, 96);
    sf::IntRect enemyWalkingImage(0, 96, 96, 96);
    sf::IntRect enemyAttackImage(0, 192, 96, 96);

    //minatour animations
    //https://opengameart.org/content/minotaur-2 credited: "Jordan Irwin (AntumDeluge)"
    sf::IntRect minatourWalk(0, 192, 48, 64);

    //spider animations
    //https://opengameart.org/content/arachne credited: "Svetlana Kushnariova"

    
    //SET PLAYER SPRITE
    sf::Sprite sprite;
    sprite.setTexture(txt_dwarve);
    sprite.setTextureRect(dwarveIdleImage);
    sprite.setPosition(400, 300);
    sprite.setOrigin(50, 40);

    //set enemy sprite
    sf::Sprite spriteEnemy;
    spriteEnemy.setTexture(txt_enemy);
    spriteEnemy.setTextureRect(enemyWalkingImage);
    spriteEnemy.setPosition(190, 150);
    spriteEnemy.setOrigin(48, 48);
    spriteEnemy.setScale(2.0f, 2.0f);

    //set enemy sprite
    sf::Sprite spriteMinatour;
    spriteMinatour.setTexture(txt_minatour);
    spriteMinatour.setTextureRect(minatourWalk);
    spriteMinatour.setPosition(190, 450);
    spriteMinatour.setOrigin(24, 32);
    spriteMinatour.setScale(2.0f, 2.0f);

    sf::Clock clock;

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(window, event);

            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::Cyan);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
            dwarveIdleImage.top = row;
            dwarveWalkingImage.top = row;
            dwarveAttackImage.top = row;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
            dwarveIdleImage.top = row + 80;
            dwarveWalkingImage.top = row + 80;
            dwarveAttackImage.top = row + 80;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
            dwarveIdleImage.top = row + 160;
            dwarveWalkingImage.top = row + 160;
            dwarveAttackImage.top = row + 160;
        }


        //dwarve will iterate through idle animation unless input passed
        dwarveAnimated(sprite, dwarveIdleImage, 0, 300, clock, 100);

        //enemy test method
        enemyAnimated(spriteEnemy, enemyWalkingImage, 0, 288, clock, 96);

        enemyAnimated(spriteMinatour, minatourWalk, 0, 96, clock, 48);

        
            if (spriteEnemy.getPosition().x >= 600) {
                flipEnemy = false;
            } 
            
            if (spriteEnemy.getPosition().x <= 200) {
                flipEnemy = true;
            }
        
            if (flipEnemy) {
                spriteEnemy.setScale(2.f, 2.f);
                spriteEnemy.move(3.f, 0.f);
            }
            else if (!flipEnemy) {
                spriteEnemy.setScale(-2.f, 2.f);
                spriteEnemy.move(-3.f, 0.f);
            }


            if (spriteMinatour.getPosition().x >= 600) {
                flipEnemy = false;
            }

            if (spriteMinatour.getPosition().x <= 200) {
                flipEnemy = true;
            }

            if (flipEnemy) {
                spriteMinatour.setScale(-2.f, 2.f);
                spriteMinatour.move(3.f, 0.f);
            }
            else if (!flipEnemy) {
                spriteMinatour.setScale(2.f, 2.f);
                spriteMinatour.move(-3.f, 0.f);
            }
     
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            flipCharacter = false;
            dwarveAnimated(sprite, dwarveWalkingImage, 400, 900, clock, 100);
            sprite.move(-5.f, 0.f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            flipCharacter = true;
            dwarveAnimated(sprite, dwarveWalkingImage, 400, 900, clock, 100);
            sprite.move(5.f, 0.f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
            dwarveAnimated(sprite, dwarveAttackImage, 1000, 1300, clock, 100);
        }
   
        if (flipCharacter == true) {
            sprite.setScale(-1.f, 1.f);
        }
        else {
            sprite.setScale(1.f, 1.f);
        }

         window.draw(sprite);
         window.draw(spriteEnemy);
         window.draw(spriteMinatour);
         window.display();    
    }
}