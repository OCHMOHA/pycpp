#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double calculate_phi0(double k) {
    return asin(1 / k);
}

double calculate_T(double omega, double phi0) {
    return (M_PI / 2 - phi0) / omega;
}

double iteration_method(double T_initial, double epsilon, double omega, double k) {
    double T = T_initial;
    int iter = 0;
    while (true) {
        double phi0 = calculate_phi0(k);
        double T_new = calculate_T(omega, phi0);
        if (abs(T_new - T) < epsilon) {
            cout << "Number of iterations: " << iter << endl;
            return T_new;
        }
        T = T_new;
        iter++;
    }
}

int main() {
    double omega = 10;
    double k = 5;

    double T_initial = 0;
    double epsilon = 1e-6;
    double T = iteration_method(T_initial, epsilon, omega, k);
    
    cout << fixed << setprecision(6);
    cout << "Time moment when pendulum deflection is maximum: " << T << endl;

    return 0;
}
