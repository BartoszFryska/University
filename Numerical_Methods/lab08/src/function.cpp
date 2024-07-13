#include "function.h"

double ABS ( double x ) {

    return ( x < 0 ? -x : x );
}

double function::countFunction ( double x ) {

    return 1./(1.+x*x);
}

double function::countDerivativeOfAFunction ( double x ) {

    //double up = (x - 2) * ( x + 2 * x * log ( x ) - 2 );

    return 0;
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

double functiontwo::countFunction ( double x ) {

    return cos ( 2 * x );
}

double functiontwo::countDerivativeOfAFunction ( double x ) {

    double up = (x - 2) * ( x + 2 * x * log ( x ) - 2 );

    return up / x;
} 

double functiontwo::countDoubleDerivativeOfAFunction ( double x ) {

    double sum = 0.0;

    sum -= 4.0 / x / x;
    sum -= 4.0 / x;
    sum += 2.0 * log ( x );
    return sum + 3.0;
}

double functiontwo::findZeroPlace ( double x0 ) {

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

vector<double> do_wzor_13( vector<double> x, const int n ) {

    vector<double> y;
    for( int i = 0; i < n; i++ ){
        double a1 = 1. / ( 1. + ( x[i] - 0.01 ) * ( x[i] - 0.01 ) );
        double a2 = 1. / ( 1. + x[i] * x[i] );
        double a3 = 1. / ( 1. + ( x[i] + 0.01 ) * ( x[i] + 0.01 ) );
        y.push_back( ( a1 - 2. * a2 + a3 ) / ( 0.01 * 0.01 ) );
    }
    return y;
}