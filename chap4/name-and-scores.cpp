#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Record and retrieve name and scores.   
 */
int main(){

    vector<string> names;
    vector<int> scores; 
   
    cout << "Enter name and score separated by space. Stop by entering: \"NoName 0\" \n";

    int score;
    string name;

    while(cin>>name>>score && name != "NoName"){
        names.push_back(name);
        scores.push_back(score);
    }
       
    // Retrieve score from records.
    cout << "\nEnter score to retrieve names with that score.\n"; 

    while(cin >> score){
        bool found = false;

        for(int i = 0; i <= scores.size(); i++){
            if(score == scores[i]){
                cout << names[i] << '\n';
                found = true;
            }
        }
        
        if(!found){
            cout << "No one has a score of " << score << '\n';
        }
    }


    return 0;
}