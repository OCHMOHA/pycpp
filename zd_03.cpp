#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double g = 9.81;


double f(double alpha, double H, double L) {
    return (4*H)/L - tan(alpha);
}


double df(double alpha) {
    return -1.0/pow(cos(alpha), 2);
}


double newton_method(double H, double L, double initial_guess, double tol = 1e-6) {
    double alpha = initial_guess;
    for (int i = 0; i < 100; ++i) {
        double step = f(alpha, H, L)/df(alpha);
        alpha -= step;
        if (abs(step) < tol) break;
    }
    return alpha;
}

int main() {
    double H, L;
    
    cout << "Enter maximum height (H): ";
    cin >> H;
    cout << "Enter range (L): ";
    cin >> L;


    double initial_guess = atan(4*H/L);
    
    // Solve using Newton's method
    double alpha_rad = newton_method(H, L, initial_guess);
    double alpha_deg = alpha_rad * 180/M_PI;
    
    // Calculate velocity
    double V = sqrt((g*L)/sin(2*alpha_rad));


    cout << fixed << setprecision(6);
    cout << "\nResults:" << endl;
    cout << "Launch angle (α): " << alpha_deg << " degrees" << endl;
    cout << "Initial velocity (V): " << V << " m/s" << endl;
    cout << "Validation:" << endl;
    cout << "Max height should be: " << H << " m" << endl;
    cout << "Calculated max height: " << pow(V,2)*pow(sin(alpha_rad),2)/(2*g) << " m" << endl;

    return 0;
}