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
#include "FacLogin.h"
#include"FacRegistration.h"


/*--------------Prototypes------------*/
int FacDash();
int FacReg();
void loginAs();
/*--------------Prototypes------------*/


using namespace sf;
using namespace std;
void FacSignup()
{
	/*----------------------------------------------RenderWindow----------------------------------------------*/
	RenderWindow window(VideoMode(1340, 760), "Faculty Sign-Up", Style::Close | Style::Titlebar);
	window.setFramerateLimit(60);
	/*----------------------------------------------RenderWindow----------------------------------------------*/

	/*----------------------------------------------Textures and Sprites----------------------------------------------*/
	Texture background;
	Sprite backgroundImage;

	if (!background.loadFromFile("FacSignup.png"))
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


	Texture LoginButton;
	Sprite LoginButtonImage;
	if (!LoginButton.loadFromFile("login.png"))
		cout << "Can't find the image" << endl;


	Texture RegisterButton;
	Sprite RegisterButtonImage;
	if (!RegisterButton.loadFromFile("Register.png"))
		cout << "Can't find the image" << endl;

	RegisterButtonImage.setPosition(515.0f, 480.0f);

	float RegisterButtonWidth = RegisterButtonImage.getLocalBounds().width;
	float RegisterButtonHeight = RegisterButtonImage.getLocalBounds().height;

	RegisterButtonImage.setTexture(RegisterButton);

	float LoginButtonWidth = LoginButtonImage.getLocalBounds().width;
	float LoginButtonHeight = LoginButtonImage.getLocalBounds().height;
	LoginButtonImage.setPosition(515.0f, 320.0f);

	LoginButtonImage.setTexture(LoginButton);
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
				if (LoginButtonImage.getGlobalBounds().contains(mousePosF))
				{
					LoginButtonImage.setColor(Color(255, 229, 204));
				}
				else
				{
					LoginButtonImage.setColor(Color(255, 255, 255));
				}
				if (RegisterButtonImage.getGlobalBounds().contains(mousePosF))
				{
					RegisterButtonImage.setColor(Color(255, 229, 204));
				}
				else
				{
					RegisterButtonImage.setColor(Color(255, 255, 255));
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
					if (LoginButtonImage.getGlobalBounds().contains(mousePosF))
					{
						cout << "Login button pressed";
						window.close();
						Faclogin();

					}
					if (BackButtonImage.getGlobalBounds().contains(mousePosF))
					{
						window.close();
						loginAs();
					}
				}
			} /*------------------------------------------------END OF EVENT FOR MOUSE BUTTON PRESS ON BUTTONS------------------------------------------------*/
			}

			/*------------------------------------------------DRAWING SPRITES ON THE SCREEN------------------------------------------------*/
			window.clear();
			window.draw(backgroundImage);
			window.draw(BackButtonImage);
			window.draw(LoginButtonImage);
			window.display();
			/*------------------------------------------------END OF DRAWING SPRITES ON THE SCREEN------------------------------------------------*/

		}
	}

	return;
}