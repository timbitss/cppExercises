#include <iostream>
#include <vector>
#include <string> 
#include "include/fib.h"


/**
 * @brief Computes Fibonacci sequence starting from x and y.
 * 
 * @param x first number
 * @param y second number
 * @param v empty vector of integers to hold Fibonacci sequence 
 * @param n size of Fibonacci sequence
 * 
 * @pre size of Fibonacci sequence must be >= 2
 */
void fibonacci(int x, int y, std::vector<int>& v, int n)
{
    if(n < 2) throw std::runtime_error("Size of fibonacci sequence must be >= 2.\n");

    for(int i = 0; i <= n - 2; i++)
    {
        if(i == 0)
        {
            v.push_back(x);
            v.push_back(y);
        }
        else
        {
            v.push_back(v[v.size() - 1] + v[v.size() - 2]);
        }
        
    }

}

/**
 * @brief Print vector objects sequentially with a label
 * 
 * @param s label to print
 * @param v vector of objects to print
 */
void print(std::string s, const std::vector<int>& v)
{
    std::cout << s << ' ';
    for(auto x: v)
        std::cout << x << ' ';
    std::cout << '\n';
}