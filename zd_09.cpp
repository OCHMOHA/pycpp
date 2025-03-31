#include <iostream>
#include <cmath>

using namespace std;

// Function to calculate initial phase phi0
double calculatePhi0(double k) {
    return asin(1 / k);
}

// Function to calculate time T
double calculateT(double omega, double phi0) {
    return (M_PI / 2 - phi0) / omega;
}

// Function for iteration method
double iterationMethod(double omega, double k, double initialGuess, double epsilon) {
    double T = initialGuess;
    double delta;

    do {
        double phi0 = calculatePhi0(k);
        double newT = calculateT(omega, phi0);
        delta = newT - T;
        T = newT;
    } while (abs(delta) > epsilon);

    return T;
}

int main() {
    double omega, k;
    cout << "Enter frequency omega: ";
    cin >> omega;
    cout << "Enter parameter k: ";
    cin >> k;

    double initialGuess = 0; // Initial guess
    double epsilon = 1e-6; // Precision

    double T = iterationMethod(omega, k, initialGuess, epsilon);
    cout << "Time moment T when pendulum deflection is maximum: " << T << endl;

    return 0;
}