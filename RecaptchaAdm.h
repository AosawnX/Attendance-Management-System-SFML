#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include <string>
#include <iostream> 
#include <random>
#include"Recaptcha test.h"

using namespace sf;
using namespace std;
void RecaptchaAdmin()
{
    /*--------------------------------------------RenderWindow----------------------------------------------*/

    RenderWindow Recwindow(VideoMode(1340, 760), "Recaptcha Page", Style::Close | Style::Titlebar);

    /*--------------------------------------------RenderWindow----------------------------------------------*/

     /*--------------------------------------------Textures and Sprites----------------------------------------------*/
    Texture background;
    Sprite backgroundImage;

    if (!background.loadFromFile("RecaptchaPg.png"))
        cout << "Error: Could not display image" << endl;

    backgroundImage.setTexture(background);

    Texture BackButton;
    Sprite BackButtonImage;
    if (!BackButton.loadFromFile("Back.png"))
        cout << "Can't find the image" << endl;
    BackButtonImage.setPosition(40.0f, 30.0f);
    BackButtonImage.setScale(0.55, 0.55);

    float BackButtonWidth = BackButtonImage.getLocalBounds().width;
    float BackButtonHeight = BackButtonImage.getLocalBounds().height;

    BackButtonImage.setTexture(BackButton);

    Texture VerifyButton;
    Sprite VerifyButtonImage;
    if (!VerifyButton.loadFromFile("Back.png"))
        cout << "Can't find the image" << endl;
    VerifyButtonImage.setPosition(400.0f, 500.0f);
    VerifyButtonImage.setScale(0.55, 0.55);

    float VerifyButtonWidth = VerifyButtonImage.getLocalBounds().width;
    float VerifyButtonHeight = VerifyButtonImage.getLocalBounds().height;

    VerifyButtonImage.setTexture(VerifyButton);
    /*--------------------------------------------Textures and Sprites----------------------------------------------*/

    /*------------------------------------------------END OF BOUNDS AND TEXTURES FOR BUTTONS------------------------------------------------*/


    /*------------------------------------------------EVENT FOR COLOR CHANGE ON HOVER OVER BUTTONS------------------------------------------------*/
    while (Recwindow.isOpen())
    {
        Event Event;

        while (Recwindow.pollEvent(Event))
        {
            switch (Event.type)
            {
            case Event::Closed:
                Recwindow.close();
                break;
            case Event::MouseMoved:
            {
                Vector2i mousePos = Mouse::getPosition(Recwindow);
                Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                if (BackButtonImage.getGlobalBounds().contains(mousePosF))
                {
                    BackButtonImage.setColor(Color(255, 229, 204));
                }
                else
                {
                    BackButtonImage.setColor(Color(255, 255, 255));
                }
                if (VerifyButtonImage.getGlobalBounds().contains(mousePosF))
                {
                    VerifyButtonImage.setColor(Color(255, 229, 204));
                }
                else
                {
                    VerifyButtonImage.setColor(Color(255, 255, 255));
                }
                break;
            }
            /*------------------------------------------------END OF EVENT FOR COLOR CHANGE ON HOVER OVER BUTTONS------------------------------------------------*/


            /*------------------------------------------------EVENT FOR MOUSE BUTTON PRESS ON BUTTONS------------------------------------------------*/
            case (Event::MouseButtonPressed):
            {
                if (Event.mouseButton.button == Mouse::Left)
                {
                    Vector2i mousePos = Mouse::getPosition(Recwindow);
                    Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                    if (BackButtonImage.getGlobalBounds().contains(mousePosF))
                    {
                        Recwindow.close();
                        loginAs();

                    }
                    if (VerifyButtonImage.getGlobalBounds().contains(mousePosF))
                    {

                        Recwindow.close();
                        recaptcha(); //verification function
                    }
                }
            } /*------------------------------------------------END OF EVENT FOR MOUSE BUTTON PRESS ON BUTTONS------------------------------------------------*/
            }

            /*------------------------------------------------DRAWING SPRITES ON THE SCREEN------------------------------------------------*/
            Recwindow.clear();
            Recwindow.draw(backgroundImage);
            Recwindow.draw(BackButtonImage);
            //Recwindow.draw(VerifyButtonImage);
            Recwindow.display();
            /*------------------------------------------------END OF DRAWING SPRITES ON THE SCREEN------------------------------------------------*/

        }
    }

    return;
}