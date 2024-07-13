import numpy as np
import matplotlib.pyplot as plt
import math

N_values = [2, 3, 4, 5, 6, 7, 8, 9 , 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 ]
N3_values = [2, 3, 4, 5, 6, 7, 8, 9 , 10, 11, 12, 13, 14, 15 ]

with open('/home/dziad/projects/METODY_NUMERYCZNE/lab13/funOneDifferences.txt', 'r') as file:
    y_values_diff_1 = [float(value) for value in file.readline().split()]
    
with open('/home/dziad/projects/METODY_NUMERYCZNE/lab13/funTwoDifferencesK5.txt', 'r') as file:
    y_values_diff_2_5 = [float(value) for value in file.readline().split()]
    
with open('/home/dziad/projects/METODY_NUMERYCZNE/lab13/funTwoDifferencesK10.txt', 'r') as file:
    y_values_diff_2_10 = [float(value) for value in file.readline().split()]
    
with open('/home/dziad/projects/METODY_NUMERYCZNE/lab13/funThreeDifferences.txt', 'r') as file:
    y_values_diff_3 = [float(value) for value in file.readline().split()] 

x = np.linspace(-5, 5, 400 )

y1 = x / ( 4 * x**2 + 1 )
y2_5 = x**5 * np.exp(-x)
y2_10 = x**10 * np.exp(-x)
y3= np.linspace ( -5, 5, 400 )
X, Y = np.meshgrid(x, y3)
Z = np.sin(X)**2 * np.sin(Y)**4 * np.exp(-(X**2) - (Y**2) )

plt.plot(x, y1, color='red')
plt.xlabel('x')
plt.ylabel('f1(x)')
plt.title('Funkcja f1(x)')
plt.grid(True)
plt.savefig('plot_f1.png')
plt.close()

plt.plot(x, y2_5, color='green')
plt.xlabel('x')
plt.ylabel('f25(x)')
plt.title('Funkcja f2(x) dla k=5')
plt.grid(True)
plt.savefig('plot_f2_k5.png')
plt.close()

plt.plot(x, y2_10, color='blue')
plt.xlabel('x')
plt.ylabel('f210(x)')
plt.title('Funkcja f2(x) dla k=10')
plt.grid(True)
plt.savefig('plot_f2_k10.png')
plt.close()

plt.figure()
plt.contourf(X, Y, Z, 20, cmap='plasma')
plt.title('Funkcja f3(x,y)')
plt.xlabel('x')
plt.ylabel('y')
plt.colorbar(label='f(x,y)')
plt.savefig('plot_f3.png')
plt.close()

plt.plot(N_values, y_values_diff_1, color='red')
plt.xlabel('N')
plt.ylabel('|c1 - c1a|')
plt.title('|c1 - c1a| w funkcji F1(N)')
plt.grid(True)
plt.savefig('plot_diff_c1.png')
plt.close()

plt.plot(N_values, y_values_diff_2_5, color='green')
plt.xlabel('N')
plt.ylabel('|c2 - c2a|, k=5')
plt.title('|c2 - c2a| w funkcji F2(N) dla k = 5')
plt.grid(True)
plt.savefig('plot_diff_c2_5.png')
plt.close()

plt.plot(N_values, y_values_diff_2_10, color='blue')
plt.xlabel('N')
plt.ylabel('|c2 - c2a|, k=10')
plt.title('|c2 - c2a| w funkcji F2(N) dla k = 10')
plt.grid(True)
plt.savefig('plot_diff_c2_10.png')
plt.close()

plt.plot(N3_values, y_values_diff_3, color='magenta')
plt.xlabel('N')
plt.ylabel('|c3 - c3dok|')
plt.title('|c3 - c3dok| w funkcji F3(N)')
plt.grid(True)
plt.savefig('plot_diff_c3.png')
plt.close()