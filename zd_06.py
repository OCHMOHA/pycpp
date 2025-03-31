def calculate_time(S, V, U):
    """
    Function to calculate the total travel time of the boat.
    """
    t1 = S / (V + U)  # Time downstream (with current)
    t2 = S / (V - U)  # Time upstream (against current)
    return t1 + t2  # Total time

def newton_method(S, V, U, initial_guess, tolerance=1e-6, max_iterations=100):
    """
    Newton's method for finding the root of the equation f(T) = calculate_time(S, V, U) - T.
    """
    T = initial_guess
    for i in range(max_iterations):
        f = calculate_time(S, V, U) - T  # Function f(T)
        df = -1  # Derivative of function f(T)

        if df == 0:
            print("Derivative is zero. Newton's method cannot be applied.")
            return -1

        T_new = T - f / df  # New approximation

        if abs(T_new - T) < tolerance:  # Convergence check
            return T_new

        T = T_new  # Update T value

    print(f"Newton's method did not converge in {max_iterations} iterations.")
    return -1

def main():
    # User input
    S = float(input("Enter distance between points S (in meters): "))
    V = float(input("Enter boat speed V (in m/s): "))
    U = float(input("Enter river current speed U (in m/s): "))

    # Validate input
    if V <= U:
        print("Boat speed must be greater than river current speed.")
        return

    # Initial guess for travel time
    initial_guess = S / V

    # Calculate total travel time using Newton's method
    T = newton_method(S, V, U, initial_guess)

    if T != -1:
        print(f"Total boat travel time T: {T} seconds")

if __name__ == "__main__":
    main()