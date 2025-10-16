// main.cpp
#include <iostream>
#include "decisions.h"
using namespace std;

int main()
{
    int option;
    int grade;

    cout << "MAIN MENU\n";
    cout << "1 - Letter grade using if\n";
    cout << "2 - Letter grade using switch\n";
    cout << "3 - Exit\n";
    cout << "Enter your choice: ";
    cin >> option;

    if (option == 1 || option == 2)
    {
        cout << "Enter a numerical grade (0 - 100): ";
        cin >> grade;

        if (grade >= 0 && grade <= 100)
        {
            if (option == 1)
                cout << "Letter grade: " << get_letter_grade_using_if(grade) << endl;
            else
                cout << "Letter grade: " << get_letter_grade_using_switch(grade) << endl;
        }
        else
        {
            cout << "Error: Grade is out of range!" << endl;
        }
    }
    else if (option == 3)
    {
        cout << "Goodbye!" << endl;
    }
    else
    {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
