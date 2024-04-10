import matplotlib.pyplot as plt

with open ('/home/dziad/projects/METODY_NUMERYCZNE/lab03/doWykresow/wyk_xk_iteracje11_FirstValueE-6.txt', 'r' ) as file_one:
    y_values = [float(value) for value in file_one.readline().split()]

x_values = list(range(len(y_values)))

plt.plot (x_values, y_values)
plt.xlabel ( 'k' )
plt.ylabel ( 'xk' )
plt.title ( 'Wykres xk od k dla pierwszego zadania' )
plt.grid( True )
plt.savefig ( 'Wykres_xk_pierwsze.png')
plt.clf()

with open ('/home/dziad/projects/METODY_NUMERYCZNE/lab03/doWykresow/wyk_xk_iteracje_2ndTask.txt', 'r' ) as file_two:
    y1_values = [float(value) for value in file_two.readline().split()]

x_values = list(range(len(y1_values)))

plt.plot (x_values, y1_values)
plt.xlabel ( 'k' )
plt.ylabel ( 'xk' )
plt.title ( 'Wykres xk od k dla drugiego zadania' )
plt.grid( True )
plt.savefig ( 'Wykres_xk_drugie.png')
plt.clf()

with open ('/home/dziad/projects/METODY_NUMERYCZNE/lab03/doWykresow/wyk_rk_iteracje11_FirstValueE-6.txt', 'r' ) as file_three:
    y2_values = [float(value) for value in file_three.readline().split()]

x_values = list(range(len(y2_values)))

plt.plot (x_values, y2_values)
plt.xlabel ( 'k' )
plt.ylabel ( 'rk' )
plt.title ( 'Wykres rk od k dla pierwszego zadania' )
plt.grid( True )
plt.yscale('log')
plt.savefig ( 'Wykres_rk_pierwsze.png')
plt.clf()

with open ('/home/dziad/projects/METODY_NUMERYCZNE/lab03/doWykresow/wyk_rk_iteracje_2ndTask.txt', 'r' ) as file_four:
    y3_values = [float(value) for value in file_four.readline().split()]

x_values = list(range(len(y3_values)))

plt.plot (x_values, y3_values)
plt.xlabel ( 'k' )
plt.ylabel ( 'rk' )
plt.title ( 'Wykres rk od k dla drugiego zadania' )
plt.grid( True )
plt.yscale('log')
plt.savefig ( 'Wykres_rk_drugie.png')
plt.clf()
