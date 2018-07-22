//
// Created by hugo on 22/07/18.
//

#include "Graphics.hpp"
#include "RenderWindow.hpp"
#include "Core.h"
#include "Core.h"

Core::Core() {

}

Core::~Core() {

}

bool Core::initMap() {
    return false;
}

void Core::startGame() {
    sf::RenderWindow window(sf::VideoMode(1300, 900), "SFML works!");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }

}

bool Core::initPlayers() {
    return false;
}

