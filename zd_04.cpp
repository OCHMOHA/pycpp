#include <iostream>
#include <cmath>

using namespace std;

const double g = 9.81;  // Gravitational acceleration (m/s^2)

// Function to calculate y(t) — height from the bottom of the cliff at time t
double y(double T, double V, double alpha, double H) {
    return H + V * T * sin(alpha) - (g * T * T) / 2.0;
}

double dy(double T, double V, double alpha) {
    return V * sin(alpha) - g * T;
}

// Newton's method to calculate flight time T
double newtonMethod(double V, double alpha, double H, double initialGuess, double tolerance = 1e-6, int maxIterations = 100) {
    double T = initialGuess;
    for (int i = 0; i < maxIterations; ++i) {
        double yVal = y(T, V, alpha, H);  // Calculate y(T)
        double dyVal = dy(T, V, alpha);   // Calculate derivative dy/dt

        if (dyVal == 0) {
            cout << "The derivative is zero. Newton's method cannot be applied." << endl;
            return -1;
        }

        double Tnew = T - yVal / dyVal;

        // Check for convergence 
        if (abs(Tnew - T) < tolerance) {
            return Tnew;
        }

        T = Tnew;  
    }

    cout << "Newton's method did not converge within " << maxIterations << " iterations." << endl;
    return -1;
}

int main() {
    double V, alpha, H, t;

    cout << "Enter the initial velocity V (in m/s): ";
    cin >> V;
    cout << "Enter the angle alpha (in degrees): ";
    cin >> alpha;
    cout << "Enter the height of the cliff H (in meters): ";
    cin >> H;

    // Convert angle to radians
    double alphaRad = alpha * M_PI / 180.0;

    // Initial guess for flight time
    double initialGuess = (V * sin(alphaRad)) / g;

    double T = newtonMethod(V, alphaRad, H, initialGuess);


    if (T != -1) {
        cout << "Flight time : " << T << " seconds" << endl;

        cout << "Enter time t (in seconds): ";
        cin >> t;

        double x = V * t * cos(alphaRad);
        double yVal = H + V * t * sin(alphaRad) - (g * t * t) / 2.0;

        yVal = (yVal > 0) ? yVal : 0;

        // Print the results
        cout << "Horizontal distance x(t): " << x << " meters" << endl;
        cout << "Height from the bottom of the cliff y(t): " << yVal << " meters" << endl;
    }

    return 0;
}
