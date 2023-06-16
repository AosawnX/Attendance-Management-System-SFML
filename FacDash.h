#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
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

int FacDash();
void FacSignup();

using namespace std;
using namespace sf;

/*-----------------------------------------------Classes------------------------------------------------*/
class Student {
public:
    string name;
    bool present;
    string age;
    string semester;
    string batch;
    string course;


    Texture presentRadioButtonTexture;
    Sprite presentRadioButtonImage;
    Texture absentRadioButtonTexture;
    Sprite absentRadioButtonImage;
    Texture detailsButtonTexture;
    Sprite detailsButtonImage;

    Student(const string& studentName, const string& studentAge, const string& studentSemester,
        const string& studentBatch, const string& studentCourse) {
        name = studentName;
        present = false;
        age = studentAge;
        semester = studentSemester;
        batch = studentBatch;
        course = studentCourse;
    }
};


class AttendanceSystem {
public:
    vector<Student> students;

    void addStudent(const string& name, const string& age, const string& semester,
        const string& batch, const string& course) {
        students.emplace_back(name, age, semester, batch, course); //creates a new object directly in vector, and calls it's constructor in same place too, no overhead
    }

    void markAttendance(int index, bool present) {
        students[index].present = present;
    }

    void saveAttendance() {
        ofstream file("attendance_records.txt", ios::app);
        if (file.is_open()) {

            time_t t = time(nullptr);
            tm now;
            localtime_s(&now, &t);
            char date[11];
            strftime(date, sizeof(date), "%m-%d-%Y", &now);


            file << date << endl;


            file << "Name\t\t\tAttendance" << endl;
            file << "---------------------------" << endl;
            for (const auto& student : students) {
                file << student.name << "\t\t\t\t" << (student.present ? "Present" : "Absent") << endl;
            }

            file << endl;
            file.close();
        }
    }

    void displayStudentDetails(int index)
    {
        cout << "Name: " << students[index].name << endl;
        cout << "Age: " << students[index].age << endl;
        cout << "Semester: " << students[index].semester << endl;
        cout << "Batch: " << students[index].batch << endl;
        cout << "Course: " << students[index].course << endl;
    }
};
/*-----------------------------------------------Events------------------------------------------------*/

int FacDash()
{
    /*-----------------------------------------------RenderWindow------------------------------------------------*/
    RenderWindow window(VideoMode(1340, 760), "Faculty Dashboard", Style::Close | Style::Titlebar);
    window.setFramerateLimit(60);
    /*-----------------------------------------------RenderWindow------------------------------------------------*/

     /*-----------------------------------------------Textures and Sprites------------------------------------------------*/
    Texture background;
    Sprite backgroundImage;

    if (!background.loadFromFile("FacDash.png"))
        cout << "Error: Could not display image" << endl;

    backgroundImage.setTexture(background);

    Texture back;
    back.loadFromFile("Back.png");
    Sprite Back(back);
    Back.setPosition(20, 20);
    Back.setScale(0.55, 0.55);

    Font font;
    font.loadFromFile("OsMed.ttf");

    const int windowWidth = 400;
    const int windowHeight = 600;
    const int buttonWidth = 100;
    const int buttonHeight = 30;
    const int buttonSpacing = 50;

    AttendanceSystem attendanceSystem;
    attendanceSystem.addStudent("Saad", "20", "Spring 2023", "Batch 1", "Computer Science");
    attendanceSystem.addStudent("Sohaib", "19", "Fall 2022", "Batch 2", "Physics");
    attendanceSystem.addStudent("Abdullah", "20", "Summer 2023", "Batch 1", "Mathematics");
    attendanceSystem.addStudent("Ada", "1", "Summer 2023", "Batch 1", "Mathematics");
    attendanceSystem.addStudent("Rabiyah", "25", "Summer 2023", "Batch 1", "Mathematics");

    /*-----------------------------------------------Textures and Sprites------------------------------------------------*/

     /*-----------------------------------------------Events------------------------------------------------*/
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            /*-----------------------------------------------Events to read attendance buttons------------------------------------------------*/
            for (int i = 0; i < attendanceSystem.students.size(); ++i)
            {
                attendanceSystem.students[i].presentRadioButtonTexture.loadFromFile("present.png");
                attendanceSystem.students[i].presentRadioButtonImage.setTexture(attendanceSystem.students[i].presentRadioButtonTexture);
                attendanceSystem.students[i].presentRadioButtonImage.setScale(0.5, 0.5);
                attendanceSystem.students[i].absentRadioButtonTexture.loadFromFile("absent.png");
                attendanceSystem.students[i].absentRadioButtonImage.setTexture(attendanceSystem.students[i].absentRadioButtonTexture);
                attendanceSystem.students[i].absentRadioButtonImage.setScale(0.5, 0.5);
                attendanceSystem.students[i].detailsButtonTexture.loadFromFile("details(fill).png");
                attendanceSystem.students[i].detailsButtonImage.setTexture(attendanceSystem.students[i].detailsButtonTexture);
                attendanceSystem.students[i].detailsButtonImage.setScale(0.51, 0.51);
                attendanceSystem.students[i].presentRadioButtonImage.setPosition(750, 80 + buttonHeight + buttonSpacing + i * (buttonHeight + buttonSpacing));
                attendanceSystem.students[i].absentRadioButtonImage.setPosition(950, 80 + buttonHeight + buttonSpacing + i * (buttonHeight + buttonSpacing));
                attendanceSystem.students[i].detailsButtonImage.setPosition(1150, 80 + buttonHeight + buttonSpacing + i * (buttonHeight + buttonSpacing));
            }
            /*-----------------------------------------------Events to read attendance buttons------------------------------------------------*/
            if (event.type == Event::Closed)
                window.close();
            /*-----------------------------------------------Events Mouse button Pressed------------------------------------------------*/
            if (event.type == Event::MouseButtonPressed) {
                if (event.mouseButton.button == Mouse::Left) {

                    for (int i = 0; i < attendanceSystem.students.size(); ++i)
                    {
                        Vector2i mousePos = Mouse::getPosition(window);
                        Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                        if (attendanceSystem.students[i].presentRadioButtonImage.getGlobalBounds().contains(mousePosF)) {
                            attendanceSystem.markAttendance(i, true);
                            cout << "present " << endl;
                            break;
                        }
                        else if (attendanceSystem.students[i].absentRadioButtonImage.getGlobalBounds().contains(mousePosF)) {
                            attendanceSystem.markAttendance(i, false);
                            cout << "absent " << endl;
                            break;
                        }
                        else if (attendanceSystem.students[i].detailsButtonImage.getGlobalBounds().contains(mousePosF)) {
                            attendanceSystem.displayStudentDetails(i);
                            cout << "details " << endl;
                            break;
                        }
                        else if (Back.getGlobalBounds().contains(mousePosF))
                        {
                            window.close();
                            FacSignup();
                        }
                    }
                }
            }
            /*-----------------------------------------------Events Mouse button Pressed------------------------------------------------*/

            /*-----------------------------------------------Events Key presses------------------------------------------------*/
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::S && Keyboard::LControl) {
                    attendanceSystem.saveAttendance();
                }
            }
            /*-----------------------------------------------Events Key presses------------------------------------------------*/
        }
        /*-----------------------------------------------Events------------------------------------------------*/

        /*-----------------------------------------------Drawing Sprites------------------------------------------------*/
        window.clear(Color::White);
        window.draw(backgroundImage);
        window.draw(Back);


        for (int i = 0; i < attendanceSystem.students.size(); ++i) {
            Text studentNameText;
            studentNameText.setFont(font);
            studentNameText.setString(attendanceSystem.students[i].name);
            studentNameText.setCharacterSize(28);
            studentNameText.setFillColor(Color::Black);
            studentNameText.setPosition(150, 90 + buttonHeight + buttonSpacing + i * (buttonHeight + buttonSpacing));

            window.draw(studentNameText);

            window.draw(attendanceSystem.students[i].presentRadioButtonImage);
            window.draw(attendanceSystem.students[i].absentRadioButtonImage);
            window.draw(attendanceSystem.students[i].detailsButtonImage);
        }

        window.display();
        /*-----------------------------------------------Drawing Sprites------------------------------------------------*/
    }

    return 0;
}