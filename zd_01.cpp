#include <iostream>
#include <cmath>
using namespace std;

const double g = 9.81;

double f(double alpha, double V, double T) {
    return 2 * V * sin(alpha) - g * T;
}

double df(double alpha, double V) { // Derivative of f(α)
    return 2 * V * cos(alpha);
}

double newton_method(double V, double T, double initial_guess, double tol) {
    double alpha = initial_guess;
    double h = f(alpha, V, T) / df(alpha, V);
    
    while (abs(h) >= tol) {
        alpha -= h;
        h = f(alpha, V, T) / df(alpha, V);
    }
    return alpha;
}

int main() {
    double V, T;
    cout << "Enter initial velocity (V): ";
    cin >> V;
    cout << "Enter flight time (T): ";
    cin >> T;


    double alpha_rad = newton_method(V, T, M_PI / 4, 1e-6);
    double alpha_deg = alpha_rad * 180 / M_PI;

    cout << "Angle α (in radians): " << alpha_rad << endl;
    cout << "Angle α (in degrees): " << alpha_deg << endl;

    return 0;
}