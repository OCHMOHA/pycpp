from math import sin, sqrt, radians

# Given values
H = 10.0    # height in meters
V = 20.0    # initial velocity in m/s
alpha_deg = 45.0  # angle in degrees
g = 9.81

# Convert angle to radians
alpha = radians(alpha_deg)

# Define the function f(T) based on the equation:
# T = (V * sin(alpha) / g) * (1 + sqrt(1 + (2 * g * H) / (V^2 * sin^2(alpha))))
def f(T):
    return T - (V * sin(alpha) / g) * (1 + sqrt(1 + (2 * g * H) / (V**2 * sin(alpha)**2)))

# Derivative of f(T) with respect to T (approximated numerically)
def df(T, delta=1e-6):
    return (f(T + delta) - f(T - delta)) / (2 * delta)

# Newton-Raphson method
def newton_method(x0, epsilon):
    x = x0
    iter_count = 0
    while True:
        fx = f(x)
        dfx = df(x)
        if dfx == 0:
            raise ValueError("Zero derivative encountered.")
        x_new = x - fx / dfx
        if abs(x_new - x) < epsilon:
            print(f"Number of iterations: {iter_count}")
            return x_new
        x = x_new
        iter_count += 1

# Initial guess and precision
x0 = 2.0
epsilon = 1e-8

# Solve for T
T_result = newton_method(x0, epsilon)
T_result