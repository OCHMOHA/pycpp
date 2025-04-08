import math

g = 9.81


V = float(input("Enter initial velocity (V): "))
T = float(input("Enter flight time (T): "))

alpha = math.pi / 4 
tolerance = 1e-6

while True:
    f = 2 * V * math.sin(alpha) - g * T
    df = 2 * V * math.cos(alpha)
    
    alpha -= f / df
    
    if abs(f) < tolerance:
        break

alpha_deg = alpha * 180 / math.pi

print(f"Launch angle (radians): {alpha:.6f}")
print(f"Launch angle (degrees): {alpha_deg:.6f}")
