#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include"AdminDash.h"
using namespace std;
using namespace sf;

void AdmDash();

/*------------------------------------------------Classes------------------------------------------------*/
class Faculty {
public:
	string name;
	bool present;
	string FacultyID;
	string Designation;
	string batch;
	string course;
	Texture presentRadioButtonTexture;
	Sprite presentRadioButtonImage;
	Texture absentRadioButtonTexture;
	Sprite absentRadioButtonImage;
	Texture detailsButtonTexture;
	Sprite detailsButtonImage;

	Faculty(const string& FacName, const string& ID, const string& Desig) {
		name = FacName;
		present = false;
		FacultyID = ID;
		Designation = Desig;
	}
};

class AAttendanceSystem {
public:
	vector<Faculty> faculties;

	void addFaculty(const string& name, const string& ID, const string& Designation) {
		faculties.emplace_back(name, ID, Designation);
	}

	void markAttendance(int index, bool present) {
		faculties[index].present = present;
	}
	void SaveDetails() {
		ofstream file("FacDets.txt", ios::app);
		if (file.is_open()) {
			file << "Faculty Details\n";
			file << "----------------\n";

			for (const auto& faculty : faculties) {
				file << "Name: " << faculty.name << "\n";
				file << "Faculty ID " << faculty.FacultyID << "\n";
				file << "Designation " << faculty.Designation << "\n";
				file << "----------------\n";
			}

			file.close();
		}
	}
	void saveAttendance() {
		ofstream file("attendance_records_faculty.txt", ios::app);
		if (file.is_open()) {
			// Get the current date
			time_t t = time(nullptr);
			tm now;
			localtime_s(&now, &t);
			char date[11];
			strftime(date, sizeof(date), "%m-%d-%Y", &now);

			// Write the date as a header
			file << date << endl;

			// Write the attendance records in a table format
			file << "Name\t\t\tAttendance" << endl;
			file << "---------------------------" << endl;
			for (const auto& faculty : faculties) {
				file << faculty.name << "\t\t\t\t" << (faculty.present ? "Present" : "Absent") << endl;
			}

			file << endl;
			file.close();
		}
	}

	void displayFacultyDetails(int index) {
		cout << "Name: " << faculties[index].name << endl;
		cout << "ID: " << faculties[index].FacultyID << endl;
		cout << "Designation: " << faculties[index].Designation << endl;
	}
};
/*------------------------------------------------DRAWING SPRITES ON THE SCREEN------------------------------------------------*/
AAttendanceSystem attendanceSystem;//Global Object

int FacultyAttendance()
{
	/*------------------------------------------------Sprites and Textures------------------------------------------------*/
	Texture background;
	Sprite backgroundImage;

	if (!background.loadFromFile("FacAttendancePage.png"))
		cout << "Error: Could not display image" << endl;

	backgroundImage.setTexture(background);

	Font font;
	if (!font.loadFromFile("OsMed.ttf"))
		cout << "Error: Could not load font" << endl;

	Texture BackButton;
	Sprite BackButtonImage;
	if (!BackButton.loadFromFile("back.png"))
		cout << "Can't find the image" << endl;
	BackButtonImage.setPosition(20.0f, 20.0f);

	float BackButtonWidth = BackButtonImage.getLocalBounds().width;
	float BackButtonHeight = BackButtonImage.getLocalBounds().height;

	BackButtonImage.setTexture(BackButton);
	BackButtonImage.setScale(0.55, 0.55);

	/*--------------ADD FAC---------------*/

	Texture AddFaculty;
	Sprite AddFacImg;
	if (!AddFaculty.loadFromFile("facreg.png"))
		cout << "Can't find the image" << endl;
	AddFacImg.setPosition(35.0f, 155.0f);

	float AddFacultyWidth = AddFacImg.getLocalBounds().width;
	float AddFacultyHeight = AddFacImg.getLocalBounds().height;

	AddFacImg.setScale(0.07, 0.07);
	AddFacImg.setTexture(AddFaculty);



	/*----------------ADD NEW STUDENT BUTTON-------------*/

	Texture AddStudent;
	Sprite AddStudImg;
	if (!AddStudent.loadFromFile("studreg.png"))
		cout << "Can't find the image" << endl;
	AddStudImg.setPosition(40.0f, 240.0f);

	float AddStudentWidth = AddStudImg.getLocalBounds().width;
	float AddStudentHeight = AddStudImg.getLocalBounds().height;

	AddStudImg.setScale(0.07, 0.07);
	AddStudImg.setTexture(AddStudent);

	/*----------------------Mark Faculty attendance button---------------------*/
	Texture FacAtt;
	Sprite FacAttImg;
	if (!FacAtt.loadFromFile("atten-L.png"))
		cout << "Can't find the image" << endl;
	FacAttImg.setPosition(22.0f, 300.0f);

	float FacAttWidth = FacAttImg.getLocalBounds().width;
	float FacAttHeight = FacAttImg.getLocalBounds().height;

	FacAttImg.setScale(0.18, 0.18);
	FacAttImg.setTexture(FacAtt);

	/*-----------------------Check notification button----------------------*/
	Texture Notif;
	Sprite NotifImg;
	if (!Notif.loadFromFile("notification.png"))
		cout << "Can't find the image" << endl;
	NotifImg.setPosition(22.0f, 400.0f);

	float NotifWidth = NotifImg.getLocalBounds().width;
	float NotifHeight = NotifImg.getLocalBounds().height;

	NotifImg.setScale(1, 1);
	NotifImg.setTexture(Notif);


	/*--------------Available Faculty---------------------*/
	Texture AvFac;
	Sprite AvFacImg;
	if (!AvFac.loadFromFile("Book.png"))
		cout << "Can't find the image" << endl;
	AvFacImg.setPosition(22.0f, 500.0f);

	float AvFacWidth = AvFacImg.getLocalBounds().width;
	float AvFacHeight = AvFacImg.getLocalBounds().height;

	AvFacImg.setScale(1, 1);
	AvFacImg.setTexture(AvFac);

	const int windowWidth = 400;
	const int windowHeight = 600;
	const int buttonWidth = 100;
	const int buttonHeight = 30;
	const int buttonSpacing = 50;


	attendanceSystem.addFaculty("Burhan Abbasi", "001", "Prof.");
	attendanceSystem.addFaculty("Tahira Anwar", "002", "Prof.");
	attendanceSystem.addFaculty("Haroon Kiani", "007", "Lecturer");
	attendanceSystem.addFaculty("Sheraz Khan", "017", "Lecturer");
	attendanceSystem.addFaculty("Shahmeer Khan", "041", "Asst. Prof.");
	attendanceSystem.addFaculty("Ali Bokhari", "074", "Asst. Prof.");
	attendanceSystem.addFaculty("Raheel Ahmad", "082", "Prof.");
	/*------------------------------------------------Sprites and Textures------------------------------------------------*/

	/*-----------------------------------------------Render Window------------------------------------------------*/

	RenderWindow window(VideoMode(1340, 760), "Faculty Attendance", Style::Close | Style::Titlebar);

	/*-----------------------------------------------Render Window------------------------------------------------*/

	/*-----------------------------------------------Events------------------------------------------------*/
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();

			if (event.type == Event::MouseButtonPressed) {
				/*----------------------------------------------MouseButton pressed-----------------------------------------------*/
				if (event.mouseButton.button == Mouse::Left) {
					for (int i = 0; i < attendanceSystem.faculties.size(); ++i)
					{
						attendanceSystem.faculties[i].presentRadioButtonTexture.loadFromFile("present.png");
						attendanceSystem.faculties[i].presentRadioButtonImage.setTexture(attendanceSystem.faculties[i].presentRadioButtonTexture);
						attendanceSystem.faculties[i].presentRadioButtonImage.setScale(0.5, 0.5);
						attendanceSystem.faculties[i].absentRadioButtonTexture.loadFromFile("absent.png");
						attendanceSystem.faculties[i].absentRadioButtonImage.setTexture(attendanceSystem.faculties[i].absentRadioButtonTexture);
						attendanceSystem.faculties[i].absentRadioButtonImage.setScale(0.5, 0.5);
						attendanceSystem.faculties[i].detailsButtonTexture.loadFromFile("details(fill).png");
						attendanceSystem.faculties[i].detailsButtonImage.setTexture(attendanceSystem.faculties[i].detailsButtonTexture);
						attendanceSystem.faculties[i].detailsButtonImage.setScale(0.51, 0.51);
						attendanceSystem.faculties[i].presentRadioButtonImage.setPosition(750, 80 + buttonHeight + buttonSpacing + i * (buttonHeight + buttonSpacing));
						attendanceSystem.faculties[i].absentRadioButtonImage.setPosition(950, 80 + buttonHeight + buttonSpacing + i * (buttonHeight + buttonSpacing));
						attendanceSystem.faculties[i].detailsButtonImage.setPosition(1150, 80 + buttonHeight + buttonSpacing + i * (buttonHeight + buttonSpacing));

						Vector2i mousePos = Mouse::getPosition(window);
						Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
						if (attendanceSystem.faculties[i].presentRadioButtonImage.getGlobalBounds().contains(mousePosF)) {
							attendanceSystem.markAttendance(i, true);
							cout << "present ";
							break;
						}
						else if (attendanceSystem.faculties[i].absentRadioButtonImage.getGlobalBounds().contains(mousePosF)) {
							attendanceSystem.markAttendance(i, false);
							cout << "absent ";
							break;
						}
						else if (attendanceSystem.faculties[i].detailsButtonImage.getGlobalBounds().contains(mousePosF)) {
							attendanceSystem.displayFacultyDetails(i);
							cout << "details ";
							break;
						}
					}
					Vector2i mousePos = Mouse::getPosition(window);
					Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
					if (BackButtonImage.getGlobalBounds().contains(mousePosF))
					{
						window.close();
						AdmDash();

					}
					if (AddFacImg.getGlobalBounds().contains(mousePosF))
					{
						cout << "addfac button pressed";
					}
					if (AddStudImg.getGlobalBounds().contains(mousePosF))
					{
						cout << "addstud button pressed";
					}
					if (FacAttImg.getGlobalBounds().contains(mousePosF))
					{
						cout << "Already here" << endl;
					}
					if (AvFacImg.getGlobalBounds().contains(mousePosF))
					{
						cout << "AvFac button pressed";
					}
					if (NotifImg.getGlobalBounds().contains(mousePosF))
					{
						if (!background.loadFromFile("NOTIFPG.png"))
							cout << "Error: Could not display image" << endl;

						backgroundImage.setTexture(background);
						cout << "Notif button pressed";
					}

				}
			}
			/*----------------------------------------------MouseButton pressed-----------------------------------------------*/

			/*---------------------------------------------KeyPRessed pressed-----------------------------------------------*/
			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::S) {
					attendanceSystem.saveAttendance();
					attendanceSystem.SaveDetails();
				}
			}
			/*---------------------------------------------KeyPRessed pressed-----------------------------------------------*/
		}
		/*-----------------------------------------------Events------------------------------------------------*/

		/*---------------------------------------------Drawing Sprites-----------------------------------------------*/

		window.clear(Color::White);
		window.draw(backgroundImage);


		for (int i = 0; i < attendanceSystem.faculties.size(); ++i) {
			Text facultyNameText;
			facultyNameText.setFont(font);
			facultyNameText.setString(attendanceSystem.faculties[i].name);
			facultyNameText.setCharacterSize(28);
			facultyNameText.setFillColor(Color::Black);
			facultyNameText.setPosition(150, 90 + buttonHeight + buttonSpacing + i * (buttonHeight + buttonSpacing));

			window.draw(facultyNameText);

			window.draw(BackButtonImage);
			window.draw(attendanceSystem.faculties[i].presentRadioButtonImage);
			window.draw(attendanceSystem.faculties[i].absentRadioButtonImage);
			window.draw(attendanceSystem.faculties[i].detailsButtonImage);
		}

		window.display();
		/*---------------------------------------------Drawing Sprites-----------------------------------------------*/
	}

	return 0;
}