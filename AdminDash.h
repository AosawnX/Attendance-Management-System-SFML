#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include <string>
#include <iostream> 
#include <random>
#include"FacAtt.h"
#include"FacRegistration.h"
#include"AdminLogin.h"
#include"FacLogin.h"
#include"AddStud.h"
#include"LoginAs.h"
#include"AvFac.h"

/*--------------------------------------------------------------------------Function Prototype-----------------------------------------------------------------------------*/
int FacReg();
void loginAs();
void AvFaculty();

/*--------------------------------------------------------------------------Drawing The Sprites-----------------------------------------------------------------------------*/

using namespace sf;
using namespace std;
void AdmDash()
{
	int noti = 0;

	/*--------------------------------------------------------------------------Render Window-----------------------------------------------------------------------------*/

	RenderWindow window(VideoMode(1340, 760), "Admin Dashboard", Style::Close | Style::Titlebar);
	window.setFramerateLimit(60);

	/*--------------------------------------------------------------------------Drawing The Sprites-----------------------------------------------------------------------------*/

	/*--------------------------------------------------------------------------Textures and Sprites-----------------------------------------------------------------------------*/
	Texture background;
	Sprite backgroundImage;

	if (!background.loadFromFile("AdmDash.png"))
		cout << "Error: Could not display image" << endl;

	backgroundImage.setTexture(background);

	Font font;
	if (!font.loadFromFile("Blanka-Regular.otf"))
		cout << "Can't find the font file" << endl;

	Texture BackButton;
	Sprite BackButtonImage;
	if (!BackButton.loadFromFile("back.png"))
		cout << "Can't find the image" << endl;
	BackButtonImage.setPosition(40.0f, 30.0f);

	float BackButtonWidth = BackButtonImage.getLocalBounds().width;
	float BackButtonHeight = BackButtonImage.getLocalBounds().height;

	BackButtonImage.setTexture(BackButton);
	BackButtonImage.setScale(0.55, 0.55);

	/*--------------------------------------------------------------------------Textures and Sprites-----------------------------------------------------------------------------*/

	/*--------------------------------------------------------------------------Add Faculty-----------------------------------------------------------------------------*/

	Texture AddFaculty;
	Sprite AddFacImg;
	if (!AddFaculty.loadFromFile("facreg.png"))
		cout << "Can't find the image" << endl;
	AddFacImg.setPosition(35.0f, 155.0f);

	float AddFacultyWidth = AddFacImg.getLocalBounds().width;
	float AddFacultyHeight = AddFacImg.getLocalBounds().height;

	AddFacImg.setScale(0.07, 0.07);
	AddFacImg.setTexture(AddFaculty);
	/*--------------------------------------------------------------------------Textures and Sprites-----------------------------------------------------------------------------*/


	/*--------------------------------------------------------------------------Add New Student-----------------------------------------------------------------------------*/

	Texture AddStudent;
	Sprite AddStudImg;
	if (!AddStudent.loadFromFile("studreg.png"))
		cout << "Can't find the image" << endl;
	AddStudImg.setPosition(40.0f, 240.0f);

	float AddStudentWidth = AddStudImg.getLocalBounds().width;
	float AddStudentHeight = AddStudImg.getLocalBounds().height;

	AddStudImg.setScale(0.07, 0.07);
	AddStudImg.setTexture(AddStudent);
	/*--------------------------------------------------------------------------Add New Student-----------------------------------------------------------------------------*/

	/*-------------------------------------------------------------------------Mark Faculty Attendance-----------------------------------------------------------------------------*/
	Texture FacAtt;
	Sprite FacAttImg;
	if (!FacAtt.loadFromFile("atten-L.png"))
		cout << "Can't find the image" << endl;
	FacAttImg.setPosition(22.0f, 300.0f);

	float FacAttWidth = FacAttImg.getLocalBounds().width;
	float FacAttHeight = FacAttImg.getLocalBounds().height;

	FacAttImg.setScale(0.18, 0.18);
	FacAttImg.setTexture(FacAtt);
	/*-------------------------------------------------------------------------Mark Faculty Attendance-----------------------------------------------------------------------------*/

	/*-------------------------------------------------------------------------Check Notification-----------------------------------------------------------------------------*/
	Texture Notif;
	Sprite NotifImg;
	if (!Notif.loadFromFile("notification.png"))
		cout << "Can't find the image" << endl;
	NotifImg.setPosition(22.0f, 400.0f);

	float NotifWidth = NotifImg.getLocalBounds().width;
	float NotifHeight = NotifImg.getLocalBounds().height;

	NotifImg.setScale(1, 1);
	NotifImg.setTexture(Notif);
	/*-------------------------------------------------------------------------Check Notification-----------------------------------------------------------------------------*/

	/*-------------------------------------------------------------------------Available faculty-----------------------------------------------------------------------------*/
	Texture AvFac;
	Sprite AvFacImg;
	if (!AvFac.loadFromFile("Book.png"))
		cout << "Can't find the image" << endl;
	AvFacImg.setPosition(22.0f, 500.0f);

	float AvFacWidth = AvFacImg.getLocalBounds().width;
	float AvFacHeight = AvFacImg.getLocalBounds().height;

	AvFacImg.setScale(1, 1);
	AvFacImg.setTexture(AvFac);
	/*-------------------------------------------------------------------------Available faculty-----------------------------------------------------------------------------*/


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
				if (AddFacImg.getGlobalBounds().contains(mousePosF))
				{
					AddFacImg.setColor(Color(255, 229, 204));
				}
				else
				{
					AddFacImg.setColor(Color(255, 255, 255));
				}
				if (AddStudImg.getGlobalBounds().contains(mousePosF))
				{
					AddStudImg.setColor(Color(255, 229, 204));
				}
				else
				{
					AddStudImg.setColor(Color(255, 255, 255));
				}
				if (FacAttImg.getGlobalBounds().contains(mousePosF))
				{
					FacAttImg.setColor(Color(255, 229, 204));
				}
				else
				{
					FacAttImg.setColor(Color(255, 255, 255));
				}
				if (AvFacImg.getGlobalBounds().contains(mousePosF))
				{
					AvFacImg.setColor(Color(255, 229, 204));
				}
				else
				{
					AvFacImg.setColor(Color(255, 255, 255));
				}
				if (NotifImg.getGlobalBounds().contains(mousePosF))
				{
					NotifImg.setColor(Color(255, 229, 204));
				}
				else
				{
					NotifImg.setColor(Color(255, 255, 255));
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
					if (BackButtonImage.getGlobalBounds().contains(mousePosF) && noti == 1)
					{
						noti = 0;
						if (!background.loadFromFile("AdmDash.png"))
							cout << "Error: Could not display image" << endl;

						backgroundImage.setTexture(background);
					}
					else if (BackButtonImage.getGlobalBounds().contains(mousePosF) && noti == 0)
					{
						window.close();
						loginAs();
					}
					if (AddFacImg.getGlobalBounds().contains(mousePosF))
					{
						window.close();
						FacReg();
					}
					if (AddStudImg.getGlobalBounds().contains(mousePosF))
					{
						window.close();
						StudReg();
					}
					if (FacAttImg.getGlobalBounds().contains(mousePosF))
					{
						window.close();
						FacultyAttendance();
					}
					if (AvFacImg.getGlobalBounds().contains(mousePosF))
					{
						window.close();
						AvFaculty();
					}
					if (NotifImg.getGlobalBounds().contains(mousePosF))
					{
						if (!background.loadFromFile("NOTIFPG.png"))
							cout << "Error: Could not display image" << endl;

						backgroundImage.setTexture(background);
						cout << "Notif button pressed";
						int noti = 1;
					}

				}
			} /*------------------------------------------------END OF EVENT FOR MOUSE BUTTON PRESS ON BUTTONS------------------------------------------------*/
			}
			/*------------------------------------------------DRAWING SPRITES ON THE SCREEN------------------------------------------------*/
			window.clear();
			window.draw(backgroundImage);
			window.draw(BackButtonImage);
			window.draw(AddFacImg);
			window.draw(AddStudImg);
			window.draw(FacAttImg);
			window.draw(AvFacImg);
			window.draw(NotifImg);
			window.display();
			/*------------------------------------------------END OF DRAWING SPRITES ON THE SCREEN------------------------------------------------*/

		}
	}

	return;
}