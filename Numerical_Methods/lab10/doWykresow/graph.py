import math
from matplotlib import pyplot as plt
import numpy as np

with open('/home/stud2022/2fryska/METODY_NUMER/lab09/values.txt', 'r') as file:
    lines = file.readlines()
    x_values = [float(value) for value in lines[0].split()]
    y_values_orig = [float(value) for value in lines[1].split()]
    y_values_new = [float(value) for value in lines[2].split()]
    

plt.plot(x_values, y_values_orig, color='red', label='f(x)')

plt.plot(x_values, y_values_new, color='blue', label='aproksymacja')

plt.xlabel('x')
plt.ylabel('y')
plt.title('f(x) i jej aproksymacja, n = 50')
plt.legend()

plt.grid(True)
plt.savefig('plot1.png')