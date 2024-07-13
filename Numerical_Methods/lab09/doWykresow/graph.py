import math
from matplotlib import pyplot as plt
import numpy as np

with open('/home/dziad/projects/METODY_NUMERYCZNE/lab09/values1.txt', 'r') as file:
    lines = file.readlines()
    x_values = [float(value) for value in lines[0].split()]
    y_values_orig = [float(value) for value in lines[1].split()]
    y_values_new = [float(value) for value in lines[2].split()]
    

plt.plot(x_values, y_values_orig, color='red', label='f(x)')

plt.plot(x_values, y_values_new, color='blue', label='aproksymacja')

plt.xlabel('x')
plt.ylabel('y')
plt.title('f1(x) i jej aproksymacja, n = 100')
plt.legend()

plt.grid(True)
plt.savefig('plot1.png')

x_values.clear()
y_values_orig.clear()
y_values_new.clear()
lines.clear()
plt.close()

with open('/home/dziad/projects/METODY_NUMERYCZNE/lab09/values2.txt', 'r') as file:
    lines = file.readlines()
    x_values = [float(value) for value in lines[0].split()]
    y_values_orig = [float(value) for value in lines[1].split()]
    y_values_new = [float(value) for value in lines[2].split()]

plt.plot(x_values, y_values_orig, color='red', label='f2(x)')

plt.plot(x_values, y_values_new, color='blue', label='aproksymacja')

plt.xlabel('x')
plt.ylabel('y')
plt.title('f2(x) i jej aproksymacja, n = 100')
plt.legend()

plt.grid(True)
plt.savefig('plot2.png')

x_values.clear()
y_values_orig.clear()
y_values_new.clear()
lines.clear()
plt.close()

with open('/home/dziad/projects/METODY_NUMERYCZNE/lab09/values3_5_0.txt', 'r') as file:
    lines = file.readlines()
    x_values = [float(value) for value in lines[0].split()]
    y_values_orig = [float(value) for value in lines[1].split()]
    y_values_new = [float(value) for value in lines[2].split()]

plt.plot(x_values, y_values_orig, color='red', label='f3(x)')

plt.plot(x_values, y_values_new, color='blue', label='aproksymacja dla Ms=5, Mc=0')

plt.xlabel('x')
plt.ylabel('y')
plt.title('f3(x) i jej aproksymacja, Ms=5, Mc=0, n = 100')
plt.legend()

plt.grid(True)
plt.savefig('plot3_5_0.png')

x_values.clear()
y_values_orig.clear()
y_values_new.clear()
lines.clear()
plt.close()

with open('/home/dziad/projects/METODY_NUMERYCZNE/lab09/values3_5_5.txt', 'r') as file:
    lines = file.readlines()
    x_values = [float(value) for value in lines[0].split()]
    y_values_orig = [float(value) for value in lines[1].split()]
    y_values_new = [float(value) for value in lines[2].split()]

plt.plot(x_values, y_values_orig, color='red', label='f3(x)')

plt.plot(x_values, y_values_new, color='blue', label='aproksymacja dla Ms=5, Mc=5')

plt.xlabel('x')
plt.ylabel('y')
plt.title('f3(x) i jej aproksymacja, Ms=5, Mc=5, n = 100')
plt.legend()

plt.grid(True)
plt.savefig('plot3_5_5.png')

x_values.clear()
y_values_orig.clear()
y_values_new.clear()
lines.clear()
plt.close()

with open('/home/dziad/projects/METODY_NUMERYCZNE/lab09/values3_10_10.txt', 'r') as file:
    lines = file.readlines()
    x_values = [float(value) for value in lines[0].split()]
    y_values_orig = [float(value) for value in lines[1].split()]
    y_values_new = [float(value) for value in lines[2].split()]

plt.plot(x_values, y_values_orig, color='red', label='f3(x)')

plt.plot(x_values, y_values_new, color='blue', label='aproksymacja dla Ms=10, Mc=10')

plt.xlabel('x')
plt.ylabel('y')
plt.title('f3(x) i jej aproksymacja, Ms=10, Mc=10, n = 100')
plt.legend()

plt.grid(True)
plt.savefig('plot3_10_10.png')

x_values.clear()
y_values_orig.clear()
y_values_new.clear()
lines.clear()
plt.close()

with open('/home/dziad/projects/METODY_NUMERYCZNE/lab09/values4_5_5.txt', 'r') as file:
    lines = file.readlines()
    x_values = [float(value) for value in lines[0].split()]
    y_values_orig = [float(value) for value in lines[1].split()]
    y_values_new = [float(value) for value in lines[2].split()]

plt.plot(x_values, y_values_orig, color='red', label='f(x) z alpha wyliczoną losowo')

plt.plot(x_values, y_values_new, color='blue', label='aproksymacja dla Ms=5, Mc=5')

plt.xlabel('x')
plt.ylabel('y')
plt.title('f(x) z przesunięciem losowym i jej aproksymacja, Ms=5, Mc=5, n = 100')
plt.legend()

plt.grid(True)
plt.savefig('plot4_5_5.png')

x_values.clear()
y_values_orig.clear()
y_values_new.clear()
lines.clear()
plt.close()

with open('/home/dziad/projects/METODY_NUMERYCZNE/lab09/values4_30_30.txt', 'r') as file:
    lines = file.readlines()
    x_values = [float(value) for value in lines[0].split()]
    y_values_orig = [float(value) for value in lines[1].split()]
    y_values_new = [float(value) for value in lines[2].split()]

plt.plot(x_values, y_values_orig, color='red', label='f(x) z alpha wyliczoną losowo')

plt.plot(x_values, y_values_new, color='blue', label='aproksymacja dla Ms=30, Mc=30')

plt.xlabel('x')
plt.ylabel('y')
plt.title('f(x) z przesunięciem losowym i jej aproksymacja, Ms=30, Mc=30, n = 100')
plt.legend()

plt.grid(True)
plt.savefig('plot4_30_30.png')

x_values.clear()
y_values_orig.clear()
y_values_new.clear()
lines.clear()
plt.close()

with open('/home/dziad/projects/METODY_NUMERYCZNE/lab09/ai5.txt', 'r') as file:
    lines = file.readlines()
    y_values_ai = [float(value) for value in lines[0].split()]
lines.clear()
with open('/home/dziad/projects/METODY_NUMERYCZNE/lab09/bj5.txt', 'r') as file:
    lines = file.readlines()
    y_values_bj = [float(value) for value in lines[0].split()]
    
x_values = list(range(len(y_values_ai)))

plt.plot(x_values, y_values_ai, color='red', label='ai')

plt.plot(x_values, y_values_bj, color='blue', label='bj')

plt.xlabel('x')
plt.ylabel('y')
plt.title('ai oraz bj dla f(x) z przesunięciem losowym, Ms=5, Mc=5, n = 100')
plt.legend()

plt.grid(True)
plt.savefig('barplot4_5_5.png')

x_values.clear()
y_values_ai.clear()
y_values_bj.clear()
lines.clear()
plt.close()

with open('/home/dziad/projects/METODY_NUMERYCZNE/lab09/ai30.txt', 'r') as file:
    lines = file.readlines()
    y_values_ai = [float(value) for value in lines[0].split()]
lines.clear()
with open('/home/dziad/projects/METODY_NUMERYCZNE/lab09/bj30.txt', 'r') as file:
    lines = file.readlines()
    y_values_bj = [float(value) for value in lines[0].split()]
    
x_values = list(range(len(y_values_ai)))

plt.plot(x_values, y_values_ai, color='red', label='ai')

plt.plot(x_values, y_values_bj, color='blue', label='bj')

plt.xlabel('x')
plt.ylabel('y')
plt.title('ai oraz bj dla f(x) z przesunięciem losowym, Ms=30, Mc=30, n = 100')
plt.legend()

plt.grid(True)
plt.savefig('barplot4_30_30.png')