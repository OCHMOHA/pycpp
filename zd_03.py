from math import *

# Known values
H = 5.0   # Max height in meters
L = 20.0  # Horizontal range in meters
g = 9.81  # Gravitational acceleration

# Function: f(alpha) = tan(alpha) - 4H / L
def exmp_function(alpha):
    return tan(alpha) - (4 * H / L)

# Iterative method to solve f(alpha) = 0
def iter_method(alpha_0, epsilon):
    alpha = alpha_0
    iter = 0
    while True:
        # Rearranged fixed-point form: alpha = arctan(4H / L)
        alpha_new = atan(4 * H / L)
        if abs(alpha_new - alpha) < epsilon:
            print(f"Number of iterations: {iter}")
            return alpha_new
        alpha = alpha_new
        iter += 1

# Initial guess and precision
alpha_0 = 0.5  # radians
epsilon = 1e-8

# Solving
alpha_root = iter_method(alpha_0, epsilon)
print(f"Solving the equation: alpha = {alpha_root} radians ({degrees(alpha_root)} degrees)")

# Now compute V using V = sqrt(gL / sin(2alpha))
V = sqrt(g * L / sin(2 * alpha_root))
print(f"Initial velocity V = {V:.4f} m/s")