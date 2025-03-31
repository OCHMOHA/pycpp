import math

g = 9.81

def f(alpha, V, T):
    return 2 * V * math.sin(alpha) - g * T

def df(alpha, V):  # Derivative of f(α)
    return 2 * V * math.cos(alpha)

def newton_method(V, T, initial_guess, tol=1e-6):
    alpha = initial_guess
    h = f(alpha, V, T) / df(alpha, V)
    
    while abs(h) >= tol:
        alpha -= h
        h = f(alpha, V, T) / df(alpha, V)
    return alpha

if __name__ == "__main__":
    V = float(input("Enter initial velocity (V): "))
    T = float(input("Enter flight time (T): "))


    alpha_rad = newton_method(V, T, math.pi/4)
    alpha_deg = math.degrees(alpha_rad)

    print(f"Angle α (in radians): {alpha_rad:.6f}")
    print(f"Angle α (in degrees): {alpha_deg:.6f}")