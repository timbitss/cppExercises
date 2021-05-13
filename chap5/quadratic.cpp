#include <iostream>
#include <cmath>

void quadratic(double a, double b, double c);

using namespace std;

/**
 * Q7:
 * Prompts user for a, b, and c terms of the quadratic equation.
 * Then computes the roots of the quadratic equation.
 */
int main(){

    cout << "Enter a, b, and c terms of the quadratic equation.\n";

    double a, b, c;
    cin >> a >> b >> c;

    try{
        quadratic(a,b,c);
    }catch(exception& e){
        cerr << "Error: " << e.what() << '\n';
        return 1;
    }catch(...){
        cerr << "Unknown error.\n";
        return 2;
    }

    return 0;
}

/**
 * Calculate real roots of quadratic equation.
 * If discriminant is less than zero, error is thrown.
 */
void quadratic(double a, double b, double c){

    int discriminant = b*b-4*a*c;
    if (discriminant < 0) throw runtime_error("Discriminant is less than 0.");

    cout << "x_1 = " << (-b + sqrt(discriminant))/(2*a) << '\n';
    cout << "x_2 = " << (-b - sqrt(discriminant))/(2*a) << '\n';

}