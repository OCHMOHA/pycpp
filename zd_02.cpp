#include <iostream>
#include <cmath>
#include <limits>

const double g = 9.81;  


double f(double alpha, double V, double L) {
    return (V * V * sin(2 * alpha)) / g - L;
}


double df(double alpha, double V) {
    return (2 * V * V * cos(2 * alpha)) / g;
}


double newton_method(double V, double L, double initial_guess, double tol = 1e-6, int max_iter = 100) {
    double alpha = initial_guess;
    for (int i = 0; i < max_iter; ++i) {
        double f_val = f(alpha, V, L);
        double df_val = df(alpha, V);
        
        // Avoid division by near-zero
        if (abs(df_val) < 1e-10) break;
        
        double delta = f_val / df_val;
        alpha -= delta;
        
        if (abs(delta) < tol) break;
    }
    return alpha;
}

int main() {
    double V, L;
    std::cout << "Enter initial velocity (V): ";
    std::cin >> V;
    std::cout << "Enter desired range (L): ";
    std::cin >> L;
    
    const double L_max = V * V / g;
    if (L > L_max) {
        std::cout << "Error: Desired range " << L 
                  << " m exceeds maximum possible range " << L_max << " m.\n";
    } else {

        double alpha_rad = newton_method(V, L, M_PI/4);
        double alpha_deg = alpha_rad * 180 / M_PI;
        
        // Validate physical angle bounds
        if (alpha_deg >= 0 && alpha_deg <= 90) {
            std::cout << "Required launch angle α: " << alpha_deg << "°\n";
        } else {
            std::cout << "Newton's Method failed to converge. Try another method.\n";
        }
    }
    return 0;
}