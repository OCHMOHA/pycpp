from math import asin, degrees

def calculate_launch_angle(V, T):

    g = 9.81  
    a = asin((g * T) / (2 * V))
    return degrees(a)

V = float(input("Enter initial velocity V (m/s): "))
T = float(input("Enter flight time T (s): "))

alpha = calculate_launch_angle(V, T)
print(f"Launch angle α = {alpha:.2f}°")
