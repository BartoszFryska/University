import matplotlib.pyplot as plt

with open ('/home/dziad/projects/METODY_NUMERYCZNE/lab07/doWykresow/y_values.txt', 'r' ) as file_one:
    y_values = [float(value) for value in file_one.readline().split()]
    
with open ('/home/dziad/projects/METODY_NUMERYCZNE/lab07/doWykresow/x_values.txt', 'r' ) as file_two:
    x_values = [float(value) for value in file_two.readline().split()]

with open ('/home/dziad/projects/METODY_NUMERYCZNE/lab07/doWykresow/y5_values.txt', 'r' ) as file_three:
    y1_values = [float(value) for value in file_three.readline().split()]
    
plt.plot (x_values, y_values, label='f(x)')
plt.plot (x_values, y1_values, label='wielomian')
plt.xlabel ( 'x' )
plt.ylabel ( 'y' )
plt.title ( 'Wykres f(x) oraz wielomianu interpolacyjnego dla n=5' )
plt.grid( True )
plt.legend( )
plt.savefig ( 'Wykres_fx_n5.png')
plt.clf()

with open ('/home/dziad/projects/METODY_NUMERYCZNE/lab07/doWykresow/y10_values.txt', 'r' ) as file_four:
    y2_values = [float(value) for value in file_four.readline().split()]
    
plt.plot (x_values, y_values, label='f(x)')
plt.plot (x_values, y2_values, label='wielomian')
plt.xlabel ( 'x' )
plt.ylabel ( 'y' )
plt.title ( 'Wykres f(x) oraz wielomianu interpolacyjnego dla n=10' )
plt.grid( True )
plt.legend( )
plt.savefig ( 'Wykres_fx_n10.png')
plt.clf()

with open ('/home/dziad/projects/METODY_NUMERYCZNE/lab07/doWykresow/y15_values.txt', 'r' ) as file_five:
    y3_values = [float(value) for value in file_five.readline().split()]
    
plt.plot (x_values, y_values, label='f(x)')
plt.plot (x_values, y3_values, label='wielomian')
plt.xlabel ( 'x' )
plt.ylabel ( 'y' )
plt.title ( 'Wykres f(x) oraz wielomianu interpolacyjnego dla n=15' )
plt.grid( True )
plt.legend( )
plt.savefig ( 'Wykres_fx_n15.png')
plt.clf()

with open ('/home/dziad/projects/METODY_NUMERYCZNE/lab07/doWykresow/y20_values.txt', 'r' ) as file_six:
    y4_values = [float(value) for value in file_six.readline().split()]
    
plt.plot (x_values, y_values, label='f(x)')
plt.plot (x_values, y4_values, label='wielomian')
plt.xlabel ( 'x' )
plt.ylabel ( 'y' )
plt.title ( 'Wykres f(x) oraz wielomianu interpolacyjnego dla n=20' )
plt.grid( True )
plt.legend( )
plt.savefig ( 'Wykres_fx_n20.png')
plt.clf()

with open ('/home/dziad/projects/METODY_NUMERYCZNE/lab07/doWykresow/y5_values_czyby.txt', 'r' ) as file_three_czy:
    y1_values_czyby = [float(value) for value in file_three_czy.readline().split()]
    
plt.plot (x_values, y_values, label='f(x)')
plt.plot (x_values, y1_values_czyby, label='Wn(x)')
plt.xlabel ( 'x' )
plt.ylabel ( 'y' )
plt.title ( 'Wykres f(x) oraz Wn(x) dla n=5' )
plt.grid( True )
plt.legend( )
plt.savefig ( 'Wykres_fx_n5_czy.png')
plt.clf()

with open ('/home/dziad/projects/METODY_NUMERYCZNE/lab07/doWykresow/y10_values_czyby.txt', 'r' ) as file_four_czy:
    y2_values_czyby = [float(value) for value in file_four_czy.readline().split()]
    
plt.plot (x_values, y_values, label='f(x)')
plt.plot (x_values, y2_values_czyby, label='Wn(x)')
plt.xlabel ( 'x' )
plt.ylabel ( 'y' )
plt.title ( 'Wykres f(x) oraz Wn(x) dla n=10' )
plt.grid( True )
plt.legend( )
plt.savefig ( 'Wykres_fx_n10_czy.png')
plt.clf()

with open ('/home/dziad/projects/METODY_NUMERYCZNE/lab07/doWykresow/y15_values_czyby.txt', 'r' ) as file_five_czy:
    y3_values_czyby = [float(value) for value in file_five_czy.readline().split()]
    
plt.plot (x_values, y_values, label='f(x)')
plt.plot (x_values, y3_values_czyby, label='Wn(x)')
plt.xlabel ( 'x' )
plt.ylabel ( 'y' )
plt.title ( 'Wykres f(x) oraz Wn(x) dla n=15' )
plt.grid( True )
plt.legend( )
plt.savefig ( 'Wykres_fx_n15_czy.png')
plt.clf()

with open ('/home/dziad/projects/METODY_NUMERYCZNE/lab07/doWykresow/y20_values_czyby.txt', 'r' ) as file_six_czy:
    y4_values_czyby = [float(value) for value in file_six_czy.readline().split()]
    
plt.plot (x_values, y_values, label='f(x)')
plt.plot (x_values, y4_values_czyby, label='Wn(x)')
plt.xlabel ( 'x' )
plt.ylabel ( 'y' )
plt.title ( 'Wykres f(x) oraz Wn(x) dla n=20' )
plt.grid( True )
plt.legend( )
plt.savefig ( 'Wykres_fx_n20_czy.png')
plt.clf()
