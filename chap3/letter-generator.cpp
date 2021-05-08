#include <iostream>
#include <string>

using namespace std;

/**
 * Generate a generic letter to a friend based on inputs.
 */
int main(){
    
    string friend1_name, friend2_name;
    char friend_gender = 0;
    int age = 0;
    
    cout << "Enter recipient's first name.\n";
    cin >> friend1_name;

    cout << "Enter name of another friend.\n";
    cin >> friend2_name;

    cout << "Enter gender of the other friend. (m/f)\n";
    cin >> friend_gender; 

    cout << "Enter age of recipient.\n";
    cin >> age;

    cout << "\nDear " << friend1_name << ",\n\n" 
         << "    How are you? I miss seeing you every day.\n";
    cout << "I'd like to ask, \"Have you seen " << friend2_name << " lately?\"\n";

    if(friend_gender == 'm')
        cout << "If you see " << friend2_name << ", please ask him to call me.\n";
    else
        cout << "If you see " << friend2_name << ", please ask her to call me.\n";
    
    if(age < 12)
        cout << "Wow! Next year you will be " << age << " years old!\n";
    
    if (age == 17)
        cout << "Wow! Next year you will be able to vote.\n";

    if (age > 70)
        cout << "Wow! I hope you are enjoying retirement.\n";

    cout << "It's amazing how fast time flies by.\n"
         << "I hope to see you on campus after this pandemic.\n\n"
         << "Yours sincerely,\n"
         << "Timothy Nguyen\n";

    return 0;
}