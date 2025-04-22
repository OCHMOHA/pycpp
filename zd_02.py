import math

g = 9.81

V = float(input("Enter initial velocity (m/s): "))
L = float(input("Enter target distance (m): "))

max_L = V**2 / g
if L > max_L:
    print(f"Impossible! Maximum distance is {max_L:.2f} m")
else:

    if L < max_L/2:
        alpha = math.radians(30)
    else:
        alpha = math.radians(60)
    
    converged = False
    for _ in range(100):
        current = (V**2 * math.sin(2*alpha))/g - L
        slope = (2 * V**2 * math.cos(2*alpha))/g
        
        if abs(slope) < 1e-10:
            alpha += 0.1
            continue
            
        alpha -= current/slope
        
        if abs(current) < 1e-6:
            converged = True
            break
    
    angle_deg = math.degrees(alpha)
    
    if converged and 0 <= angle_deg <= 90:
        print(f"Launch angle needed: {angle_deg:.2f}°")
    else:
        print("No valid solution found (numerical error)")