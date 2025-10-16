#include <iostream>
#include "func.h"
using namespace std;

int main()
{
    int choice;
    string dna;

    do
    {
        cout << "\nDNA Analysis Menu\n";
        cout << "1 - Get GC Content\n";
        cout << "2 - Get DNA Complement\n";
        cout << "3 - Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter DNA string: ";
            cin >> dna;
            double gc = get_gc_content(dna);
            cout << "GC Content: " << gc << endl;
        }
        else if (choice == 2)
        {
            cout << "Enter DNA string: ";
            cin >> dna;
            string complement = get_dna_complement(dna);
            cout << "DNA Complement: " << complement << endl;
        }
        else if (choice == 3)
        {
            cout << "Exiting program...\n";
        }
        else
        {
            cout << "Invalid option. Try again.\n";
        }

    } while (choice != 3);

    return 0;
}

