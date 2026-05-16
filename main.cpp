#include <iostream>
#include <SFML/Graphics.hpp>
#include "Airplane.h"

int main() {

    sf::RenderWindow AirCombatWindow(sf::VideoMode(1920, 1080), "Air Combat 2");
    AirCombatWindow.setFramerateLimit(60);
    Airplane playerAirplane;
    enum GameState {
        MENU,
        GAME,
        CREDITS,
        OPTIONS
    };
    enum GameState gameMachine = MENU;
    if(!playerAirplane.airplaneTexture.loadFromFile("../assets/MB5.png")) {
        std::cerr << "Failed to load playerAirplane.airplaneTexture" << std::endl;
    }
    playerAirplane.airplaneTexture.setSmooth(true);
    playerAirplane.airplaneSprite.setTexture(playerAirplane.airplaneTexture);
    playerAirplane.airplaneSprite.setScale({0.45f, 0.45f});
    playerAirplane.airplaneSprite.setPosition({playerAirplane.airplaneX, playerAirplane.airplaneY});
    sf::Vector2f playerPosition = playerAirplane.airplaneSprite.getPosition();
    sf::View mainCamera;

    while(AirCombatWindow.isOpen()) {
        sf::Event gameEvent {};
        while(AirCombatWindow.pollEvent(gameEvent)) {
            if(gameEvent.type == sf::Event::Closed)
                AirCombatWindow.close();
        }
        if(gameMachine == GAME) {
            AirCombatWindow.clear(sf::Color(51,230,230));
            AirCombatWindow.draw(playerAirplane.airplaneSprite);
            mainCamera.setCenter(static_cast<float>(playerAirplane.airplaneSprite.getTextureRect().left), static_cast<float>(playerAirplane.airplaneSprite.getTextureRect().top));
            playerAirplane.airplaneSprite.move(playerPosition.x + playerAirplane.airplaneSpeed, 0);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                gameMachine = MENU;

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                playerAirplane.airplaneSprite.move(5.f, 0.f);
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                playerAirplane.airplaneSprite.move(-5.f, 0.f);
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                playerAirplane.airplaneSprite.move(0.f, 5.f);
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                playerAirplane.airplaneSprite.move(0.f, -5.f);
            }
        }
        else if(gameMachine == OPTIONS) {
            AirCombatWindow.clear(sf::Color::Green);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                gameMachine = MENU;
        }
        else if(gameMachine == MENU) {
            AirCombatWindow.clear(sf::Color::Yellow);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                gameMachine = GAME;
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
                gameMachine = OPTIONS;
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                gameMachine = CREDITS;
        }
        else if(gameMachine == CREDITS) {
            AirCombatWindow.clear(sf::Color::Red);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                gameMachine = MENU;
        }
        AirCombatWindow.setView(mainCamera);
        AirCombatWindow.display();
    }
    return 0;
}
