#include <iostream>
#include <string>

using namespace std;

/**
 * Takes an operation followed by two operands and outputs the result.
 */
int main(){

    char op = ' ';
    double operand1 = 0, operand2 = 0;

    cout << "Enter operator followed by two operands, separated by white-space.\n";

    while(cin >> op >> operand1 >> operand2){
        if (op == '+')
            cout << (operand1 + operand2) << '\n';
        else if (op == '-')
            cout << (operand1 - operand2) << '\n';
        else if (op == '*')
            cout << (operand1 * operand2) << '\n';
        else if (op == '/')
            cout << (operand1 / operand2) << '\n';
        else
            cout << "Operand not identifiable.\n";
        
        cout << "Enter another operator followed by two operands, separated by white-space.\n";
    }


    return 0;
}