import numpy as np
import matplotlib.pyplot as plt

# Define parameters
V_peak = 220 * np.sqrt(2)  # Peak voltage
f = 50  # Frequency (Hz)
T = 1 / f  # Period (s)
delta_t = 2e-3  # Time step (2 ms)
num_steps = int(T / delta_t)  # Number of steps in one period

# Create time array from 0 to T with step delta_t
t_values = np.linspace(0, T, num_steps, endpoint=False)

# Calculate voltage values at each time point
V_values = V_peak * np.sin(2 * np.pi * f * t_values)

# Calculate Riemann sum of V(t)^2
riemann_sum = np.sum(V_values**2 * delta_t)

# Calculate RMS from the Riemann sum
V_rms = np.sqrt(riemann_sum / T)

# Plotting the waveform
plt.figure(figsize=(10, 6))
plt.plot(t_values, V_values, label="Voltage (V)")
plt.axhline(y=V_rms, color='r', linestyle='--', label=f"RMS Voltage: {V_rms:.2f} V")

# Adding labels and title
plt.xlabel("Time (s)")
plt.ylabel("Voltage (V)")
plt.title("Voltage Waveform and RMS Value")
plt.legend()
plt.grid(True)

# Display the plot
plt.show()

# Print RMS value
print("RMS Voltage:", V_rms)
