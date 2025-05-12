#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double g = 9.81; 
const double V = 20;    
const double a = 45;    
const double H = 10;    

double y(double T, double V, double a, double H) {
    return H + V * T * sin(a) - (g * pow(T, 2)) / 2.0;
}

double dy(double T, double V, double a) {
    return V * sin(a) - g * T;
}

double newton_method(double V, double a, double H, double initial_guess, double tolerance=1e-6, int max_iterations=100) {
    double T = initial_guess;
    for (int i = 0; i < max_iterations; ++i) {
        double y_val = y(T, V, a, H);
        double dy_val = dy(T, V, a);

        if (dy_val == 0) {
            cout << "derivative is zero" << endl;
            return -1;
        }

        double T_new = T - y_val / dy_val;

        if (abs(T_new - T) < tolerance) {
            return T_new;
        }

        T = T_new;
    }

    cout << "did not converge in " << max_iterations << " iterations." << endl;
    return -1;
}

int main() {
    double a_rad = a * M_PI / 180.0; 
    double initial_guess = (V * sin(a_rad)) / g;

    double T = newton_method(V, a_rad, H, initial_guess);

    if (T != -1) {
        cout << fixed << setprecision(10);
        cout << "Flight time T: " << T << " seconds" << endl;

        double t;
        cout << "Enter time t (in seconds): ";
        cin >> t;

        double x = V * t * cos(a_rad);
        double y_val = max(H + V * t * sin(a_rad) - (g * pow(t, 2))/2.0, 0.0);

        cout << setprecision(6);
        cout << "Horizontal distance x(t): " << x << " meters" << endl;
        cout << "Height from the bottom of the cliff y(t): " << y_val << " meters" << endl;
    }

    return 0;
}
