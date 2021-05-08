#include <iostream>
#include <string>

using namespace std;

/**
 * Purpose: Converts age from month to years.
 */
int main(){

    double age = 0;
    string firstName = "???", lastName = "???";
    
    cout << "Please enter your first and last name\n";
    cin >> firstName >> lastName;
    cout << "Please enter your age in years.\n";
    cin >> age;

    cout << "Hello " << firstName << " " << lastName << ". Your age in months: " << age * 12 << "\n";

    return 0;
}