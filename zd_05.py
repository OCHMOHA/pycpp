from math import *

g = 9.81

def y(T, U, H):
    return H - (g * T**2) / 2.0

def dy(T):
    return -g * T

def newton_method(U, H, T_initial, epsilon=1e-6, max_iter=100):
    T = T_initial
    for i in range(max_iter):
        y_val = y(T, U, H)
        dy_val = dy(T)
        
        if dy_val == 0:
            print("Derivative is zero.")
            return -1
            
        T_new = T - y_val / dy_val
        
        if abs(T_new - T) < epsilon:
            return T_new
            
        T = T_new

        
    print(f"Did not converge in {max_iter} iterations")
    return -1

H = 50
U = 400

T_initial = sqrt(2 * H / g)
epsilon = 1e-6


T = newton_method(U, H, T_initial, epsilon)

if T != -1:
    print(f"Bomb flight time T: {T} seconds")
    
    t = float(input("Enter time t (in seconds): "))
    x = U * t
    
    print(f"Horizontal distance x(t): {x} meters")
