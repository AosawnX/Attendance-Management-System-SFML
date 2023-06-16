#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include <string>
#include <iostream> 
#include <random>
#include "AdminLogin.h"
#include"FacSignup.h"
#include"Recaptcha test.h"
#include"RecaptchaAdm.h"
#include"HomePage.h"
/*--------------Prototypes------------*/
int FacDash();
void HomePage();
/*--------------Prototypes------------*/

using namespace sf;
using namespace std;
void loginAs()
{
    /*----------------------------------------------RenderWindow----------------------------------------------*/
    RenderWindow window(VideoMode(1340, 760), "Login Page", Style::Close | Style::Titlebar);
    window.setFramerateLimit(60);
    /*----------------------------------------------RenderWindow----------------------------------------------*/

     /*----------------------------------------------Textures and Sprites----------------------------------------------*/
    Texture background;
    Sprite backgroundImage;

    if (!background.loadFromFile("Login as.png"))
        cout << "Error: Could not display image" << endl;

    backgroundImage.setTexture(background);

    Font font;
    if (!font.loadFromFile("Blanka-Regular.otf"))
        cout << "Can't find the font file" << endl;

    Texture FacultyButton;
    Sprite FacultyButtonImage;
    if (!FacultyButton.loadFromFile("faculty.png"))
        cout << "Can't find the image" << endl;
    FacultyButtonImage.setPosition(784.0f, 530.0f);

    Texture AdminButton;
    Sprite AdminButtonImage;
    if (!AdminButton.loadFromFile("My project.png"))
        cout << "Can't find the image" << endl;

    AdminButtonImage.setPosition(285.0f, 530.0f);

    float FacultyButtonWidth = FacultyButtonImage.getLocalBounds().width;
    float FacultyButtonHeight = FacultyButtonImage.getLocalBounds().height;

    FacultyButtonImage.setTexture(FacultyButton);

    float AdminButtonWidth = AdminButtonImage.getLocalBounds().width;
    float AdminButtonHeight = AdminButtonImage.getLocalBounds().height;

    AdminButtonImage.setTexture(AdminButton);


    Texture BackButton;
    Sprite BackButtonImage;
    if (!BackButton.loadFromFile("Back.png"))
        cout << "Can't find the image" << endl;
    BackButtonImage.setPosition(20.0f, 20.0f);
    BackButtonImage.setPosition(20, 20);
    BackButtonImage.setScale(0.55, 0.55);

    float BackButtonWidth = BackButtonImage.getLocalBounds().width;
    float BackButtonHeight = BackButtonImage.getLocalBounds().height;

    BackButtonImage.setTexture(BackButton);

    /*----------------------------------------------Textures and Sprites----------------------------------------------*/



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
                if (FacultyButtonImage.getGlobalBounds().contains(mousePosF))
                {
                    FacultyButtonImage.setColor(Color(255, 229, 204));
                }
                else
                {
                    FacultyButtonImage.setColor(Color(255, 255, 255));
                }
                if (AdminButtonImage.getGlobalBounds().contains(mousePosF))
                {
                    AdminButtonImage.setColor(Color(255, 229, 204));
                }
                else
                {
                    AdminButtonImage.setColor(Color(255, 255, 255));
                }
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
                    if (FacultyButtonImage.getGlobalBounds().contains(mousePosF))
                    {
                        b2 = true; //Tells recaptcha where to go after verification
                        window.close();
                        RecaptchaAdmin();
                    }
                    if (AdminButtonImage.getGlobalBounds().contains(mousePosF))
                    {
                        b1 = true;
                        window.close();
                        RecaptchaAdmin();
                    }
                    if (BackButtonImage.getGlobalBounds().contains(mousePosF))
                    {
                        window.close();
                        HomePage();
                    }
                }
            } /*------------------------------------------------END OF EVENT FOR MOUSE BUTTON PRESS ON BUTTONS------------------------------------------------*/
            }

            /*------------------------------------------------DRAWING SPRITES ON THE SCREEN------------------------------------------------*/
            window.clear();
            window.draw(backgroundImage);
            window.draw(FacultyButtonImage);
            window.draw(AdminButtonImage);
            window.draw(BackButtonImage);
            window.display();
            /*------------------------------------------------END OF DRAWING SPRITES ON THE SCREEN------------------------------------------------*/

        }
    }

    return;
}