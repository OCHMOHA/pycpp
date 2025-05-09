#include <iostream>
#include <cmath>
using namespace std;

const double H = 5.0;      // Max height in meters
const double L = 20.0;     // Horizontal range in meters
const double g = 9.81;     // Acceleration due to gravity

// Function: f(x) = 4H / L (constant)
double exmp_function(double x) {
    return (4 * H / L);
}

// Iterative method to solve for alpha
double iter_method(double x_0, double epsilon) {
    double x = x_0;
    int iter = 0;
    while (true) {
        double x_new = 4 * H / L;  // Fixed value
        if (abs(x_new - x) < epsilon) {
            cout << "Number of iterations: " << iter << endl;
            return x_new;
        }
        x = x_new;
        iter++;
    }
}

int main() {
    double x_0 = 0.5;          // Initial guess in radians
    double epsilon = 1e-8;     // Tolerance

    double x_root = iter_method(x_0, epsilon);
    cout << "Solving the equation: x = " << x_root << " radians ("
         << x_root * (180.0 / M_PI) << " degrees)" << endl;

    // Compute V using V = sqrt(gL / sin(2 * alpha))
    double V = sqrt(g * L / sin(2 * x_root));
    cout << "Initial velocity V = " << V << " m/s" << endl;

    return 0;
}