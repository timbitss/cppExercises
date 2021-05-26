#include <iostream> 

int factorial(int x); // Compute factorial

int permutation(int tot, int sel); // Compute permutation

int combination(int tot, int sel); // Compute combination

using namespace std;

/**
 * Computer either permutation or combination given total number of objects and objects to select. 
 */
int main(){
    try{
        int total, select;

        cout << "Enter total number of objects and objects to select.\n";
        if(!(cin >> total >> select)) throw runtime_error("Numbers must be two integers.");
        
        cout << "Would you like to compute the permutation or the combination? (p/c)\n";
        char choice;
        cin >> choice;

        switch (choice){
            case 'p':
                cout << "Permutation: " << permutation(total, select) << '\n';
                break;
            case 'c':
                cout << "Combination: " << combination(total, select) << '\n';
                break;
            default:
                throw runtime_error("Choice not recognized.");
                break;
        }
    }
    catch(exception& e){
        cerr << "Error: " << e.what() << '\n';
        return 1;
    }

    return 0;
}


int factorial(int x){
    if(x == 0 || x == 1) 
        return 1;
    else
        return x * factorial(x-1);
}

int permutation(int tot, int sel){
    if(tot < sel || tot < 1 || sel < 1) throw runtime_error("Invalid inputs.\n");
    return (factorial(tot)/factorial(tot-sel));
}

int combination(int tot, int sel){
    if(tot < sel || tot < 1 || sel < 1) throw runtime_error("Invalid inputs.\n");
    return (permutation(tot, sel)/factorial(sel));
}
