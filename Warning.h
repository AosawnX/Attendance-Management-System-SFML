#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include"AdminLogin.h"
#include"LoginAs.h"
#include"Security.h"

int admin();
void loginAs();
using namespace sf;
using namespace std;

void displayWarningDialog(RenderWindow &AdmWin) {
    sf::RenderWindow window(sf::VideoMode(400, 200), "Warning Dialog");
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("OsMed.ttf")) {
        std::cout << "Error loading font file!" << std::endl;
        return;
    }

    Texture Warning;
    Warning.loadFromFile("warning.png");
    Sprite WarningImage(Warning);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        
        window.draw(WarningImage);
        window.display();
        FaceCap();
        

        // Wait for 3 seconds
        std::this_thread::sleep_for(std::chrono::seconds(3));

        window.close();
        break; // Exit the loop after 3 seconds
        
    }
    AdmWin.close();
    loginAs();
}

