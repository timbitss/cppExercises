#include <iostream>
#include "include/fib.h"

/* Testing out fib.cpp */
int main(){

    std::vector<int> someNums;
    int x = 1, y = 2, size = 10;
    std::string s = "Fibonnaci sequence: ";
    
    try
    {
        fibonacci(x, y, someNums, size);
        print(s, someNums);
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    catch(...)
    {
        std::cerr << "Error.\n";
        return 2;
    }

    return 0;
}