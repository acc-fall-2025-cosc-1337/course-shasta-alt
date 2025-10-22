// main.cpp
#include <iostream>
#include "data_types.h"

using namespace std;

int main()
{
    double num1 = 7;
    double num2 = 7;
    double result = multiply_numbers(num1, num2);
    cout << num1 << " x " << num2 << " = " << result << endl;

    num1 = 5;
    num2 = 5;
    result = multiply_numbers(num1, num2);
    cout << num1 << " x " << num2 << " = " << result << endl;

    return 0;
}


