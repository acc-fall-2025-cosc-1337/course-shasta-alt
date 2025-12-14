// main.cpp
#include <iostream>
#include "hwexpressions.h"

using namespace std;

int main()
{
    double meal_amount, tip_rate;
    double sales_tax, tip_amount, total;

    cout << "Enter the meal amount: ";
    cin >> meal_amount;

    cout << "Enter the tip rate (e.g., 0.15 for 15%): ";
    cin >> tip_rate;

    sales_tax = get_sales_tax_amount(meal_amount);
    tip_amount = get_tip_amount(meal_amount, tip_rate);
    total = meal_amount + sales_tax + tip_amount;

    cout << "\n--- Receipt ---" << endl;
    cout << "Meal Amount: $" << meal_amount << endl;
    cout << "Sales Tax:   $" << sales_tax << endl;
    cout << "Tip Amount:  $" << tip_amount << endl;
    cout << "Total:       $" << total << endl;

    return 0;
}
