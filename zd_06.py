from math import *

def calculate_time(S, V, U):
    return S/(V + U) + S/(V - U)

def newton_solver(S, V, U, T_guess, epsilon=1e-6, max_iter=100):
    T = T_guess
    for i in range(max_iter):
        f = calculate_time(S, V, U) - T
        df = -1
        
        if df == 0:
            print("derivative is zero.")
            return -1
            
        T_new = T - f/df
        
        if  abs(T_new - T) < epsilon:
            return T_new
            
        T = T_new
    
    print(f"Did not converge in {max_iter} iterations")
    return -1

S = float(input("Distance between points S (m): "))
V = float(input("Boat speed V (m/s): "))
U = float(input("River current speed U (m/s): "))

if V <= U:
    print("Boat speed must exceed current speed")
else:
    T_initial = S/V  
    epsilon = 1e-6

    T = newton_solver(S, V, U, T_initial, epsilon)
    
    if T != -1:
        print(f"Total travel time: {T:.6f} seconds")
