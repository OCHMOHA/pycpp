def calculate_v2(V, S, t, V1):
    """Calculate V2 using the given formula"""
    return S / (2 * S / V - t)

def bisection_method(V, S, t, a, b, epsilon):
    """Find V2 using the bisection method within given bounds [a, b]"""
    V1 = S / t  # Calculate V1
    V2_a = calculate_v2(V, S, t, a)
    V2_b = calculate_v2(V, S, t, b)

    while abs(V2_a - V2_b) > epsilon:
        mid = (a + b) / 2
        V2_mid = calculate_v2(V, S, t, mid)

        if V2_mid * V2_a < 0:
            b = mid
            V2_b = V2_mid
        else:
            a = mid
            V2_a = V2_mid

    return (a + b) / 2

def main():
    # User input
    V = float(input("Enter average speed V: "))
    S = float(input("Enter distance S: "))
    t = float(input("Enter time t: "))

    # Calculate V1
    V1 = S / t
    print(f"Speed V1: {V1}")

    # Bisection method parameters
    a = 0  # Initial lower bound for V2
    b = 2 * V  # Initial upper bound for V2
    epsilon = 1e-6  # Precision

    # Find V2 using bisection method
    V2 = bisection_method(V, S, t, a, b, epsilon)
    print(f"Speed V2: {V2}")

if __name__ == "__main__":
    main()