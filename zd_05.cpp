#include <iostream>
#include <cmath>

using namespace std;

const double g = 9.81; 

double calculateTime(double height) {
    return sqrt(2 * height / g);
}

double calculateDistance(double velocity, double time) {
    return velocity * time;
}

double secantMethod(double (*function)(double), double x0, double x1, double epsilon = 1e-6, int maxIterations = 100) {
    double x2;
    for (int i = 0; i < maxIterations; ++i) {
        if (function(x1) - function(x0) == 0) {
            cout << "Secant method failed: f(x1) - f(x0) = 0." << endl;
            return -1;
        }
        x2 = x1 - function(x1) * (x1 - x0) / (function(x1) - function(x0));
        if (abs(x2 - x1) < epsilon) {
            return x2;
        }
        x0 = x1;
        x1 = x2;
    }
    cout << "Secant method did not converge after " << maxIterations << " iterations." << endl;
    return -1;
}

int main() {
    double altitude, velocity;

    cout << "Enter aircraft altitude H (in meters): ";
    cin >> altitude;
    cout << "Enter aircraft speed U (in m/s): ";
    cin >> velocity;

    double time = calculateTime(altitude);
    double distance = calculateDistance(velocity, time);

    cout << "Bomb flight time T: " << time << " seconds" << endl;
    cout << "Horizontal distance S: " << distance << " meters" << endl;

    return 0;
}