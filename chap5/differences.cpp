#include <iostream>
#include <vector>
#include <string>

using namespace std;

void Differences(vector<double> numbers, int amount_to_sum);

/**
 * Q10:
 * Print differences between adjacent values
 */
int main(){

    int amount_of_diff;
    cout << "Please enter the number of differences you want between adjacent values:\n";
    cin >> amount_of_diff;

    vector<double> nums;
    cout << "Please enter numbers: \n";
    for(int num; cin>>num;){
        nums.push_back(num);
    }

    try{
        Differences(nums, amount_of_diff);
    }catch(exception& e){
        cerr << "Error: " << e.what() << '\n';
        return 1;
    }

    return 0;
}

/**
 * Compute difference between adjacent values. 
 * Throws error if insufficient amount of numbers to compute amount_of_diff differences. 
 */ 
void Differences(vector<double> numbers, int amount_of_diff){

    if(numbers.size()/(amount_of_diff*2) < 1) 
        throw runtime_error("Not enough numbers to compute " + to_string(amount_of_diff) + " differences.");
    else{
        vector<double> adjacent_diffs;
        for(int i = 0; i < amount_of_diff*2; i += 2)
            adjacent_diffs.push_back(numbers[i] - numbers[i+1]);
        for(double diff: adjacent_diffs)
            cout << diff << ' ';
    }

}