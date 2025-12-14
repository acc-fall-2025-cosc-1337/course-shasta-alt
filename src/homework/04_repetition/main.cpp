#include <iostream>
#include "repetition.h"

int main()
{
    int choice = 0;

    do {
        std::cout << "\nHomework 4 Menu\n";
        std::cout << "1-Factorial\n";
        std::cout << "2-Sum odd numbers\n";
        std::cout << "3-Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        if (choice == 1) {
            int n = 0;
            do {
                std::cout << "Enter a number 1 to 9: ";
                std::cin >> n;
            } while (n <= 0 || n >= 10);

            int fact = get_factorial(n);
            std::cout << "Factorial of " << n << " is " << fact << "\n";
        }
        else if (choice == 2) {
            int n = 0;
            do {
                std::cout << "Enter a number 1 to 99: ";
                std::cin >> n;
            } while (n <= 0 || n >= 100);

            int sum = sum_odd_numbers(n);
            std::cout << "Sum of odd numbers up to " << n << " is " << sum << "\n";
        }
        else if (choice == 3) {
            std::cout << "Exiting.\n";
        }
        else {
            std::cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 3);

    return 0;
}
