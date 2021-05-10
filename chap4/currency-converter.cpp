#include <iostream>

using namespace std;

/**
 * Takes in different currencies and converts to CAD.
 */
int main()
{
    constexpr double dollar_per_yen = 1/90.10;
    constexpr double dollar_per_kroner = 1/6.82;
    constexpr double dollar_per_pounds = 1/0.59;

    double amount = 0.0;
    char currency = ' ';

    cout << "Please enter amount followed by currency (k for kroner, p for pounds, y for yen):\n";
    cin >> amount >> currency;

    switch(currency){
    case 'k':
        cout << amount << " kroner = " << amount * dollar_per_kroner << " CAD\n";
        break;
    case 'p':
        cout << amount << " pounds == " << amount * dollar_per_pounds << " CAD\n";
        break;
    case 'y':
        cout << amount << " yens == " << amount * dollar_per_yen << " CAD\n";
        break;
    default:
        cout << "Invalid input.\n";
        break;
    }

    return 0; 
}