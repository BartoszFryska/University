#include "function.h"

double ABS ( double x ) {

    return ( x < 0 ? -x : x );
}

double function::countFunction ( double x ) {

    return exp( - (x * x) );
}

double function::countDerivativeOfAFunction ( double x ) {

    double up = (x - 2) * ( x + 2 * x * log ( x ) - 2 );

    return up / x;
} 

double function::countDoubleDerivativeOfAFunction ( double x ) {

    double sum = 0.0;

    sum -= 4.0 / x / x;
    sum -= 4.0 / x;
    sum += 2.0 * log ( x );
    return sum + 3.0;
}

double function::findZeroPlace ( double x0 ) {

    double x1 = x0;

    static int number = 0;

    int iterations = 1;

    std::cout << "Miejsce zerowe nr. " << std::to_string ( number ) << ", punkt startowy x0 = " << x0 << '\n';

    do {

        x0 = x1;

        x1 = x0 -  countFunction ( x0 ) / countDerivativeOfAFunction ( x0 );

        std::cout << "IT." << std::to_string ( iterations) << ": x(k+1) = " << x1 << '\n';

        iterations++;

    } while ( ABS ( x1 - x0 ) > 1.0e-6 );

    number ++;
    std::cout << '\n';

    return x1;
}

double functionOmega::countFunctionOme ( vector <double> X, double x, int i ) {

    double sum = 1;

    for ( int ix = 0; ix < X.size(); ix ++ ) {

        if ( i != ix ) sum *= ( x - X [ ix ] );
    }

    return sum;
}

double functionOmega::countDerivativeOfAFunctionOme ( vector <double> X, double x ) {

    double sum = 1.0;

    for ( int i = 0; i < X.size(); i ++ ) {

        if ( x != X [ i ] ) sum *= ( x - X [ i ] );
    }

    return sum;
} 

double endFunction::countFunctionEnd ( vector <double> X, vector <double> Y, double x ) {

    double sum = 0;

    n = X.size();

    for ( int i = 0; i < n; i ++ ) {

        sum += Y [ i ] * countFunctionOme ( X, x, i ) /*/ ( x - X [ i ] )*/ / countDerivativeOfAFunctionOme ( X, X [ i ] );
    }

    return sum;
}