// main.cpp
#include <iostream>
#include "data_types.h"

using namespace std;

int main()
{
    int result;

    result = multiply_numbers(7, 7);
    cout << "7 x 7 = " << result << endl;

    result = multiply_numbers(5, 5);
    cout << "5 x 5 = " << result << endl;

    return 0;
}

