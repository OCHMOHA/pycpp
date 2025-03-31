#include <iostream>
#include <cmath>

using namespace std;

// Constants
const double G = 6.672e-11;  // Gravitational constant (Nm^2/kg^2)
const double M = 5.96e24;    // Mass of Earth (kg)
const double R = 6.37e6;     // Radius of Earth (m)

// Function to calculate f(h)
double f(double h, double g_target) {
    return G * M / pow(R + h, 2) - g_target;
}

// Derivative of function f(h)
double df(double h) {
    return -2 * G * M / pow(R + h, 3);
}

// Newton's method to find h
double newtonMethod(double g_target, double initialGuess, double epsilon) {
    double h = initialGuess;
    double delta;

    do {
        delta = f(h, g_target) / df(h);
        h -= delta;
    } while (abs(delta) > epsilon);

    return h;
}

int main() {
    double g_target;
    cout << "Enter target free-fall acceleration g_target (m/s^2): ";
    cin >> g_target;

    double initialGuess = 0; // Initial guess for h
    double epsilon = 1e-6; // Precision

    double h = newtonMethod(g_target, initialGuess, epsilon);
    cout << "Height h where free-fall acceleration equals " << g_target << " m/s^2: " << h << " m" << endl;

    return 0;
}