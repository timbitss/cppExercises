#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;

#define NICKEL  0.05
#define DIME    0.10
#define QUARTER 0.25
#define LOONIE  1.00
#define TOONIE  2.00    

/**
 * Prints out total value of coins in dollars and cents.
 */
int main(){

    int nickels, dimes, quarters, loonies, toonies;

    cout << "How many nickels do you have?\n";
    cin >> nickels;
    cout << "You have " << nickels << " nickel" << (nickels != 1 ? "s.\n" : ".\n");

    cout << "How many dimes do you have?\n";
    cin >> dimes;
    cout << "You have " << dimes << " dime" << (dimes != 1 ? "s.\n" : ".\n");

    cout << "How many quarters do you have?\n";
    cin >> quarters;
    cout << "You have " << quarters << " quarter" << (quarters != 1 ? "s.\n" : ".\n");    

    cout << "How many loonies do you have?\n";
    cin >> loonies;
    cout << "You have " << loonies << " loonie" << (loonies != 1 ? "s.\n" : ".\n") ;

    cout << "How many toonies do you have?\n";
    cin >> toonies;
    cout << "You have " << toonies << " toonie" << (toonies != 1 ? "s.\n" : ".\n");

    printf("The value of all your coins is %.2lf\n", 
    (nickels * NICKEL + dimes * DIME + quarters * QUARTER + loonies * LOONIE + toonies * TOONIE));
            
    return 0;
}