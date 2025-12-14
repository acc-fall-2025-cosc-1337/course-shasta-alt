#include <iostream>
using namespace std;

int multiply_numbers(int num1, int num2)
{
    return num1 * num2;
}

int main()
{
    int a, b;
    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;

    int result = multiply_numbers(a, b);
    cout << a << " x " << b << " = " << result << endl;

    return 0;
}
