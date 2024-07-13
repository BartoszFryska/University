import numpy as np
import matplotlib.pyplot as plt

num_elements = 2**12
x_values = np.linspace(0, 3, num_elements)

y_values1 = []
with open('/home/dziad/projects/METODY_NUMERYCZNE/lab11/fone_val.txt', 'r') as file:
    line = file.readline()
    y_values1 = [float(value) for value in line.split()]
    
y_values2 = []
with open('/home/dziad/projects/METODY_NUMERYCZNE/lab11/foneVar_val.txt', 'r') as file:
    line = file.readline()
    y_values2 = [float(value) for value in line.split()]
    
y_values3 = []
with open('/home/dziad/projects/METODY_NUMERYCZNE/lab11/foneVarFourr_val.txt', 'r') as file:
    line = file.readline()
    y_values3 = [float(value) for value in line.split()]
    
#plt.figure(figsize=(10, 6))
plt.plot(x_values, y_values2, label='f(t)', color='magenta', linestyle='-',markersize = 3)

plt.plot(x_values, y_values1, label='f0(t)', color='blue', linestyle='-', markersize = 3)

plt.plot(x_values, y_values3, label='fk(t)', color='red', linestyle='-', markersize = 3)

plt.xlabel('X')
plt.ylabel('Y')
plt.title('Sygnały dla k = 12')
plt.legend()

plt.savefig('plot3.png')
    