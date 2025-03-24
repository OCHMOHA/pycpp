#include <iostream>
#include <cmath>
#include <iomanip> 
using namespace std;

double example_function(double x) {
    return x * x * x - 0.2 * x * x + 0.5 * x - 1;
}

// Dichotomy (Bisection) method to find the root of a function
// f - pointer to the function
// a, b - interval where the root is searched
// epsilon - desired accuracy
// iter - number of iterations
double dichotomy_method(double (*f)(double), double a, double b, double epsilon, int& iter) {
        if (f(a) * f(b) > 0) {
        cerr << "The function must have opposite signs at the ends of the interval." << endl;
        return 0; 
    }

    iter = 0; 

    // Repeat the process while the interval is larger than the desired precision
    while ((b - a) / 2 > epsilon) {
        double c = (a + b) / 2;  // Midpoint of the interval
        iter++;  // Increase iteration count

        if (f(c) == 0) {
            return c;  // Exact root
        } 
        // Check where the root lies and update the interval
        else if (f(a) * f(c) < 0) {
            b = c;  // Root is between a and c
        } else {
            a = c;  // Root is between c and b
        }
    }

    // Return the midpoint of the final interval as the approximate root
    return (a + b) / 2;
}

// Main function
int main() {
    double a = 0;        
    double b = 3;      
    double epsilon = 1e-10; 
    int iter = 0;        

    double root = dichotomy_method(example_function, a, b, epsilon, iter);

    // Check if the root is valid
    if (!isnan(root)) {  
        cout << "Number of iterations: " << iter << endl;
        cout << "Solution of the equation: x = " << setprecision(10) << root << endl;
        double fun = example_function(root);
        cout << "Value of the function: f(" << root << ") = " << fun << endl;
    } else {
        cout << "The dichotomy method is not applicable to this interval." << endl;
    }

    return 0;
}
