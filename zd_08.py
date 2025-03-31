import math

def calculate_S(V, t):
    S1 = V * t
    a = V / t
    S2 = a * t**2 / 2
    return S1 + S2

def newton_method(V, t, initial_guess, epsilon):
    S = initial_guess
    delta = 0

    while True:
        f = S - (3 * V * t / 2)  # Equation for Newton's method
        df = 1  # Derivative of function f with respect to S
        delta = f / df
        S -= delta
        if abs(delta) < epsilon:
            break

    return S

def main():
    V = float(input("Enter speed V: "))
    t = float(input("Enter time t: "))

    S_calculated = calculate_S(V, t)
    print(f"Path S calculated by formula: {S_calculated}")

    initial_guess = S_calculated  # Initial guess
    epsilon = 1e-6  # Precision

    S_newton = newton_method(V, t, initial_guess, epsilon)
    print(f"Path S calculated by Newton's method: {S_newton}")

if __name__ == "__main__":
    main()