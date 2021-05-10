#include <iostream>
#include <vector>

using namespace std;


int main(){

    vector<double> temps;

    for(double temp = 69; temp < 100; temp++)
        temps.push_back(temp);

    for (double temp : temps)
        cout << temp << '\n';
    
    return 0;
}