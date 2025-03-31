import math

# Constants
G = 6.672e-11  # Gravitational constant (Nm^2/kg^2)
M = 5.96e24    # Mass of Earth (kg)
R = 6.37e6     # Radius of Earth (m)

# Function to calculate f(h)
def f(h, g_target):
    return G * M / (R + h)**2 - g_target

# Derivative of function f(h)
def df(h):
    return -2 * G * M / (R + h)**3

# Newton's method to find h
def newton_method(g_target, initial_guess, epsilon):
    h = initial_guess
    delta = 0

    while True:
        delta = f(h, g_target) / df(h)
        h -= delta
        if abs(delta) < epsilon:
            break

    return h

def main():
    g_target = float(input("Enter target free-fall acceleration g_target (m/s^2): "))

    initial_guess = 0  # Initial guess for h
    epsilon = 1e-6      # Precision

    h = newton_method(g_target, initial_guess, epsilon)
    print(f"Height h where free-fall acceleration equals {g_target} m/s^2: {h} m")

if __name__ == "__main__":
    main()