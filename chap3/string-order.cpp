#include <iostream>
#include <string>

using namespace std;

/**
 * Print 3 words in alphabetical order. 
 * Note that capitalized words precede lower-case words by ASCII convention.
 */
int main(){

    string s1, s2, s3;

    cout << "Enter 3 words separated by space.\n";
    cin >> s1 >> s2 >> s3;

    if (s1 <= s2 && s1 <= s3){
        if(s2 <= s3)
            cout << s1 << ", " << s2 << ", " << s3 << '\n';
        else
            cout << s1 << ", " << s3 << ", " << s2 << '\n';
    }
    else if (s2 <= s1 && s2 <= s3){
        if(s1 <= s3)
            cout << s2 << ", " << s1 << ", " << s3 << '\n';
        else
            cout << s2 << ", " << s3 << ", " << s1 << '\n';
    }
    else{
        if(s2 <= s1)
            cout << s3 << ", " << s2 << ", "  << s1 << '\n';
        else
            cout << s3 << ", " << s1 << ", " << s2 << '\n';
    }
    
    return 0;
}