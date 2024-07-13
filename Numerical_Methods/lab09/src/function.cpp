#include "function.h"

#define Ns 5
#define Nc 5

double ABS ( double x ) {

    return ( x < 0 ? -x : x );
}

double function1::countFunction ( double x ) {

    return 2 * sin ( x ) + sin ( 2*x ) + 2 * sin ( 3 * x );
}

double function4::countFunction ( double x ) {

    return 2 * sin ( x ) + sin ( 2*x ) + 2 * sin ( 3 * x ) + (rand()/(RAND_MAX+1.0) - 0.5 );
}

double function2::countFunction ( double x ) {

    return 2 * sin ( x ) + sin ( 2*x ) + 2 * cos( x ) + cos ( 2 * x );
}

double function3::countFunction ( double x ) {

    return 2 * sin ( 1.1 * x ) + sin ( 2.1 * x ) + 2 * sin ( 3.1 * x );
}

double return_aj ( int j, vector < double > X, int n, function &fun ) {

    double sum;

    for ( int i = 0; i <= 2 * n - 1; i ++ ) {

        sum += fun.countFunction ( X [ i ] ) * sin ( X [ i ] * j );
    }

    sum /= n;

    return sum;
}

double return_bi ( int i, vector < double > X, int n, function &fun  ) {

    if ( i == 0 ) {

        double sum;

        for ( int j = 0; j <= 2 * n - 1; j ++ ) {

            sum += fun.countFunction ( X [ j ] );
        }

        sum /= 4 * n;

        return sum;
    }

    double sum;

    for ( int j = 0; j <= 2 * n - 1; j ++ ) {

        sum += fun.countFunction ( X [ j ] ) * cos ( X [ j ] * i );
    }

    sum /= n;

    return sum;
}

double Function::countFunction ( double x, vector < double > X, int n, function& fun ) {

    double val = 0;

    for ( int i = 0; i < Ns; i ++ ) {

        val += return_aj ( i, X, n, fun ) * sin ( x * i );
    }

    for ( int i = 0; i < Nc; i ++ ) {

        val += return_bi ( i, X, n, fun )* sin ( x * i );
    }

    return val;
}

void Function::countAndCout_aj_bi ( double x, vector < double > X, int n, function& fun ){

    cout << "Next function\n";
    for ( int i = 0; i < Ns; i ++ ) {

        cout << "a" + to_string ( i ) << "\t" << return_aj ( i, X, n, fun ) << '\n' ;
    }

    cout << '\n';

    for ( int i = 0; i < Nc; i ++ ) {

        cout << "b" + to_string ( i ) << "\t" << return_bi ( i, X, n, fun ) << '\n' ;
    }

    cout << "\n\n";
}

void Function::countAndCout_aj_bi ( double x, vector < double > X, int n, function& fun, double Ms, double Mc  ){

    cout << "Next function\n";
    for ( int i = 0; i < Ms; i ++ ) {

        cout << "a" + to_string ( i ) << "\t" << return_aj ( i, X, n, fun ) << '\n' ;
    }

    cout << '\n';

    for ( int i = 0; i < Mc; i ++ ) {

        cout << "b" + to_string ( i ) << "\t" << return_bi ( i, X, n, fun ) << '\n' ;
    }

    cout << "\n\n";
}

void Function_WithoutDefaultMcMs::ofstreamAndCout_aj_bi ( double x, vector < double > X, int n, function& fun, double Ms, double Mc  ){

    ofstream of1 ( "../ai"+to_string ((int)Ms)+".txt" );
    ofstream of2 ( "../bj"+to_string ((int)Mc)+".txt" );

    for ( int i = 0; i < Ms; i ++ ) {

        of1 << return_aj ( i, X, n, fun ) << ' ' ;
    }

    for ( int i = 0; i < Ms; i ++ ) {

        of2 << return_bi ( i, X, n, fun ) << ' ';
    }

    of1.close();
    of2.close();
}

double Function_WithoutDefaultMcMs::countFunction ( double x, vector < double > X, int n, function &fun, double Ms, double Mc ) {

    double val = 0;

    for ( int i = 0; i < Ms; i ++ ) {

        val += return_aj ( i, X, n, fun ) * sin ( x * i );
    }

    for ( int i = 0; i < Mc; i ++ ) {

        val += return_bi ( i, X, n, fun )* sin ( x * i );
    }

    return val;
}

void Function_WithoutDefaultMcMs::countAndCout_aj_bi ( double x, vector < double > X, int n, function &fun, double Ms, double Mc ){

    cout << "Next function\n";
    for ( int i = 0; i < Ms; i ++ ) {

        cout << "a" + to_string ( i ) << "\t" << return_aj ( i, X, n, fun ) << '\n' ;
    }

    cout << '\n';

    for ( int i = 0; i < Mc; i ++ ) {

        cout << "b" + to_string ( i ) << "\t" << return_bi ( i, X, n, fun ) << '\n' ;
    }

    cout << "\n\n";
}

vector < double > countVectorX ( double n ) {

    vector < double > x;

    for ( int i = 0; i <= 2*n - 1; i ++ )
        x.push_back ( (double) 2 * M_PI * i / 2 / n );

    return x;
}


void coutVector ( vector < double > v, std::string name ) {

    cout << name << ":\n";
    for ( auto V : v ) {

        cout << V << ' ';
    }

    cout << '\n';
}

void ofstreamVector ( ofstream *of, vector < double > v, std::string name ) {

    for ( auto V : v ) {

        *of << V << ' ';
    }
    *of << "\n";
}