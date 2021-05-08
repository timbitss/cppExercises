#include <iostream>
#include <string>

using namespace std;

/**
 * Repeated word counter. 
 * Case-sensitive.
 */
int main(){

    int count = 0;
    string previous = " ", current;

    cin >> previous;

    while(cin >> current){          
        if (current == previous){
            count++;
            cout << "You repeated " << previous << " " << count << " times!\n";
        }
        else{
            previous = current; 
            count = 0;
        }
    }

    return 0;
}