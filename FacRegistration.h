#pragma once
#pragma warning(disable: 4305)
#pragma warning(disable: 4244)


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

/*-----------------------------------------------Prototype------------------------------------------------*/
void AdmDash();
int Faclogin();
void FacSignup();
/*-----------------------------------------------Prototype------------------------------------------------*/

/*----------------------------------------------Classes-----------------------------------------------*/
class scnn2
{
public:
	bool email = false;
	bool password = false;
};

class scnn3
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

class aaccount
{
public:
	string email;
	string password;
};

int scenee = 1, q = 1;
scnn2 scenee2;
scnn3 scenee3;
aaccount facacc[100]; //amount of accounts you can make
bool ffirst = true;
/*----------------------------------------------Classes-----------------------------------------------*/

void inputfacc() //whatever is the input stored in file, it will read
{
	/*----------------------------------------------Read From file-----------------------------------------------*/

	ifstream fin("FacLogin.txt", ios::in | ios::app);
	while (fin >> facacc[q].email)
	{
		fin >> facacc[q].password; //stores details in aaccount array declared on Ln55
		q++;
	}
	fin.close();
	/*----------------------------------------------Read From file-----------------------------------------------*/
}

//Register new faculty members
int FacReg()
{
	/*----------------------------------------------Render Window-----------------------------------------------*/
	RenderWindow window(VideoMode(1340, 760), "Faculty Registration", Style::Close | Style::Titlebar);
	window.setFramerateLimit(60);
	/*----------------------------------------------Render Window-----------------------------------------------*/

	/*----------------------------------------------Textures and Sprites----------------------------------------------*/
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

	if (!background.loadFromFile("FacRegPg.png"))
		cout << "Error: Could not display image" << endl;

	backgroundImage.setTexture(background);

	Font arial;
	arial.loadFromFile("Arial.ttf");
	/*----------------------------------------------Textures and Sprites----------------------------------------------*/


	/*----------------------------------------------TextBoxes----------------------------------------------*/

	Textbox textLoginEmail(30, Color::Black, false);
	textLoginEmail.setFont(arial);
	Textbox textLoginPassword(30, Color::Black, false);
	textLoginPassword.setFont(arial);
	Textbox textRegisterEmail(30, Color::Black, false);
	textRegisterEmail.setFont(arial);
	Textbox textRegisterConfirmEmail(30, Color::Black, false);
	textRegisterConfirmEmail.setFont(arial);
	Textbox textRegisterPassword(30, Color::Black, false);
	textRegisterPassword.setFont(arial);
	Textbox textRegisterConfirmPassword(30, Color::Black, false);
	textRegisterConfirmPassword.setFont(arial);
	Textbox textRegisterName(30, Color::Black, false);
	textRegisterName.setFont(arial);
	Textbox textRegisterID(30, Color::Black, false);
	textRegisterID.setFont(arial);
	Textbox textRegisterDesignation(30, Color::Black, false);
	textRegisterDesignation.setFont(arial);

	/*----------------------------------------------TextBoxes----------------------------------------------*/

	inputfacc();

	ofstream fout("FacLogin.txt", ios::app);
	ofstream foutDetails("FacDets.txt", ios::app);

	/*----------------------------------------------Events----------------------------------------------*/
	while (window.isOpen())
	{
		if (ffirst == true)
		{
			for (int j = 1; j < q; j++)
			{
				fout << facacc[j].email << "\n";
				fout << facacc[j].password << "\n";
			}
			ffirst = false;
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
				/*----------------------------------------------Events MouseButton Pressed----------------------------------------------*/
				if (e.mouseButton.button == Mouse::Left)
				{
					int x = e.mouseButton.x;
					int y = e.mouseButton.y;
					if (scenee == 1)
					{
						scenee = 3;
					}
					if (scenee == 3)
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
							textRegisterEmail.setSelected(true);
						}
						// confirm email
						if (ConfirmEmail.getGlobalBounds().contains(mousePosF))
						{
							scenee3.confirmEmail = true;
							textRegisterConfirmEmail.setSelected(true);
						}
						// password
						if (Password.getGlobalBounds().contains(mousePosF))
						{
							scenee3.password = true;
							textRegisterPassword.setSelected(true);
						}
						// confirm password
						if (ConfirmPassword.getGlobalBounds().contains(mousePosF))
						{
							scenee3.confirmPassword = true;
							textRegisterConfirmPassword.setSelected(true);

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
							textRegisterID.setSelected(true);
						}
						// designation
						if (Designation.getGlobalBounds().contains(mousePosF))
						{
							scenee3.designation = true;
							textRegisterDesignation.setSelected(true);
						}


						// submit
						if (Submit.getGlobalBounds().contains(mousePosF))
						{
							cout << "1 button pressed";
							string e, ce, p, cp;
							e = textRegisterEmail.getText();
							ce = textRegisterConfirmEmail.getText();
							p = textRegisterPassword.getText();
							cp = textRegisterConfirmPassword.getText();
							if (!e.empty() && !ce.empty() && !p.empty() && !cp.empty())
							{
								cout << "2 button pressed";
								fout << e << "\n";
								if (e == ce && p == cp)
								{
									fout << p << "\n";
								}


								string name = textRegisterName.getText();
								string ID = textRegisterID.getText();
								string designation = textRegisterDesignation.getText();

								ofstream namefile("Name.txt", ios::app);
								namefile << name << endl;

								foutDetails << "Name: " << name << "\n";
								foutDetails << "ID: " << ID << "\n";
								foutDetails << "Designation: " << designation << "\n";
								attendanceSystem.addFaculty(name, ID, designation);
								fout.close();
								foutDetails.close();
							}
							window.close();
							AdmDash();
						}
					}
				}
			}
			/*----------------------------------------------Events MouseButton Pressed----------------------------------------------*/

			/*----------------------------------------------Events Text Entered----------------------------------------------*/
			if (e.type == Event::TextEntered)
			{
				if (scenee == 3)
				{
					if (scenee3.email == true)
					{
						if (e.text.unicode == '\r')
						{
							textRegisterEmail.setSelected(false);
							scenee3.email = false;
						}
						else
						{
							textRegisterEmail.typedOn(e);
						}
					}
					else if (scenee3.confirmEmail == true)
					{
						if (e.text.unicode == '\r')
						{
							textRegisterConfirmEmail.setSelected(false);
							scenee3.confirmEmail = false;
						}
						else
						{
							textRegisterConfirmEmail.typedOn(e);
						}
					}
					else if (scenee3.password == true)
					{
						if (e.text.unicode == '\r')
						{
							textRegisterPassword.setSelected(false);
							scenee3.password = false;
						}
						else
						{
							textRegisterPassword.typedOn(e);
						}
					}
					else if (scenee3.confirmPassword == true)
					{
						if (e.text.unicode == '\r')
						{
							textRegisterConfirmPassword.setSelected(false);
							scenee3.confirmPassword = false;
						}
						else
						{
							textRegisterConfirmPassword.typedOn(e);
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
							textRegisterID.setSelected(false);
							scenee3.ID = false;
						}
						else
						{
							textRegisterID.typedOn(e);
						}

					}
					else if (scenee3.designation == true)
					{
						if (e.text.unicode == '\r')
						{
							textRegisterDesignation.setSelected(false);
							scenee3.designation = false;
						}
						else
						{
							textRegisterDesignation.typedOn(e);
						}

					}

				}
			}
		}
		/*----------------------------------------------Events Text Entered----------------------------------------------*/

		/*----------------------------------------------Events----------------------------------------------*/

		/*----------------------------------------------Drawing Sprites----------------------------------------------*/
		window.clear(Color(104, 167, 92));
		window.draw(backgroundImage);
		if (scenee == 3)
		{
			Submit.setPosition(595, 670);
			window.draw(Submit);
			Back.setPosition(20, 20);
			Back.setScale(0.55, 0.55);
			window.draw(Back);
			Email.setPosition(220, 380);
			ConfirmEmail.setPosition(220, 490);
			Password.setPosition(220, 600);
			ConfirmPassword.setPosition(740, 600);
			Name.setPosition(220, 170);
			ID.setPosition(740, 170);
			Designation.setPosition(220, 270);
			textRegisterEmail.setPosition({ 240, 385 });
			textRegisterEmail.drawTo(window);
			textRegisterConfirmEmail.setPosition({ 240,495 });
			textRegisterConfirmEmail.drawTo(window);
			textRegisterPassword.setPosition({ 240,605 });
			textRegisterPassword.drawTo(window);
			textRegisterConfirmPassword.setPosition({ 760,605 });
			textRegisterConfirmPassword.drawTo(window);
			textRegisterName.setPosition({ 240, 170 });
			textRegisterName.drawTo(window);
			textRegisterID.setPosition({ 760, 175 });
			textRegisterID.drawTo(window);
			textRegisterDesignation.setPosition({ 240, 280 });
			textRegisterDesignation.drawTo(window);
		}
		if (scenee == 4)
		{
			LoginOK.setPosition(193, 219);
			window.draw(LoginOK);
		}
		window.display();
		/*----------------------------------------------Drawing Sprites----------------------------------------------*/
	}
	return 0;
}