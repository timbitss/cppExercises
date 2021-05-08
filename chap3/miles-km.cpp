#include <iostream>

#define RATIO 1.609 // km per mile

using namespace std;

/**
 * Convert from miles to kilometers.
 */
int main(){
    double miles = 0;

    cout << "Enter distance in miles.\n";
    cin >> miles;
    cout << "Distance in meters: " << miles * RATIO << "\n";
 
    return 0;
}