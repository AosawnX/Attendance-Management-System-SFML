#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include <string>
#include <iostream> 
#include <random>
#include "LoginAs.h"
#include "AboutUs.h"
#include"AdminLogin.h"
#include "AdminDash.h"
#include"FacDash.h"
#include"FacSignup.h"
#include"FacRegistration.h"
#include"Recaptcha test.h"
#include"Security.h"

/*----------------------------------------------Prototypes----------------------------------------------*/
void loginAs();
int FaceCap();
/*----------------------------------------------Prototypes----------------------------------------------*/

using namespace sf;
using namespace std;
void HomePage()
{
    /*----------------------------------------------RenderWindow----------------------------------------------*/
    RenderWindow window(VideoMode(1340, 760), "Attendance System", Style::Close | Style::Titlebar);
    window.setFramerateLimit(60);
    /*----------------------------------------------RenderWindow----------------------------------------------*/

    /*----------------------------------------------Textures and Sprites----------------------------------------------*/
    Texture background;
    Sprite backgroundImage;

    if (!background.loadFromFile("bckgnd2.png"))
        cout << "Error: Could not display image" << endl;

    backgroundImage.setTexture(background);

    Font font;
    if (!font.loadFromFile("Blanka-Regular.otf"))
        cout << "Can't find the font file" << endl;

    Texture ProceedButton;
    Sprite ProceedButtonImage;
    if (!ProceedButton.loadFromFile("login.png"))
        cout << "Can't find the image" << endl;
    ProceedButtonImage.setPosition(120.0f, 600.0f);

    Texture InfoButton;
    Sprite InfoButtonImage;
    if (!InfoButton.loadFromFile("My project (3).png"))
        cout << "Can't find the image" << endl;
    InfoButtonImage.setPosition(520.0f, 600.0f);

    Texture QuitButton;
    Sprite QuitButtonImage;
    if (!QuitButton.loadFromFile("quit.png"))
        cout << "Can't find the image" << endl;
    QuitButtonImage.setPosition(920.0f, 600.0f);

    float ProceedButtonWidth = ProceedButtonImage.getLocalBounds().width;
    float ProceedButtonHeight = ProceedButtonImage.getLocalBounds().height;

    ProceedButtonImage.setTexture(ProceedButton);

    float InfoButtonWidth = InfoButtonImage.getLocalBounds().width;
    float InfoButtonHeight = InfoButtonImage.getLocalBounds().height;

    InfoButtonImage.setTexture(InfoButton);

    float QuitButtonWidth = QuitButtonImage.getLocalBounds().width;
    float QuitButtonHeight = QuitButtonImage.getLocalBounds().height;

    QuitButtonImage.setTexture(QuitButton);
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
                if (ProceedButtonImage.getGlobalBounds().contains(mousePosF))
                {
                    ProceedButtonImage.setColor(Color(255, 229, 204));
                }
                else
                {
                    ProceedButtonImage.setColor(Color(255, 255, 255));
                }
                if (InfoButtonImage.getGlobalBounds().contains(mousePosF))
                {
                    InfoButtonImage.setColor(Color(255, 229, 204));
                }
                else
                {
                    InfoButtonImage.setColor(Color(255, 255, 255));
                }
                if (QuitButtonImage.getGlobalBounds().contains(mousePosF))
                {
                    QuitButtonImage.setColor(Color(255, 229, 204));
                }
                else
                {
                    QuitButtonImage.setColor(Color(255, 255, 255));
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
                    if (ProceedButtonImage.getGlobalBounds().contains(mousePosF))
                    {
                        window.close();
                        loginAs();
                    }
                    if (InfoButtonImage.getGlobalBounds().contains(mousePosF))
                    {
                        window.close();
                        aboutus();
                    }
                    if (QuitButtonImage.getGlobalBounds().contains(mousePosF))
                    {
                        window.close();
                    }
                }
            } /*------------------------------------------------END OF EVENT FOR MOUSE BUTTON PRESS ON BUTTONS------------------------------------------------*/
            }

            /*------------------------------------------------DRAWING SPRITES ON THE SCREEN------------------------------------------------*/
            window.clear();
            window.draw(backgroundImage);
            window.draw(ProceedButtonImage);
            window.draw(InfoButtonImage);
            window.draw(QuitButtonImage);

            window.display();
            /*------------------------------------------------END OF DRAWING SPRITES ON THE SCREEN------------------------------------------------*/

        }
    }

    return;
}