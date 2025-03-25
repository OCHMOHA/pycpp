import math

g = 9.81  # Gravitational acceleration (m/s^2)

def y(T, V, alpha, H):
    return H + V * T * math.sin(alpha) - (g * T**2) / 2.0

def dy(T, V, alpha):
    return V * math.sin(alpha) - g * T

def newton_method(V, alpha, H, initial_guess, tolerance=1e-6, max_iterations=100):
    T = initial_guess  # Initial guess for time
    for i in range(max_iterations):
        y_val = y(T, V, alpha, H)  # Calculate y(T)
        dy_val = dy(T, V, alpha)   # Calculate derivative dy/dt

        if dy_val == 0:
            print("The derivative is zero. Newton's method cannot be applied.")
            return -1

        T_new = T - y_val / dy_val

        # Check for convergence 
        if abs(T_new - T) < tolerance:
            return T_new

        T = T_new  

    print(f"Newton's method did not converge within {max_iterations} iterations.")
    return -1

def main():

    V = float(input("Enter the initial velocity V (in m/s): "))
    alpha = float(input("Enter the angle alpha (in degrees): "))
    H = float(input("Enter the height of the cliff H (in meters): "))

    alpha_rad = math.radians(alpha)

    initial_guess = (V * math.sin(alpha_rad)) / g

    # Apply Newton's method 
    T = newton_method(V, alpha_rad, H, initial_guess)

    if T != -1:
        print(f"Flight time T: {T} seconds")

        t = float(input("Enter time t (in seconds): "))

        # Calculate horizontal and vertical positions at time t
        x = V * t * math.cos(alpha_rad)
        y_val = H + V * t * math.sin(alpha_rad) - (g * t**2) / 2.0

        y_val = max(y_val, 0)

        print(f"Horizontal distance x(t): {x} meters")
        print(f"Height from the bottom of the cliff y(t): {y_val} meters")

if __name__ == "__main__":
    main()
