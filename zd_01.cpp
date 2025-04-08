#include <iostream>
#include <cmath>
using namespace std;

const double g = 9.81;

int main() {
    double V, T;
    cout << "Enter initial velocity (V): ";
    cin >> V;
    cout << "Enter flight time (T): ";
    cin >> T;

    double alpha = M_PI / 4;  // Start with 45 degrees (in radians)
    double tolerance = 1e-6;
    double f, df;

    do {
        f = 2 * V * sin(alpha) - g * T;   
        df = 2 * V * cos(alpha);          
        alpha -= f / df;                   
    } while (abs(f) > tolerance);         

    double alpha_deg = alpha * 180 / M_PI;

    cout << "Launch angle (radians): " << alpha << endl;
    cout << "Launch angle (degrees): " << alpha_deg << endl;

    return 0;
}
