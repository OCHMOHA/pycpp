from math import * 

g = 9.81 
V = 20
a = 45
H = 10

def y(T, V, a, H):
    return H + V * T * sin(a) - (g * T**2) / 2.0

def dy(T, V, a):
    return V * sin(a) - g * T

def newton_method(V, a, H, initial_guess, tolerance=1e-6, max_iterations=100):
    T = initial_guess 
    for i in range(max_iterations):
        y_val = y(T, V, a, H)  
        dy_val = dy(T, V, a) 

        if dy_val == 0:
            print("derivative is zero")
            return -1

        T_new = T - y_val / dy_val

        if abs(T_new - T) < tolerance:
            return T_new

        T = T_new  

    print(f"did not converge in {max_iterations} iterations.")
    return -1

a_rad = radians(a)

initial_guess = (V * sin(a_rad)) / g

T = newton_method(V, a_rad, H, initial_guess)

if T != -1:
    print(f"Flight time T: {T} seconds")

    t = float(input("Enter time t (in seconds): "))
    x = V * t * cos(a_rad)
    y_val = max(H + V * t * sin(a_rad) - (g * t**2)/2.0, 0)

    print(f"Horizontal distance x(t): {x} meters")
    print(f"Height from the bottom of the cliff y(t): {y_val} meters")
