#include <iostream>

using namespace std;

/**
 * Determines smaller, larger, sum, difference, product, and ratio of two values
 * and reports them to the user. 
 */
int main(){

    double num1 = 0, num2 = 0;

    cout << "Enter two numbers to be compared\n";
    cin >> num1 >> num2;

    cout << "The smaller of the two numbers is " << ((num1 < num2) ? num1 : num2) << '\n';
    cout << "The larger of the two numbers is "  << ((num1 > num2) ? num1 : num2) << '\n';
    cout << "The sum of the two numbers is " << (num1 + num2) << '\n';
    cout << "The difference of the two numbers is " << (num1 - num2) << '\n';
    cout << "The product of the two numbers is " << (num1*num2) << '\n';
    cout << "The ratio of these two numbers is " << (num1/num2) << '\n'; 
    
    return 0;
}