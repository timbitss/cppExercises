#include <iostream>
#include <string>
#include <vector>


using namespace std;
/**
 * BLEEPS out foods that are in blacklist.
 */
int main(){

    vector<string> blacklist = {"broccoli", "mushrooms", "olives"};
    vector<string> ingredients; 

    cout << "Enter ingredients of recipe.\n";

    for(string ingredient; cin >> ingredient; )
        ingredients.push_back(ingredient);

    cout << "Ingredients in recipe are: ";
    for (string ingredient : ingredients){
        if(ingredient == "broccoli" || ingredient == "mushrooms" || ingredient == "olives")
            cout << "BLEEP, "; 
        else   
            cout << ingredient << " ";
    }
    cout << '\n';

    return 0;
}