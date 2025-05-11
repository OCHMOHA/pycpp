from math import *

def calculate_phi0(k):
    return asin(1 / k)

def calculate_T(omega, phi0):
    return (pi / 2 - phi0) / omega

def iteration_method(T_initial, epsilon, omega, k):
    T = T_initial
    iter = 0
    while True:
        phi0 = calculate_phi0(k)
        T_new = calculate_T(omega, phi0)
        if abs(T_new - T) < epsilon:
            print(f"Number of iterations: {iter}")
            return T_new
        T = T_new
        iter += 1

omega = 10
k = 5

T_initial = 0
epsilon = 1e-6
T = iteration_method(T_initial, epsilon, omega, k)
print(f"Time moment when pendulum deflection is maximum: {T}")
