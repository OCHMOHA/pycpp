#include <iostream>
#include <cmath>
using namespace std;

double example_function(double x) {
    return x * x * x - 0.2 * x * x + 0.5 * x - 1;
}

double chord_method(double (*f)(double), double a, double b, double eps, int max_iter) {
    int iteration = 0;
    if (f(a) * f(b) >= 0) {
        cerr << "The function must have opposite signs at the ends of the interval" << endl;
        return 0;
    }

    double x = a - (b - a) * f(a) / (f(b) - f(a));  // Initial guess using chord formula
    for (int i = 0; i < max_iter; ++i) {
        if (abs(f(x)) < eps) {  // Check for convergence
            break;
        }

        if (f(a) * f(x) < 0) {  // Root lies between a and x
            b = x;
        } else {  // Root lies between x and b
            a = x;
        }

        x = a - (b - a) * f(a) / (f(b) - f(a));  // Update x using chord method
        iteration++;
    }
    cout << "Number of iterations: " << iteration << endl;
    return x;
}


int main() {
    double a = 0;      // Start of the interval
    double b = 3;      // End of the interval
    double epsilon = 1e-6;  // Precision
    int max_iter = 1000;    // Maximum number of iterations

    double root = chord_method(example_function, a, b, epsilon, max_iter);

if (!isnan(root)) {  // Check if a valid root is found
    cout << "Root of the equation: " << root << endl;
    double fun = example_function(root);
    cout << "Value of the function: f(" << root << ") = " << fun << endl;
} else {
    cerr << "Root not found" << endl;
}

    return 0;
}
