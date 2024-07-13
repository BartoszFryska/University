import math
from matplotlib import pyplot as plt
import numpy as np

with open('/home/dziad/projects/METODY_NUMERYCZNE/lab08/doWykresow/m_values.txt', 'r') as file:
    lines = file.readlines()
    y_values = [float(value) for value in lines[0].split()]

with open('/home/dziad/projects/METODY_NUMERYCZNE/lab08/doWykresow/x_der_values.txt', 'r') as file1:
    lines1 = file1.readlines()
    x_values = [float(value) for value in lines1[0].split()]
    
with open('/home/dziad/projects/METODY_NUMERYCZNE/lab08/doWykresow/y_der_values.txt', 'r') as file2:
    lines2 = file2.readlines()
    y_values_1 = [float(value) for value in lines2[0].split()]
    

x_f = np.linspace(-5, 5, 150)
y_f = ( 8 * x_f * x_f ) / ( ( 1 + x_f * x_f )**3 ) - 2 / ( ( 1 + x_f * x_f )**2 )
plt.plot(x_f, y_f, color='blue', label='funkcja')

plt.plot(x_values, y_values, color='red', label='m')
plt.plot(x_values, y_values_1, color='orange', label='wartości wyliczone za pomoca wzoru')

plt.xlabel('x')
plt.ylabel('y')
plt.title('druga pochodna f(x) w dwóch wersjach')
plt.legend()

#plt.plot(x_values, y_values, 'go', markersize=5)
#plt.plot(x_values, y_values_1, 'or', markersize=5)

plt.grid(True)
plt.savefig('pochodna.png')