import math
from matplotlib import pyplot as plt
import numpy as np

with open('/home/dziad/projects/METODY_NUMERYCZNE/lab08/doWykresow/s_values.txt', 'r') as file:
    lines = file.readlines()
    y_values = [float(value) for value in lines[0].split()]
    
with open('/home/dziad/projects/METODY_NUMERYCZNE/lab08/doWykresow/x_values.txt', 'r') as file2:
    lines2 = file2.readlines()
    x_values = [float(value) for value in lines2[0].split()]

def my_function(x):
    return 1/(1 + x**2)

x_f = np.linspace(-5, 5, 150)
y_f = np.cos(2*x_f)
plt.plot(x_f, y_f, color='red', label='f(x)')

plt.plot(x_f, y_values, color='blue', label='W_n(x)')

plt.xlabel('x')
plt.ylabel('y')
plt.title('f(x) i W_n(x) dla funkcji drugiej, n = 21')
plt.legend()

plt.grid(True)
plt.savefig('plot1.png')