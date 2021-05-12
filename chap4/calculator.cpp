#include <iostream>
#include <string>

using namespace std;

int convertToNum(string number);

/**
 * Simple calculator that can perform add, subtract, multiply, and divide on two input values.
 * Modified to only accept single digit values as either digits or spelled out
 */
int main(){

    string val1, val2;
    int i_val1, i_val2;
    char operation;

    do{
        cout << "Enter two single digit values followed by operation (+, -, *, or /)\n";
        cin >> val1 >> val2 >> operation;
        i_val1 = convertToNum(val1);
        i_val2 = convertToNum(val2);
    } while(i_val1 == -1 || i_val2 == -1);

    switch (operation){
        case '+':
            cout << i_val1 + i_val2 << '\n';
            break;
        case '-':
            cout << i_val1 - i_val2 << '\n';
            break;
        case '*':
            cout << i_val1 * i_val2 << '\n';
            break;
        case '/':
            cout << double(i_val1) / i_val2 << '\n';
            break;
        default:
            cout << "Operation not recognized\n";
            break;
    }


    return 0;
}

/**
 * Converts digit represented by string to int type.
 * Returns -1 if number entered is not a digit. 
 */
int convertToNum(string number){
    
    if(number.size() == 1){
        if(int(number[0]) >= 48 && int(number[0]) <= 57){  // return integer value if number entered is not in words
            return int(number[0]) - 48; 
        }
        else{
            return -1;
        }
    }
    else if(number == "nine"){
        return 9;
    }
    else if(number == "eight"){
        return 8;
    }
    else if(number == "seven"){
        return 7;
    }
    else if(number == "six"){
        return 6;
    }
    else if(number == "five"){
        return 5;
    }
    else if(number == "four"){
        return 4;
    }
    else if(number == "three"){
        return 3;
    }
    else if(number == "two"){
        return 2;
    }
    else if(number == "one"){
        return 1;
    }
    else if(number == "zero"){
        return 0;
    }
    else{
        return -1;
    }

}


