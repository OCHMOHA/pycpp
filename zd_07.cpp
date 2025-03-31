#include <iostream>
#include <cmath>

using namespace std;

// Function to calculate V2
double calculateV2(double V, double S, double t, double V1) {
    return S / (2 * S / V - t);
}

// Bisection method function
double bisectionMethod(double V, double S, double t, double a, double b, double epsilon) {
    double V1 = S / t; // Calculate V1
    double V2_a = calculateV2(V, S, t, a);
    double V2_b = calculateV2(V, S, t, b);

    while (fabs(V2_a - V2_b) > epsilon) {
        double mid = (a + b) / 2;
        double V2_mid = calculateV2(V, S, t, mid);

        if (V2_mid * V2_a < 0) {
            b = mid;
            V2_b = V2_mid;
        } else {
            a = mid;
            V2_a = V2_mid;
        }
    }

    return (a + b) / 2;
}

int main() {
    double V, S, t;
    cout << "Enter average speed V: ";
    cin >> V;
    cout << "Enter distance S: ";
    cin >> S;
    cout << "Enter time t: ";
    cin >> t;

    double V1 = S / t;
    cout << "Speed V1: " << V1 << endl;

    double a = 0, b = 2 * V; // Initial bounds for V2
    double epsilon = 1e-6; // Precision

    double V2 = bisectionMethod(V, S, t, a, b, epsilon);
    cout << "Speed V2: " << V2 << endl;

    return 0;
}