#include <iostream>
#include <cmath>

using namespace std;

// Function to calculate the total travel time of the boat
double calculateTime(double S, double V, double U) {
    double t1 = S / (V + U);  // Time downstream (with current)
    double t2 = S / (V - U);  // Time upstream (against current)
    return t1 + t2;           // Total time
}

// Newton's method function
double newtonMethod(double S, double V, double U, double initialGuess, double tolerance = 1e-6, int maxIterations = 100) {
    double T = initialGuess;
    for (int i = 0; i < maxIterations; ++i) {
        double f = calculateTime(S, V, U) - T;
        double df = -1;  // Derivative of f(T) = calculateTime(S, V, U) - T

        if (df == 0) {
            cout << "Derivative is zero. Newton's method cannot be applied." << endl;
            return -1;
        }

        double Tnew = T - f / df;

        if (abs(Tnew - T) < tolerance) {
            return Tnew;
        }

        T = Tnew;
    }

    cout << "Newton's method did not converge in " << maxIterations << " iterations." << endl;
    return -1;
}

int main() {
    double S, V, U;

    // User input
    cout << "Enter distance between points S (in meters): ";
    cin >> S;
    cout << "Enter boat speed V (in m/s): ";
    cin >> V;
    cout << "Enter river current speed U (in m/s): ";
    cin >> U;

    // Validate input
    if (V <= U) {
        cout << "Boat speed must be greater than river current speed." << endl;
        return 1;
    }

    // Initial guess for travel time
    double initialGuess = S / V;

    // Calculate total travel time using Newton's method
    double T = newtonMethod(S, V, U, initialGuess);

    if (T != -1) {
        cout << "Total boat travel time T: " << T << " seconds" << endl;
    }

    return 0;
}