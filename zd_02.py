import math

g = 9.81  # Acceleration due to gravity

def f(alpha, V, L):
    return (V**2 * math.sin(2 * alpha)) / g - L

def df(alpha, V):
    return (2 * V**2 * math.cos(2 * alpha)) / g

def newton_method(V, L, initial_guess, tol=1e-6, max_iter=100):
    alpha = initial_guess
    for _ in range(max_iter):
        f_val = f(alpha, V, L)
        df_val = df(alpha, V)
        
        if abs(df_val) < 1e-10:  # Avoid division by near-zero
            break
        
        delta = f_val / df_val
        alpha -= delta
        
        if abs(delta) < tol:
            break
    return alpha

if __name__ == "__main__":
    V = float(input("Enter initial velocity (V): "))
    L = float(input("Enter desired range (L): "))
    
    L_max = V**2 / g
    if L > L_max:
        print(f"Error: Desired range {L:.2f} m exceeds maximum possible range {L_max:.2f} m.")
    else:

        alpha_rad = newton_method(V, L, math.pi/4)
        alpha_deg = math.degrees(alpha_rad)
        

        if 0 <= alpha_deg <= 90:
            print(f"Required launch angle α: {alpha_deg:.2f}°")
        else:
            print("Newton's Method failed to converge. Try another method.")