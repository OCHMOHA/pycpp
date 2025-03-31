#include <iostream>
#include <cmath>

using namespace std;

// Function to calculate path S
double calculateS(double V, double t) {
    double S1 = V * t;
    double a = V / t;
    double S2 = a * t * t / 2;
    return S1 + S2;
}

// Function for Newton's method
double newtonMethod(double V, double t, double initialGuess, double epsilon) {
    double S = initialGuess;
    double delta;

    do {
        double f = S - (3 * V * t / 2); // Equation for Newton's method
        double df = 1; // Derivative of function f with respect to S
        delta = f / df;
        S -= delta;
    } while (abs(delta) > epsilon);

    return S;
}

int main() {
    double V, t;
    cout << "Enter speed V: ";
    cin >> V;
    cout << "Enter time t: ";
    cin >> t;

    double S_calculated = calculateS(V, t);
    cout << "Path S calculated by formula: " << S_calculated << endl;

    double initialGuess = S_calculated; // Initial guess
    double epsilon = 1e-6; // Precision

    double S_newton = newtonMethod(V, t, initialGuess, epsilon);
    cout << "Path S calculated by Newton's method: " << S_newton << endl;

    return 0;
}