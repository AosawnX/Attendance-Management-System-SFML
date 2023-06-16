#pragma warning(disable:4244)
#pragma warning(disable:4305)
#include <iostream>
#include <string>
#include"HomePage.h"

using namespace std;
//This Project is developed by Biyah, Ark & Shah of BSCS-2A, we hope you like it

class FrontPage {
private:
    int width;
    int height;

    void printLine(char symbol) {
        for (int i = 0; i < width; i++) {
            cout << symbol;
        }
        cout << endl;
    }

    void printBox() {
        printLine('*');
        for (int i = 0; i < height; i++) {
            cout << '*';
            for (int j = 0; j < width - 2; j++) {
                cout << ' ';
            }
            cout << '*' << endl;
        }
        printLine('*');
    }

public:
    FrontPage(int w, int h) : width(w), height(h) {}

    void display() {
        printLine('*');
        printBox();
        cout << "*   Welcome to the Student Attendance   *" << endl;
        cout << "*              System!                 *" << endl;
        printBox();
        printLine('*');
    }
};

class Home {
public:
    void showAll() {
        FrontPage frontPage(40, 7); //Composed object in a member function of another class
        frontPage.display();
    }
    void display()
    {
        HomePage();
    }
};

int main() {

    Home home;
    home.showAll();

    cout << "Press 1 to continue: ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        
        cout << "Continuing to the next page..." << endl;
        system("CLS");
        
        home.display();
    }
    else {
        cout << "Invalid choice. Exiting the program..." << endl;
    }

    return 0;
}