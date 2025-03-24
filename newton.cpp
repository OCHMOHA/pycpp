#include <iostream>
#include <cmath>
using namespace std;


double exampleFunction(double x) {
    return x * x * x - 0.2 * x * x + 0.5 * x - 1;
}


double derivativeExampleFunction(double x) {
    return 3 * x * x - 0.4 * x + 0.5;
}

// Newton's method to find the root of the equation

pair<double, int> newtonMethod(double (*f)(double), double (*df)(double), double x0, double epsilon, int max_iter) {
    double x = x0;  // Initial guess
    for (int i = 0; i < max_iter; ++i) {
        double f_x = f(x);            
        double f_derivative = df(x);  


        if (fabs(f_derivative) < 1e-10) {
            cerr << "Derivative too small, unable to continue.\n";
            return {NAN, i + 1}; 
        }


        double x_new = x - f_x / f_derivative;

        // Check for convergence
        if (fabs(x_new - x) < epsilon) {
            return {x_new, i + 1};  // root and the number of iterations
        }

        x = x_new;
    }


    cerr << "Maximum number of iterations reached. No convergence.\n";
    return {NAN, max_iter};
}

int main() {
    double x0 = 1.0;  
    double epsilon = 1e-6;  
    int max_iter = 100;  


    auto [root, iterations] = newtonMethod(exampleFunction, derivativeExampleFunction, x0, epsilon, max_iter);


    if (isnan(root)) {
        cout << "The method did not converge." << endl;
    } else {
        cout << "Root of the equation: " << root << endl;
        cout << "Number of iterations: " << iterations << endl;
        cout << "Value of the function: " << exampleFunction(root) << endl;
    }

    return 0;
}
