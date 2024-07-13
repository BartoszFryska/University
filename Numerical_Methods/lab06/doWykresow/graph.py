import matplotlib.pyplot as plt

with open ('/home/dziad/projects/METODY_NUMERYCZNE/lab06/doWykresow/function.txt', 'r' ) as file_one:
    x_values = [float(value) for value in file_one.readline().split()]
    y_values = [float(value) for value in file_one.readline().split()]

plt.plot (x_values, y_values)
plt.xlabel ( 'x' )
plt.ylabel ( 'f(x)' )
plt.title ( 'Wykres funckcji w przedziale <0.5, 2.4>' )
plt.grid( True )
plt.savefig ( 'Wynkres_fun.png')
plt.clf()

#############

with open ('/home/dziad/projects/METODY_NUMERYCZNE/lab06/doWykresow/wyniki10.txt', 'r' ) as file_two:
    y_values = [float(value) for value in file_two.readline().split()]

x_values = list(range(len(y_values)))

plt.plot (x_values, y_values)
plt.xlabel ( 'nr. IT' )
plt.ylabel ( 'xi' )
plt.title ( 'Kolejne przyblizenia wartości dla wartosci poczatkowej x01 = 0.5' )
plt.grid( True )
plt.savefig ( 'Wykres_przyblizenia_10.png')
plt.clf()

with open ('/home/dziad/projects/METODY_NUMERYCZNE/lab06/doWykresow/wyniki11.txt', 'r' ) as file_three:
    y_values = [float(value) for value in file_three.readline().split()]

x_values = list(range(len(y_values)))

plt.plot (x_values, y_values)
plt.xlabel ( 'nr. IT' )
plt.ylabel ( 'xi' )
plt.title ( 'Kolejne przyblizenia wartości dla wartosci poczatkowej x02 = 2.4' )
plt.grid( True )
plt.savefig ( 'Wykres_przyblizenia_11.png')
plt.clf()

#############

with open ('/home/dziad/projects/METODY_NUMERYCZNE/lab06/doWykresow/roznice10.txt', 'r' ) as file_four:
    y_values = [float(value) for value in file_four.readline().split()]

x_values = list(range(len(y_values)))

plt.plot (x_values, y_values)
plt.xlabel ( 'nr. IT' )
plt.ylabel ( 'epsilon' )
plt.title ( 'Roznice miedzy kolejnymi wartościami dla wartosci poczatkowej x01 = 0.5' )
plt.grid( True )
plt.savefig ( 'Wykres_roznice_10.png')
plt.clf()

with open ('/home/dziad/projects/METODY_NUMERYCZNE/lab06/doWykresow/roznice11.txt', 'r' ) as file_five:
    y_values = [float(value) for value in file_five.readline().split()]

x_values = list(range(len(y_values)))

plt.plot (x_values, y_values)
plt.xlabel ( 'nr. IT' )
plt.ylabel ( 'epsilon' )
plt.title ( 'Roznice miedzy kolejnymi wartościami dla wartosci poczatkowej x02 = 2.4' )
plt.grid( True )
plt.savefig ( 'Wykres_roznice_11.png')
plt.clf()

##################

with open ('/home/dziad/projects/METODY_NUMERYCZNE/lab06/doWykresow/wyniki20.txt', 'r' ) as file_six:
    y_values = [float(value) for value in file_six.readline().split()]

x_values = list(range(len(y_values)))

plt.plot (x_values, y_values)
plt.xlabel ( 'nr. IT' )
plt.ylabel ( 'xi' )
plt.title ( 'Kolejne przyblizenia wartości dla wartosci poczatkowej x01 = 0.5' )
plt.grid( True )
plt.savefig ( 'Wykres_przyblizenia_20.png')
plt.clf()

with open ('/home/dziad/projects/METODY_NUMERYCZNE/lab06/doWykresow/wyniki21.txt', 'r' ) as file_seven:
    y_values = [float(value) for value in file_seven.readline().split()]

x_values = list(range(len(y_values)))

plt.plot (x_values, y_values)
plt.xlabel ( 'nr. IT' )
plt.ylabel ( 'xi' )
plt.title ( 'Kolejne przyblizenia wartości dla wartosci poczatkowej x02 = 2.4' )
plt.grid( True )
plt.savefig ( 'Wykres_przyblizenia_21.png')
plt.clf()

#############

with open ('/home/dziad/projects/METODY_NUMERYCZNE/lab06/doWykresow/roznice20.txt', 'r' ) as file_eight:
    y_values = [float(value) for value in file_eight.readline().split()]

x_values = list(range(len(y_values)))

plt.plot (x_values, y_values)
plt.xlabel ( 'nr. IT' )
plt.ylabel ( 'epsilon' )
plt.title ( 'Roznice miedzy kolejnymi wartościami dla wartosci poczatkowej x01 = 0.5' )
plt.grid( True )
plt.savefig ( 'Wykres_roznice_20.png')
plt.clf()

with open ('/home/dziad/projects/METODY_NUMERYCZNE/lab06/doWykresow/roznice21.txt', 'r' ) as file_nine:
    y_values = [float(value) for value in file_nine.readline().split()]

x_values = list(range(len(y_values)))

plt.plot (x_values, y_values)
plt.xlabel ( 'nr. IT' )
plt.ylabel ( 'epsilon' )
plt.title ( 'Roznice miedzy kolejnymi wartościami dla wartosci poczatkowej x02 = 2.4' )
plt.grid( True )
plt.savefig ( 'Wykres_roznice_21.png')
plt.clf()