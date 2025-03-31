import math

# Function to calculate initial phase phi0
def calculate_phi0(k):
    return math.asin(1 / k)

# Function to calculate time T
def calculate_T(omega, phi0):
    return (math.pi / 2 - phi0) / omega

# Function for iteration method
def iteration_method(omega, k, initial_guess, epsilon):
    T = initial_guess
    delta = 0

    while True:
        phi0 = calculate_phi0(k)
        new_T = calculate_T(omega, phi0)
        delta = new_T - T
        T = new_T
        if abs(delta) < epsilon:
            break

    return T

def main():
    omega = float(input("Enter frequency omega: "))
    k = float(input("Enter parameter k: "))

    initial_guess = 0  # Initial guess
    epsilon = 1e-6  # Precision

    T = iteration_method(omega, k, initial_guess, epsilon)
    print(f"Time moment T when pendulum deflection is maximum: {T}")

if __name__ == "__main__":
    main()