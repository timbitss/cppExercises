#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>

using namespace std;

double convert_to_meters(double distance, string unit);

/**
 * Converts cm, in, ft to m and prints smallest, largest, and total distance in meters.
 */
int main(){

    double distance = 0, total_distance = 0;
    string unit;
    vector<double> distances;

    for(; cin >> distance >> unit; ){
        distance = convert_to_meters(distance, unit);

        if(distance == -1) 
            continue;        // continue if illegal distance
        else
            distances.push_back(distance);
    }

    // Sort from smallest to largest value
    sort(distances.begin(), distances.end());

    for(double d : distances){
        total_distance += d;
    }


    // Print out results
    cout << "Smallest distance = " << distances[0] << " m\n"
         << "Largest distance = " << distances[distances.size() - 1] << " m\n"
         << "Total distance = " << total_distance << " m\n"
         << "Number of values = " << distances.size();

    cout << "\nSorted distances:\n";
    for(double d : distances){
        cout << d << ' ';
    }

    return 0;
}


/**
 * Returns distance in meters. 
 * Returns -1 if distance is negative or unit is "illegal".
 */
double convert_to_meters(double distance, string unit){
    constexpr double m_per_cm = 1.0/100;
    constexpr double in_per_cm = 1/2.54;
    constexpr double ft_per_in = 1.0/12;

    if(distance < 0){
        cout << "Invalid input.\n";
        return -1;
    }
    else if (unit == "m"){
        return distance;
    }
    else if(unit == "cm"){
        return distance * m_per_cm;
    }
    else if(unit == "in"){
        return (distance / in_per_cm) * m_per_cm;
    }
    else if(unit == "ft"){
        return (distance / ft_per_in) / in_per_cm * m_per_cm;
    }
    else{
        cout << "Invalid input.\n";
        return -1;
    }
}