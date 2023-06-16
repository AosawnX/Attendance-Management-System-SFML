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
#include"FacDash.h"
#include"FacRegistration.h"

void loginAs();//Prototype
using namespace sf;
using namespace std;

/*-----------------------------------------------Classes------------------------------------------------*/
class sscn2
{
public:
	bool email = false;
	bool password = false;
};

class sscn3
{
public:
	bool email = false;
	bool confirmEmail = false;
	bool password = false;
	bool confirmPassword = false;
};

class accountt
{
public:
	string email;
	string password;
};
/*-----------------------------------------------Classes------------------------------------------------*/

/*-----------------------------------------------Global Variables------------------------------------------------*/
int sscene = 1, r = 1;
sscn2 sscene2;
sscn3 sscene3;
accountt acci[100];
bool firstt = true;
/*-----------------------------------------------Global Variables------------------------------------------------*/

/*-----------------------------------------------Read From File Function------------------------------------------------*/
void Faccinput()
{
	ifstream fin("faclogin.txt", ios::beg | ios::app);
	while (fin >> acci[r].email)
	{
		fin >> acci[r].password;
		r++;
	}
	fin.close();
}
/*-----------------------------------------------Read From File Function------------------------------------------------*/

int Faclogin()
{
	/*-----------------------------------------------Render Window------------------------------------------------*/
	RenderWindow window(VideoMode(1340, 760), "Faculty Login", Style::Close | Style::Titlebar);
	/*-----------------------------------------------Render Window------------------------------------------------*/

	/*-----------------------------------------------Textures and Sprites------------------------------------------------*/
	Texture t1, t2, t3, t4, t5, t6, t7, t8, t9;

	t1.loadFromFile("Login.png");
	t2.loadFromFile("atten-S.png");
	t3.loadFromFile("Email.png");
	t4.loadFromFile("Password.png");
	t5.loadFromFile("Submit.png");
	t6.loadFromFile("Back.png");
	t7.loadFromFile("ConfirmEmail.png");
	t8.loadFromFile("ConfirmPassword.png");
	t9.loadFromFile("LoginOk.png");

	Sprite loginn(t1);
	Sprite registerr(t2);
	Sprite Email(t3);
	Sprite Password(t4);
	Sprite Submit(t5);
	Sprite Back(t6);
	Sprite ConfirmEmail(t7);
	Sprite ConfirmPassword(t8);
	Sprite LoginOK(t9);
	Texture background;
	Sprite backgroundImage;

	registerr.setScale(0.5, 0.5);

	if (!background.loadFromFile("Faclog.png"))
		cout << "Error: Could not display image" << endl;

	backgroundImage.setTexture(background);


	Font arial;
	arial.loadFromFile("OsMed.ttf");
	/*-----------------------------------------------Textures and Sprites------------------------------------------------*/

	/*-----------------------------------------------TextBoses------------------------------------------------*/

	Textbox textLoginEmail(30, Color::Black, false);
	textLoginEmail.setFont(arial);
	Textbox textLoginPassword(30, Color::Black, false);
	textLoginPassword.setFont(arial);
	Textbox textRegisterEmail(30, Color::White, false);
	textRegisterEmail.setFont(arial);
	Textbox textRegisterConfirmEmail(30, Color::White, false);
	textRegisterConfirmEmail.setFont(arial);
	Textbox textRegisterPassword(30, Color::White, false);
	textRegisterPassword.setFont(arial);
	Textbox textRegisterConfirmPassword(30, Color::White, false);
	textRegisterConfirmPassword.setFont(arial);

	/*-----------------------------------------------TextBoses------------------------------------------------*/

	Faccinput();

	/*-----------------------------------------------Events------------------------------------------------*/
	while (window.isOpen())
	{
		if (firstt == true)
		{
			firstt = false;
		}
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
			{
				window.close();
			}
			/*-----------------------------------------------Event MouseButtonPressed------------------------------------------------*/
			if (e.type == Event::MouseButtonPressed)
			{
				if (e.mouseButton.button == Mouse::Left)
				{
					int x = e.mouseButton.x;
					int y = e.mouseButton.y;
					if (sscene == 1)
					{
						sscene = 2;
					}
					if (sscene == 2)
					{
						Vector2i mousePos = Mouse::getPosition(window);
						Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
						// back
						if (Back.getGlobalBounds().contains(mousePosF))
						{
							window.close();
							loginAs();
						}
						if (Email.getGlobalBounds().contains(mousePosF))
						{
							// click on email
							sscene2.email = true;
							textLoginEmail.setSelected(true);
						}
						if (Password.getGlobalBounds().contains(mousePosF))
						{
							//click on password
							sscene2.password = true;
							textLoginPassword.setSelected(true);
						}
						// submit
						if (Submit.getGlobalBounds().contains(mousePosF))
						{
							string e, p;
							e = textLoginEmail.getText();
							p = textLoginPassword.getText();

							if (!e.empty() && !p.empty())
							{
								for (int j = 1; j <= 100; j++)
								{
									if (e == acci[j].email && p == acci[j].password)
									{

										sscene = 4;
									}
									if (e != acci[j].email && p != acci[j].password)
									{

										cout << " button not pressed";
									}
								}
							}
						}
					}


				}
			}
			/*-----------------------------------------------Event MouseButtonPressed------------------------------------------------*/

			/*-----------------------------------------------Event TextEntered------------------------------------------------*/
			if (e.type == Event::TextEntered)
			{
				if (sscene == 2)
				{
					if (sscene2.email == true)
					{
						if (e.text.unicode == '\r')
						{
							textLoginEmail.setSelected(false);
							sscene2.email = false;
						}
						else
						{
							textLoginEmail.typedOn(e);
						}
					}
					else if (sscene2.password == true)
					{
						if (e.text.unicode == '\r')
						{
							textLoginPassword.setSelected(false);
							sscene2.password = false;
						}
						else
						{
							textLoginPassword.typedOn(e);
						}
					}
				}

			}
			/*-----------------------------------------------Event TextEntered------------------------------------------------*/
		}
		/*-----------------------------------------------Events------------------------------------------------*/

		/*-----------------------------------------------Drawing Sprites------------------------------------------------*/
		window.clear(Color(104, 167, 92));
		window.draw(backgroundImage);
		if (sscene == 2)
		{
			Submit.setPosition(490, 575);
			Password.setPosition(210, 480);
			Email.setPosition(200, 290);
			Back.setPosition(20, 20);
			Back.setScale(0.55, 0.55);
			window.draw(Back);
			textLoginEmail.setPosition({ 220,290 });
			textLoginEmail.drawTo(window);
			textLoginPassword.setPosition({ 220,490 });
			textLoginPassword.drawTo(window);
		}
		if (sscene == 4)
		{
			cout << " login";
			LoginOK.setPosition(575, 300);
			window.draw(LoginOK);
			window.close();
			FacDash();
		}

		window.display();
		/*-----------------------------------------------Drawing Sprites------------------------------------------------*/


	}
	return 0;
}