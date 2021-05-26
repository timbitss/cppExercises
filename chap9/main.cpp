#include <iostream>
#include "include/Name_pairs.h"

/* Testing Name_pairs class */
int main()
{
    try
    {
        record::Name_pairs test1, test2;

        test1.read_names();
        test1.read_ages();
        test1.sort();
        std::cout << test1;

        test2.read_names();
        test2.read_ages();
        test2.sort();
        std::cout << test2;
        
        if(test1 == test2) 
            std::cout << "Name pairs are equal.\n";
        else
            std::cout << "Name pairs are not equal.\n";

        if(test1 != test2) 
            std::cout << "Name pairs are not equal.\n";
        else
            std::cout << "Name pairs are equal.\n";
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << "\n";
        return 1;
    }
    catch(...)
    {
        std::cerr << "Unknown error\n";
        return 2;
    }

    return 0;   
}