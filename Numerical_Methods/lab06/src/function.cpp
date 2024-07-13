#include "function.h"

double ABS ( double x ) {

    return ( x < 0 ? -x : x );
}

double function::countFunction ( double x ) {

    return log ( x ) * ( x - 2 ) * ( x - 2 );
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

    std::ofstream of ( "../doWykresow/wyniki1" + std::to_string(number) + ".txt" );
    std::ofstream of2 ( "../doWykresow/roznice1" + std::to_string(number) + ".txt" );

    std::cout << "Miejsce zerowe nr. " << std::to_string ( number ) << ", punkt startowy x0 = " << x0 << '\n';

    do {

        x0 = x1;

        x1 = x0 -  countFunction ( x0 ) / countDerivativeOfAFunction ( x0 );

        std::cout << "IT." << std::to_string ( iterations) << ": x(k+1) = " << x1 << '\n';

        of << x1 << " ";

        of2 << ABS ( x1 - x0 ) << " ";

        iterations++;

    } while ( ABS ( x1 - x0 ) > 1.0e-6 );

    number ++;
    std::cout << '\n';

    of.close();
    of2.close();

    return x1;
}

void function::writeOutFunctionOnOfStream( std::ofstream *of, double jump, double a, double b ) {

    for ( double i = a; i <= b; i += jump ) {

        *of << i << ' ';
    }

    *of << '\n';

    for ( double i = a; i <= b; i += jump ) {

        *of << countFunction ( i ) << ' ';
    }
}

double functionU::countFunctionU ( double x ) {

    return countFunction ( x ) / countDerivativeOfAFunction ( x );
}

double functionU::countDerivativeOfAFunctionU ( double x ) {

    double sum = 1.0;

    return sum - countDoubleDerivativeOfAFunction ( x ) * countFunctionU ( x ) / countDerivativeOfAFunction ( x );
} 

double functionU::findZeroPlaceForU ( double x0 ) {

    double x1 = x0;

    static int number = 0;

    int iterations = 1;

    std::ofstream of ( "../doWykresow/wyniki2" + std::to_string(number) + ".txt" );
    std::ofstream of2 ( "../doWykresow/roznice2" + std::to_string(number) + ".txt" );

    std::cout << "Miejsce zerowe nr. " << std::to_string ( number ) << ", punkt startowy x0 = " << x0 << '\n';

    do {

        x0 = x1;

        x1 = x0 - 0.5 * countFunctionU ( x0 ) / countDerivativeOfAFunctionU ( x0 );

        std::cout << "IT." << std::to_string ( iterations) << ": x(k+1) = " << x1 << '\n';

        of << x1 << " ";

        of2 << ABS ( x1 - x0 ) << " ";

        iterations++;

    } while ( ABS ( x1 - x0 ) > 1.0e-6 );

    number ++;
    std::cout << '\n';

    of.close();
    of2.close();

    return x1;
}