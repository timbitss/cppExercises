#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n;
    cout << "Please enter an integer value: ";
    cin >> n;
    cout << "n = " << n
          << "\nn + 1 = " << n + 1
          << "\n3 * n = " << n * 3
          << "\nn squared = " << n*n
          << "\nhalf of n = " << n/2
          << "\nsquare root of n = " << sqrt(n)
          << '\n';


    return 0;
}