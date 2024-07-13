import numpy as np
import matplotlib.pyplot as plt


# Define the range and resolution
x_min, x_max = -1.5, 1.5
y_min, y_max = -1, 2
resolution = 100

# Create a grid of points
x = np.linspace(x_min, x_max, resolution)
y = np.linspace(y_min, y_max, resolution)
X, Y = np.meshgrid(x, y)

# Define the function
def f(x, y):
    return 5./2 * (x ** 2 - y) ** 2 +( 1 - x ) ** 2

x_values_e2 = []
y_values_e2 = []

with open('/home/dziad/projects/METODY_NUMERYCZNE/lab10/iter0.010000.dat', 'r') as file:
    for line in file:
        x, y = map(float, line.strip().split())
        x_values_e2.append(x)
        y_values_e2.append(y)
        
# Compute the function values
Z = f(X, Y)

# Generate the heat map
plt.contourf(X, Y, Z, cmap='viridis')
plt.colorbar(label='f(r)')
plt.xlabel('x')
plt.ylabel('y')
plt.title('Kolejne iteracje minimum f(r), epsilon = 1.0e-2')
plt.scatter (x_values_e2, y_values_e2, color='red', marker='+' )
plt.plot (x_values_e2, y_values_e2, color='red' )
plt.scatter(1.0, 1.0, color='white', marker='*')
plt.savefig('plot1.png')
plt.clf()

x_values_e3 = []
y_values_e3 = []

with open('/home/dziad/projects/METODY_NUMERYCZNE/lab10/iter0.001000.dat', 'r') as file:
    for line in file:
        x, y = map(float, line.strip().split())
        x_values_e3.append(x)
        y_values_e3.append(y)
        

plt.contourf(X, Y, Z, cmap='inferno')
plt.colorbar(label='f(r)')
plt.xlabel('x')
plt.ylabel('y')
plt.title('Kolejne iteracje minimum f(r), epsilon = 1.0e-3')
plt.scatter (x_values_e3, y_values_e3, color='red', marker='+' )
plt.plot (x_values_e3, y_values_e3, color='red')
plt.scatter(1.0, 1.0, color='white', marker='*')
plt.savefig('plot2.png')