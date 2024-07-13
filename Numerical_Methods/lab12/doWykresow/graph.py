import numpy as np
import matplotlib.pyplot as plt
import math

x_values = [11, 21, 51, 101, 201]

with open('/home/dziad/projects/METODY_NUMERYCZNE/lab12/Simp_0_1.txt', 'r') as file:
    y_values_0_1 = [float(value) for value in file.readline().split()]
    
with open('/home/dziad/projects/METODY_NUMERYCZNE/lab12/Simp_1_1.txt', 'r') as file:
    y_values_1_1 = [float(value) for value in file.readline().split()]
    
with open('/home/dziad/projects/METODY_NUMERYCZNE/lab12/Simp_5_5.txt', 'r') as file:
    y_values_5_5 = [float(value) for value in file.readline().split()] 


plt.plot(x_values, y_values_0_1, color='red', marker = "+", markersize = 6)
plt.xlabel('N')
plt.ylabel('Błąd wyznaczenia numerycznego |I - C|')
plt.title('Błąd wyznaczania całki metodą Simpsona dla m = 0, k = 1')
plt.grid(True)
plt.savefig('plot1.png')
plt.close()

plt.plot(x_values, y_values_1_1, color='green', marker = "+", markersize = 6)
plt.xlabel('N')
plt.ylabel('Błąd wyznaczenia numerycznego |I - C|')
plt.title('Błąd wyznaczania całki metodą Simpsona dla m = 1, k = 1')
plt.grid(True)
plt.savefig('plot2.png')
plt.close()

plt.plot(x_values, y_values_5_5, color='blue', marker = "+", markersize = 6 )
plt.xlabel('N')
plt.ylabel('Błąd wyznaczenia numerycznego |C - I|')
plt.title('Błąd wyznaczania całki metodą Simpsona dla m = 5, k = 5')
plt.grid(True)
plt.savefig('plot3.png')
    