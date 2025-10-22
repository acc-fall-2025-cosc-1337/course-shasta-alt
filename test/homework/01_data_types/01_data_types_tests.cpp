// 01_data_types_tests.cpp
#include "data_types.h"
#include <cassert>
#include <iostream>

using namespace std;

int main()
{
    assert(multiply_numbers(7, 7) == 49);
    assert(multiply_numbers(5, 5) == 25);
    cout << "✅ All tests passed successfully!" << endl;
    return 0;
}



