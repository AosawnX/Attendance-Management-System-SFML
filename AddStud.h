#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include <string>
#include <iostream> 
#include <random>
#include <fstream>
#include"TextBox.h"
#include"AdminDash.h"
#include"FacAtt.h"

using namespace sf;
using namespace std;

void AdmDash();
int Faclogin();
void FacSignup();

/*-----------------------------------------------------------------------------------------Classes-----------------------------------------------------------------------------*/

class iscnn2
{
public:
	bool email = false;
	bool password = false;
};

class iscnn3
{
public:
	bool email = false;
	bool confirmEmail = false;
	bool password = false;
	bool confirmPassword = false;
	bool name = false;
	bool ID = false;
	bool designation = false;
};

class iaaccount
{
public:
	std::string email;
	std::string password;
};

/*-----------------------------------------------------------------------------------------Classes-----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------Global Variables-----------------------------------------------------------------------------*/
int iscenee = 1, u = 1;
iscnn2 sceneee2;//GLOBAL OBJECTS
iscnn3 sceneee3;
iaaccount ifacacc[100];
bool iffirst = true;

/*------------------------------------------------------------------------------------Global Variables-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------Read From File Function-----------------------------------------------------------------------------*/
void inputsacc()
{
	std::ifstream fin("StudLogin.txt", std::ios::in | std::ios::app);
	while (fin >> ifacacc[u].email)
	{
		fin >> ifacacc[u].password;
		u++;
	}
	fin.close();
}

/*-----------------------------------------------------------------------------Read From File Function-----------------------------------------------------------------------------*/

int StudReg()
{
	/*-----------------------------------------------------------------------------Window Rendered-----------------------------------------------------------------------------*/
	RenderWindow window(VideoMode(1340, 760), "Student Registration", Style::Close | Style::Titlebar);

	window.setFramerateLimit(60);

	/*-----------------------------------------------------------------------------Window Rendered-----------------------------------------------------------------------------*/

	/*-----------------------------------------------------------------------------Textures-----------------------------------------------------------------------------*/
	Texture t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12;

	t1.loadFromFile("Login.png");
	t2.loadFromFile("Register.png");
	t3.loadFromFile("Email.png");
	t4.loadFromFile("Password.png");
	t5.loadFromFile("Register.png");
	t6.loadFromFile("Back.png");
	t7.loadFromFile("ConfirmEmail.png");
	t8.loadFromFile("ConfirmPassword.png");
	t9.loadFromFile("LogSuc.png");
	t10.loadFromFile("Email.png");
	t11.loadFromFile("Password.png");
	t12.loadFromFile("Email.png");

	/*-----------------------------------------------------------------------------Textures-----------------------------------------------------------------------------*/

	/*-----------------------------------------------------------------------------Sprites-----------------------------------------------------------------------------*/

	Sprite login(t1);
	Sprite registerr(t2);
	Sprite Email(t3);
	Sprite Password(t4);
	Sprite Submit(t5);
	Sprite Back(t6);
	Sprite ConfirmEmail(t7);
	Sprite ConfirmPassword(t8);
	Sprite LoginOK(t9);
	Sprite Name(t10);
	Sprite ID(t11);
	Sprite Designation(t12);
	Texture background;
	Sprite backgroundImage;

	registerr.setScale(0.5, 0.5);
	Submit.setScale(0.6, 0.6);

	if (!background.loadFromFile("studregpg.png"))
		cout << "Error: Could not display image" << endl;

	backgroundImage.setTexture(background);

	Font arial;
	arial.loadFromFile("Arial.ttf");

	/*-----------------------------------------------------------------------------Sprites-----------------------------------------------------------------------------*/

	/*-----------------------------------------------------------------------------TextBoxes-----------------------------------------------------------------------------*/

	Textbox textLoginEmail(30, Color::Black, false);
	textLoginEmail.setFont(arial);
	Textbox textLoginPassword(30, Color::Black, false);
	textLoginPassword.setFont(arial);
	Textbox textRegisterBatch(30, Color::Black, false);
	textRegisterBatch.setFont(arial);
	Textbox textRegisterCourse(30, Color::Black, false);
	textRegisterCourse.setFont(arial);
	Textbox textRegisterSemester(30, Color::Black, false);
	textRegisterSemester.setFont(arial);
	Textbox textRegisterName(30, sf::Color::Black, false);
	textRegisterName.setFont(arial);
	Textbox textRegisterAge(30, sf::Color::Black, false);
	textRegisterAge.setFont(arial);
	Textbox textRegisterDepartment(30, sf::Color::Black, false);
	textRegisterDepartment.setFont(arial);

	/*-----------------------------------------------------------------------------TextBoxes-----------------------------------------------------------------------------*/

	inputsacc();//Input READ Function

	/*-----------------------------------------------------------------------------Write in File-----------------------------------------------------------------------------*/

	std::ofstream fout("StudLogin.txt", std::ios::app);
	std::ofstream foutDetails("StudDets.txt");
	/*-----------------------------------------------------------------------------Write in File-----------------------------------------------------------------------------*/

	/*-----------------------------------------------------------------------------Events-----------------------------------------------------------------------------*/

	while (window.isOpen())
	{
		if (iffirst == true)
		{
			for (int j = 1; j < u; j++)
			{
				fout << ifacacc[j].email << "\n";
				fout << ifacacc[j].password << "\n";
			}
			iffirst = false;
		}


		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
			{
				window.close();
			}
			if (e.type == Event::MouseButtonPressed)
			{
				/*----------------------------------------------------------------------Events Mousebutton-----------------------------------------------------------------------------*/
				if (e.mouseButton.button == Mouse::Left)
				{
					int x = e.mouseButton.x;
					int y = e.mouseButton.y;
					if (iscenee == 1)
					{
						iscenee = 3;
					}
					if (iscenee == 3)
					{
						Vector2i mousePos = Mouse::getPosition(window);
						Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
						// back
						if (Back.getGlobalBounds().contains(mousePosF))
						{
							window.close();
							AdmDash();
						}
						// email
						if (Email.getGlobalBounds().contains(mousePosF))
						{
							scenee3.email = true;
							textRegisterBatch.setSelected(true);
						}
						// confirm email
						if (ConfirmEmail.getGlobalBounds().contains(mousePosF))
						{
							scenee3.confirmEmail = true;
							textRegisterCourse.setSelected(true);
						}
						// password
						if (Password.getGlobalBounds().contains(mousePosF))
						{
							scenee3.password = true;
							textRegisterSemester.setSelected(true);
						}
						// name
						if (Name.getGlobalBounds().contains(mousePosF))
						{
							scenee3.name = true;
							textRegisterName.setSelected(true);
						}
						// ID
						if (ID.getGlobalBounds().contains(mousePosF))
						{
							scenee3.ID = true;
							textRegisterAge.setSelected(true);
						}
						// designation
						if (Designation.getGlobalBounds().contains(mousePosF))
						{
							scenee3.designation = true;
							textRegisterDepartment.setSelected(true);
						}


						// submit
						if (Submit.getGlobalBounds().contains(mousePosF))
						{
							std::cout << "1 button pressed";
							std::string e, ce, p, cp;
							e = textRegisterBatch.getText();
							ce = textRegisterCourse.getText();
							p = textRegisterSemester.getText();
							if (!e.empty() && !ce.empty() && !p.empty() && !cp.empty())
							{
								std::cout << "2 button pressed";
								fout << e << "\n";
								if (e == ce && p == cp)
								{
									fout << p << "\n";
								}

								/*----------------------------------------------------------------------Write to File-----------------------------------------------------------------------------*/
								std::string name = textRegisterName.getText();
								std::string ID = textRegisterAge.getText();
								std::string designation = textRegisterDepartment.getText();

								ofstream namefile("Name.txt", ios::app);
								namefile << name << endl;

								foutDetails << "Name: " << name << "\n";
								foutDetails << "ID: " << ID << "\n";
								foutDetails << "Designation: " << designation << "\n";
								attendanceSystem.addFaculty(name, ID, designation);
								fout.close();
								foutDetails.close();
								/*----------------------------------------------------------------------Write to File-----------------------------------------------------------------------------*/
							}
							window.close();
							AdmDash();
						}
					}
				}
			}
			/*----------------------------------------------------------------------Events Mousebutton-----------------------------------------------------------------------------*/

			/*----------------------------------------------------------------------Events Text Entered-----------------------------------------------------------------------------*/
			if (e.type == Event::TextEntered)
			{
				if (iscenee == 3)
				{
					if (scenee3.email == true)
					{
						if (e.text.unicode == '\r')
						{
							textRegisterBatch.setSelected(false);
							scenee3.email = false;
						}
						else
						{
							textRegisterBatch.typedOn(e);
						}
					}
					else if (scenee3.confirmEmail == true)
					{
						if (e.text.unicode == '\r')
						{
							textRegisterCourse.setSelected(false);
							scenee3.confirmEmail = false;
						}
						else
						{
							textRegisterCourse.typedOn(e);
						}
					}
					else if (scenee3.password == true)
					{
						if (e.text.unicode == '\r')
						{
							textRegisterSemester.setSelected(false);
							scenee3.password = false;
						}
						else
						{
							textRegisterSemester.typedOn(e);
						}
					}
					else if (scenee3.name == true)
					{
						if (e.text.unicode == '\r')
						{
							textRegisterName.setSelected(false);
							scenee3.name = false;
						}
						else
						{
							textRegisterName.typedOn(e);
						}

					}
					else if (scenee3.ID == true)
					{
						if (e.text.unicode == '\r')
						{
							textRegisterAge.setSelected(false);
							scenee3.ID = false;
						}
						else
						{
							textRegisterAge.typedOn(e);
						}

					}
					else if (scenee3.designation == true)
					{
						if (e.text.unicode == '\r')
						{
							textRegisterDepartment.setSelected(false);
							scenee3.designation = false;
						}
						else
						{
							textRegisterDepartment.typedOn(e);
						}

					}

				}
			}
		}

		/*----------------------------------------------------------------------Events Text Entered-----------------------------------------------------------------------------*/

		/*-----------------------------------------------------------------------------Events-----------------------------------------------------------------------------*/

	/*--------------------------------------------------------------------------Drawing The Sprites-----------------------------------------------------------------------------*/
		window.clear(Color(104, 167, 92));
		window.draw(backgroundImage);
		if (iscenee == 3)
		{
			Submit.setPosition(595, 670);
			window.draw(Submit);
			Back.setPosition(20, 20);
			Back.setScale(0.55, 0.55);
			window.draw(Back);
			Email.setPosition(220, 380);
			//window.draw(Email);
			ConfirmEmail.setPosition(220, 490);
			//window.draw(ConfirmEmail);
			Password.setPosition(220, 600);
			//window.draw(Password);
			ConfirmPassword.setPosition(740, 600);
			//window.draw(ConfirmPassword);
			Name.setPosition(220, 170);
			//window.draw(Name);
			ID.setPosition(740, 170);
			//window.draw(ID);
			Designation.setPosition(220, 270);
			//window.draw(Designation);
			textRegisterBatch.setPosition({ 240, 385 });
			textRegisterBatch.drawTo(window);
			textRegisterCourse.setPosition({ 240,495 });
			textRegisterCourse.drawTo(window);
			textRegisterSemester.setPosition({ 240,605 });
			textRegisterSemester.drawTo(window);
			textRegisterName.setPosition({ 240, 170 });
			textRegisterName.drawTo(window);
			textRegisterAge.setPosition({ 760, 175 });
			textRegisterAge.drawTo(window);
			textRegisterDepartment.setPosition({ 240, 280 });
			textRegisterDepartment.drawTo(window);
		}
		if (iscenee == 4)
		{
			LoginOK.setPosition(193, 219);
			window.draw(LoginOK);
		}
		window.display();
		/*--------------------------------------------------------------------------Drawing The Sprites-----------------------------------------------------------------------------*/
	}
	return 0;
}