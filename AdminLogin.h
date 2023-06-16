#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include <string>
#include <iostream> 
#include <random>
#include <fstream>
#include"AdminDash.h"
#include"TextBox.h"
#include"Security.h"
#include"LoginAs.h"
#include"Warning.h"

/*-------------------------------------------Namespace and Prototype-------------------------------------------*/
using namespace sf;
void loginAs();

/*-------------------------------------------Classes for accounts-------------------------------------------*/
class Scn2 {
public:
	bool email = false;
	bool password = false;
};

class Scn3 : public Scn2 {
public:
	bool confirmEmail = false;
	bool confirmPassword = false;
};

class account
{
public:
	string email;
	string password;
};
/*-------------------------------------------END OF CLASSES FOR ACCOUNTS-------------------------------------------*/

int scene = 1, i = 1;
Scn2 scene2;
Scn3 scene3;
account acc[100];
bool first = true;

/*-------------------------------------------Read from file-------------------------------------------*/
void input()
{
	std::ifstream fin("Admlogin.txt", std::ios::in | std::ios::app);
	while (fin >> acc[i].email)
	{
		fin >> acc[i].password;
		i++;
	}
	fin.close();
}

/*-------------------------------------------ADMIN LOGIN FXN-------------------------------------------*/
int admin()
{
	int count = 0;
	int x = 0;

	RenderWindow admwindow(VideoMode(1340, 760), "Admin Login", Style::Close | Style::Titlebar);
	admwindow.setFramerateLimit(60);

	/*-------------------------------------------LOADING TEXTURES-------------------------------------------*/
	Texture t1, t2, t3, t4, t5, t6, t7, t8, t9;
	t1.loadFromFile("Login.png");
	//t2.loadFromFile("atten-S.png");
	t3.loadFromFile("Email.png");
	t4.loadFromFile("Password.png");
	t5.loadFromFile("Submit.png");
	t6.loadFromFile("Back.png"); 
	t7.loadFromFile("ConfirmEmail.png");
	t8.loadFromFile("ConfirmPassword.png");
	t9.loadFromFile("LogSuc.png");
	/*-------------------------------------------END OF LOADING TEXTURES-------------------------------------------*/


	/*-------------------------------------------LOADING SPRITES-------------------------------------------*/
	Sprite login(t1);
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

	/*-------------------------------------------START OF PAGES AND FONT-------------------------------------------*/
	registerr.setScale(0.5, 0.5);
	if (!background.loadFromFile("Admlog.png"))
		cout << "Error: Could not display image" << endl;
	backgroundImage.setTexture(background);
	Font arial;
	arial.loadFromFile("OsMed.ttf");
	/*-------------------------------------------END OF PAGES AND FONT-------------------------------------------*/


	/*-------------------------------------------START OF TEXTBOXES-------------------------------------------*/
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
	/*-------------------------------------------START OF TEXTBOXES-------------------------------------------*/


	input(); //reads input from file made previously

	std::ofstream fout("Admlogin.txt", std::ios::app);

	/*-------------------------------------------START OF EVENTS OF SCENES-------------------------------------------*/
	while (admwindow.isOpen())
	{
		Event e;
		while (admwindow.pollEvent(e))
		{
			if (e.type == Event::Closed)
			{
				admwindow.close();
			}
			if (e.type == Event::MouseButtonPressed)
			{
				if (e.mouseButton.button == Mouse::Left)
				{
					int x = e.mouseButton.x;
					int y = e.mouseButton.y;
					if (scene == 1)
					{
						scene = 2;
					}
					if (scene == 2)
					{
						Vector2i mousePos = Mouse::getPosition(admwindow);
						Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
						// back
						if (Back.getGlobalBounds().contains(mousePosF))
						{
							admwindow.close();
							loginAs();
						}
						if (Email.getGlobalBounds().contains(mousePosF))
						{
							// lick on email. Highlights email textbox
							scene2.email = true;
							textLoginEmail.setSelected(true);
						}
						if (Password.getGlobalBounds().contains(mousePosF))
						{
							//click on password, highlights password textbox
							scene2.password = true;
							textLoginPassword.setSelected(true);
						}
						// submit
						if (Submit.getGlobalBounds().contains(mousePosF))
						{
							std::string e, p;
							e = textLoginEmail.getText();
							p = textLoginPassword.getText();

							if (!e.empty() && !p.empty())
							{
								for (int j = 1; j <= 100; j++)
								{
									if (e == acc[j].email && p == acc[j].password)
									{
										count = 0;
										scene = 4;
									}
									if (e != acc[j].email && p != acc[j].password)
									{
										x = 4;
									}
								}
								//incorrect password condition
								if (x == 4) {
									count++;
									if (count >= 5) {
										cout << "Face captured";
										displayWarningDialog(admwindow);
									}
								}
							}
						}
					}

				}
			}
			if (e.type == Event::TextEntered)
			{
				if (scene == 2)
				{
					if (scene2.email == true)
					{
						if (e.text.unicode == '\r') //checks if user is done entering in the text field
						{
							textLoginEmail.setSelected(false);
							scene2.email = false;
						}
						else
						{
							textLoginEmail.typedOn(e);
						}
					}
					else if (scene2.password == true)
					{
						if (e.text.unicode == '\r') //checks if user is done entering in the text field
						{
							textLoginPassword.setSelected(false);
							scene2.password = false;
						}
						else
						{
							textLoginPassword.typedOn(e);
						}
					}
				}

			}
		}
		/*-------------------------------------------START OF DRAWING SPRITES-------------------------------------------*/
		admwindow.clear(Color(104, 167, 92));
		admwindow.draw(backgroundImage);
		if (scene == 2)
		{
			Submit.setPosition(490, 575);
			Password.setPosition(210, 480);
			Email.setPosition(200, 290);
			Back.setPosition(20, 20);
			Back.setScale(0.55, 0.55);
			admwindow.draw(Back);
			textLoginEmail.setPosition({ 220,308 });
			textLoginEmail.drawTo(admwindow);
			textLoginPassword.setPosition({ 220,480 });
			textLoginPassword.drawTo(admwindow);
		}
		if (scene == 4)
		{
			LoginOK.setPosition(575, 300);
			admwindow.draw(LoginOK);
			
			admwindow.close();
			AdmDash();
		}
		admwindow.display();
	}
	/*-------------------------------------------END OF DRAWING SPRITES-------------------------------------------*/
	return 0;
}