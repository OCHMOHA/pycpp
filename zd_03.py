from math import *

# Known values
H = 5.0   # Max height in meters
L = 20.0  # Horizontal range in meters
g = 9.81

# Function: f(x) = tan(a) - 4H / L
def exmp_function(x):
    return (4 * H / L)

# Iterative method to solve f(alpha) = 0
def iter_method(x_0, epsilon):
    x = x_0
    iter = 0
    while True:
        # Rearranged fixed-point form: alpha = arctan(4H / L)
        x_new = (4 * H / L)
        if abs(x_new - x) < epsilon:
            print(f"Number of iterations: {iter}")
            return x_new
        x = x_new
        iter += 1

# Initial guess and precision
x_0 = 0.5  # radians
epsilon = 1e-8

# Solving
x_root = iter_method(x_0, epsilon)
print(f"Solving the equation: x = {x_root} radians ({degrees(x_root)} degrees)")

# Now compute V using V = sqrt(gL / sin(2alpha))
V = sqrt(g * L / sin(2 * x_root))
print(f"Initial velocity V = {V:.4f} m/s")
