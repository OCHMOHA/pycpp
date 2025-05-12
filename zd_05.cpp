#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double g = 9.81;

double y(double T, double U, double H) {
    return H - (g * T * T) / 2.0;
}

double dy(double T) {
    return -g * T;
}


double newton_method(double U, double H, double T_initial, double epsilon = 1e-6, int max_iter = 100) {
    double T = T_initial;
    for (int i = 0; i < max_iter; ++i) {
        double y_val = y(T, U, H);
        double dy_val = dy(T);
        
        if (dy_val == 0) {
            cout << "Derivative is zero." << endl;
            return -1;
        }
        
        double T_new = T - y_val / dy_val;
        
        if (abs(T_new - T) < epsilon) {
            return T_new;
        }
        
        T = T_new;
    }
    
    cout << "Did not converge in " << max_iter << " iterations" << endl;
    return -1;
}

int main() {
    double H = 50;    
    double U = 400;   
    
    double T_initial = sqrt(2 * H / g);
    double epsilon = 1e-6;
    
    double T = newton_method(U, H, T_initial, epsilon);
    
    if (T != -1) {
        cout << fixed << setprecision(6);
        cout << "Bomb flight time T: " << T << " seconds" << endl;
        
        double t;
        cout << "Enter time t (in seconds): ";
        cin >> t;
        
        double x = U * t;
        cout << "Horizontal distance x(t): " << x << " meters" << endl;
    }
    
    return 0;
}
