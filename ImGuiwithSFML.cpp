// ImGuiwithSFML.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Player.h"
#include "imgui.h"
#include "imgui-SFML.h"
#include "SFML/Graphics.hpp"
#define winWidth 800
#define winHeight 600


int main() {
    sf::RenderWindow window(sf::VideoMode(winWidth, winHeight), "Test");
    //window.setFramerateLimit(60);
    ImGui::SFML::Init(window);

    
    sf::Texture txt_dwarve;
    txt_dwarve.loadFromFile("dwarves.png");

    Player player(&txt_dwarve, sf::Vector2u(16, 3), 0.2f, 100.0f);

    float deltaTime = 0.0f;
    sf::Clock clock;

    while (window.isOpen()) {
        deltaTime = clock.restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(window, event);

            if (event.type == sf::Event::Closed) {
                window.close();
            }
            bool isPick = false;
            bool isAxe = false;
            bool isBow = false;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)){
                isPick = true;
                isAxe = false;
                isBow = false;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
                isPick = false;
                isAxe = true;
                isBow = false;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
                isPick = false;
                isAxe = false;
                isBow = true;
            }
            if (isPick == true) {
                std::cout << " Pick works test";
            }
            if (isAxe == true) {
                std::cout << " Axe works";
            }
            if (isBow == true) {
                std::cout << " Bow works";
            }

        }

        player.Update(deltaTime);

            window.clear();
           
            player.Draw(window);
            window.display();
    }
}

