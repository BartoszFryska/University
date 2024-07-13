#include "function.h"
#include "Matrix.h"

using namespace std;

#define NUMBER_OF_S 150

double getS (  double x_1, Matrix A, vector<double> x, vector<double> y, vector<double> h, Matrix m, const int n ) {

     double s = 0;

    int i;
    for( i = 0; i < n - 1; i++ ){ //i należy od 0 do 3
        if( x_1 <= x[1 + i] ) break;
    }

    double A_const = ( ( y[1 + i] - y[i] ) / h[i] ) - ( h[i] / 6. * ( m[i + 1][0] - m[i][0] ) );
    double B_const = y[i] - ( m[i][0] * h[i] * h[i] / 6. );

    s = ( m[i][0] * ( ( x[i + 1] - x_1 ) * ( x[i + 1] - x_1 ) * ( x[i + 1] - x_1 ) ) / ( 6. * h[i] ) ) + ( m[i + 1][0] * pow( x_1 - x[i], 3 ) / ( 6. * h[i] ) ) + ( A_const * ( x_1 - x[i] ) ) + B_const;

    return s;
}

int returnI ( double x, vector < double > pointsx ) {

    for ( int i = 0; i < pointsx.size() - 1; i ++ ) {

        if ( x >= pointsx [ i ] && x <= pointsx [ i + 1 ] ) {

            return i+1;
        }
    }

    return -1;
}
int main () {


    function fun; //w przedziale <a, b>

    double a = -5;
    double b = 5;

    int n = 10;

    Matrix A ( n );

    // A middle

    A [ 0 ] [ 0 ] = 1;
    for ( int i = 1; i < n-1; i ++ ) {

        A [ i ] [ i ] = 2;
    }
    A [ n-1 ] [ n-1 ] = 1;

    // rownoodlegle punkty

    vector < double > pointsx;
    for ( int i = 0; i < n; i ++ ) {

        pointsx.push_back ( a + ((double) (b - a) / (n - 1)) * i );
    }

    // h [ i ]

    vector < double > hi;
    for ( int i = 0; i < n-1; i ++ ) {

        hi.push_back ( pointsx [ i + 1 ] - pointsx [ i ] );
    }

    // A uzupelnienie o mi oraz lambda

    for ( int i = 1; i < n-1; i ++ ) {

        A [ i ] [ i+1 ] = hi [ i ] / ( hi [ i ] + hi [ i-1 ]); // lambda [ i ]
        A [ i ] [ i - 1 ] = 1. - A [ i ] [ i+1 ]; // mi [ i ]
    }

    // y-greki

    vector < double > pointsy;

    for ( int i = 0; i < n; i ++ ) {

        pointsy.push_back ( fun.countFunction( pointsx [ i ] ) );
    }


    A.WriteOutOnCout("A");
    A.reverse().WriteOutOnCout("A rev");

    // vector a

    Matrix a_mat ( n, 1 );

    a_mat [ 0 ] [ 0 ] = 0;
    for ( int i = 1; i < n - 1; i ++ ) {

        a_mat [ i ] [ 0 ] = 6. / ( hi [ 0 ] + hi [ 0 ]  );
        a_mat [ i ] [ 0 ] = a_mat [ i ] [ 0 ] * ( ( ( pointsy [ i + 1 ] - pointsy [ i ] ) / hi [ 0 ] ) - ( (pointsy [ i ] - pointsy [ i - 1 ] ) / hi [ 0 ]) );
    }
    a_mat [ n - 1 ] [ 0 ] = 0;

    Matrix M ( n, 1 );

    M = (A.reverse()) * a_mat;

    a_mat.WriteOutOnCout("a");

    M.WriteOutOnCout("M");

    vector < double > s;
    vector <double> X;

    for ( double i = a; i <= b; i += (b-a)/NUMBER_OF_S ) {

        X.push_back ( i );
    }

    for ( auto x : X ) {

        int i = returnI ( x, pointsx );
        s.push_back( getS ( x, A, pointsx, pointsy, hi, M, n ) );
    }

    ofstream of1 ( "../doWykresow/x_values.txt" );

    for ( auto v : X ) {

        of1 << v << " ";
    }

    of1.close();

    ofstream of2 ( "../doWykresow/s_values.txt" );

    for ( auto v : s ) {

        of2 << v << " ";
    }

    of2.close();

    system ( "python3 ../doWykresow/graph.py");

    if ( n == 10 ) {

        ofstream ofm ( "../doWykresow/m_values.txt");

        for ( int i = 0; i < n; i ++ ) {

            ofm << M [ i ] [ 0 ] << ' ';
        }

        ofm.close();

        of1.open ( "../doWykresow/x_der_values.txt");

        vector<double> x_pochodna;

        for( double i = -5.; i <= 5.; i = i + 10. / ( n - 1 ) )
            x_pochodna.push_back( i );

        for( int i = 0; i < x_pochodna.size(); i++ )
            of1 << x_pochodna[i] << " ";
        
        of1.close();

        //wzór (13)

        of2.open ( "../doWykresow/y_der_values.txt" );

        vector<double> y_pochodna = do_wzor_13( x_pochodna, x_pochodna.size() );
    
        for( int i = 0; i < y_pochodna.size(); i++ )
            of2 << y_pochodna[i] << " ";
    
        of2.close();

        system ( "python3 ../doWykresow/graph2.py");
    }
}