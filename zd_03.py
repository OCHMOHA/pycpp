import math

def calculate_launch_parameters(H, L):
    g = 9.81 
    

    def f(alpha):
        return (4 * H) / L - math.tan(alpha)
    
    def df(alpha):
        return -1 / (math.cos(alpha) ** 2) 
    
 
    def newton_method(initial_guess, tol=1e-6, max_iter=100):
        alpha = initial_guess
        for _ in range(max_iter):
            f_val = f(alpha)
            df_val = df(alpha)
            
            if abs(df_val) < 1e-10:  # Prevent division by zero
                break
                
            delta = f_val / df_val
            alpha -= delta
            
            if abs(delta) < tol:
                break
        return alpha
    

    initial_guess = math.atan(4 * H / L)
    
    # Solve for alpha
    alpha = newton_method(initial_guess)
    alpha_deg = math.degrees(alpha)
    

    V = math.sqrt((g * L) / math.sin(2 * alpha))
    
    return alpha, alpha_deg, V, g


H = float(input("Enter maximum height (H) in meters: "))
L = float(input("Enter range (L) in meters: "))


alpha_rad, alpha_deg, V, g = calculate_launch_parameters(H, L)


print(f"\nResults:")
print(f"Launch angle (α): {alpha_deg:.2f}°")
print(f"Initial velocity (V): {V:.2f} m/s")
print(f"Validation:")
print(f"- Calculated max height: {(V**2 * (math.sin(alpha_rad)**2)/(2*g)):.2f} m (should be {H} m)")
print(f"- Calculated range: {(V**2 * math.sin(2*alpha_rad)/g):.2f} m (should be {L} m)")