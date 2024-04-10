import numpy as np
import matplotlib.pyplot as plt

with open('/home/dziad/projects/METODY_NUMERYCZNE/lab04/doWykresow/equation.txt', 'r') as file:
    eigenvectors = []
    for line in file:
        eigenvector = [float(value) for value in line.split()]
        eigenvectors.append(eigenvector)

x_values = np.linspace(-5, 5, num=len(eigenvectors[0]))

for i, eigenvector in enumerate(eigenvectors):
    plt.plot(x_values, eigenvector, label=f'wektor {i+1}')

plt.xlabel('x')
plt.title('wektory własne dla oscylatora harmonicznego')
plt.legend()
plt.grid(True)
plt.savefig('plot.png')