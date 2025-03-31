import math

g = 9.81 

def calculate_time(H):
    """Calculate free-fall time from height H"""
    return math.sqrt(2 * H / g)

def calculate_distance(U, T):
    """Calculate horizontal distance traveled at speed U over time T"""
    return U * T

def secant_method(f, x0, x1, epsilon=1e-6, max_iterations=100):
    """Secant method for finding roots of function f"""
    for i in range(max_iterations):
        if f(x1) - f(x0) == 0:
            print("Secant method failed: f(x1) - f(x0) = 0.")
            return -1
        x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0))
        if abs(x2 - x1) < epsilon:
            return x2
        x0 = x1
        x1 = x2
    print(f"Secant method did not converge after {max_iterations} iterations.")
    return -1


def main():

    H = float(input("Enter aircraft altitude H (in meters): "))
    U = float(input("Enter aircraft speed U (in m/s): "))


    T = calculate_time(H)


    S = calculate_distance(U, T)


    print(f"Bomb flight time T: {T} seconds")
    print(f"Horizontal distance S: {S} meters")


if __name__ == "__main__":
    main()