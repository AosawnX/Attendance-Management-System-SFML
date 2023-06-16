#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include <string>
#include <iostream> 
#include <random>
#include"HomePage.h"


void HomePage();
using namespace sf;
using namespace std;
void AvFaculty()
{
    RenderWindow window(VideoMode(1340, 760), "Available Faculty", Style::Close | Style::Titlebar);
    window.setFramerateLimit(60);

    /*-------------------------------------------START OF TEXTURES-------------------------------------------*/
    Texture background;
    Sprite backgroundImage;



    if (!background.loadFromFile("AvFac.png"))
        cout << "Error: Could not display image" << endl;

    backgroundImage.setTexture(background);

    Texture BackButton;
    Sprite BackButtonImage;
    if (!BackButton.loadFromFile("Back.png"))
        cout << "Can't find the image" << endl;
    BackButtonImage.setPosition(20.0f, 20.0f);
    BackButtonImage.setScale(0.55, 0.55);
    float BackButtonWidth = BackButtonImage.getLocalBounds().width;
    float BackButtonHeight = BackButtonImage.getLocalBounds().height;

    BackButtonImage.setTexture(BackButton);

    /*------------------------------------------------END OF BOUNDS AND TEXTURES FOR BUTTONS------------------------------------------------*/


    /*------------------------------------------------EVENT FOR COLOR CHANGE ON HOVER OVER BUTTONS------------------------------------------------*/
    while (window.isOpen())
    {
        Event Event;

        while (window.pollEvent(Event))
        {
            switch (Event.type)
            {
            case Event::Closed:
                window.close();
                break;
            case Event::MouseMoved:
            {
                Vector2i mousePos = Mouse::getPosition(window);
                Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                if (BackButtonImage.getGlobalBounds().contains(mousePosF))
                {
                    BackButtonImage.setColor(Color(255, 229, 204));
                }
                else
                {
                    BackButtonImage.setColor(Color(255, 255, 255));
                }
                break;
            }
            /*------------------------------------------------END OF EVENT FOR COLOR CHANGE ON HOVER OVER BUTTONS------------------------------------------------*/


            /*------------------------------------------------EVENT FOR MOUSE BUTTON PRESS ON BUTTONS------------------------------------------------*/
            case (Event::MouseButtonPressed):
            {
                if (Event.mouseButton.button == Mouse::Left)
                {
                    Vector2i mousePos = Mouse::getPosition(window);
                    Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                    if (BackButtonImage.getGlobalBounds().contains(mousePosF))
                    {
                        window.close();
                        AdmDash();

                    }
                }
            } /*------------------------------------------------END OF EVENT FOR MOUSE BUTTON PRESS ON BUTTONS------------------------------------------------*/
            }

            /*------------------------------------------------DRAWING SPRITES ON THE SCREEN------------------------------------------------*/
            window.clear();
            window.draw(backgroundImage);
            window.draw(BackButtonImage);
            window.display();
            /*------------------------------------------------END OF DRAWING SPRITES ON THE SCREEN------------------------------------------------*/

        }
    }

    return;
}