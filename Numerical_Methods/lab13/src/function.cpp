#include "function.h"
#include "gauleg.c"
#include "gaulag.c"
#include "gauher.c"

double functionOne::countFunction( double x ) {

    return x / ( 4 * pow ( x, 2 ) + 1 );
}

double functionOne::countIntegralFunction ( double a, double b, int N ) {

    double polozeniaWezlyKwadraturyOne [N+1];
    double wezlyKwadraturyOne [N+1];

    gauleg(a, b, polozeniaWezlyKwadraturyOne, wezlyKwadraturyOne, N);

    double sum = 0.0;
    double sumOfWspolczynniki = 0.0;

    for ( int n = 1; n <= N; n++ ) {

        sum += countFunction ( polozeniaWezlyKwadraturyOne [ n ] ) * wezlyKwadraturyOne [ n ];
        sumOfWspolczynniki += wezlyKwadraturyOne [ n ];
    }

    std::cout << "c1 | N=" << N << " | " << "Suma wspolczynnikow : " << sumOfWspolczynniki << '\n';

    return sum;
}

double functionOne::countIntegralFunctionAnalitic ( double a, double b ) {

    return (1. / (2.*4.)) * ( (log ( 4*pow(b,2) + 1)) - log ( 4*pow(a,2)+1 ) );
}

double functionTwo::countFunction( double x, double k ) {

    return pow ( x, k ) ;
}

double functionTwo::countIntegralFunction (int N, double k) {

    double polozeniaWezlyKwadraturyOne [N+1];
    double wezlyKwadraturyOne [N+1];
    gaulag (polozeniaWezlyKwadraturyOne, wezlyKwadraturyOne, N, 0 );

    double sum = 0.0;
    double sumOfWspolczynniki = 0.0;

    for ( int n = 1; n < N+1; n++ ) {

        sum += countFunction ( polozeniaWezlyKwadraturyOne [ n ], k ) * wezlyKwadraturyOne [ n ];
        sumOfWspolczynniki += wezlyKwadraturyOne [ n ];
    }
    
    std::cout << "c2 | k=" << std::to_string ((int)k) << " | N=" << N << " | " << "Suma wspolczynnikow : " << sumOfWspolczynniki << '\n';

    return sum;
}

long long silnia ( int k ) { if ( k == 0 ) return 1; return (long long) k * silnia(k-1); }

double functionTwo::countIntegralFunctionAnalitic ( double k ) {

    return silnia((int)k);
}

double functionThree::countFunctionXSide( double x ) {

    return pow ( sin ( x ), 2 );
}

double functionThree::countFunctionYSide( double y ) {

    return pow ( sin ( y ), 4 );
}

double functionThree::countIntegralFunctionXSide (double polozeniaWezlyKwadraturyOne [],double wezlyKwadraturyOne [], int N) {

    double sum = 0.0;

    for ( int n = 1; n < N+1; n++ ) {

        sum += countFunctionXSide ( polozeniaWezlyKwadraturyOne [ n ] ) * wezlyKwadraturyOne [ n ];
    }

    return sum;
}
double functionThree::countIntegralFunctionYSide ( double polozeniaWezlyKwadraturyOne [],double wezlyKwadraturyOne [], int N ) {

    double sum = 0.0;

    for ( int n = 1; n < N+1; n++ ) {

        sum += countFunctionYSide ( polozeniaWezlyKwadraturyOne [ n ] ) * wezlyKwadraturyOne [ n ];
    }

    return sum;
}

double functionThree::countIntegralFunction ( int N ) {

    double polozeniaWezlyKwadraturyOne [N+1];
    double wezlyKwadraturyOne [N+1];
    double sumOfWspolczynniki = 0;

    gauher (polozeniaWezlyKwadraturyOne, wezlyKwadraturyOne, N );

    for ( int n = 1; n < N+1; n++ ) { sumOfWspolczynniki += wezlyKwadraturyOne [ n ]; }

    std::cout << "c3 | N=" << N << " | " << "Suma wspolczynnikow : " << sumOfWspolczynniki << '\n';

    return countIntegralFunctionXSide(polozeniaWezlyKwadraturyOne, wezlyKwadraturyOne, N ) * countIntegralFunctionYSide(polozeniaWezlyKwadraturyOne, wezlyKwadraturyOne, N );
}

double functionThree::returnIntegralFunctionAnalitic () { return 0.1919832644; }

vector <double> removeTwo ( vector <double> one, vector <double> two ) { if ( one.size() != two.size()) {return one;}
    for ( int i = 0; i < one.size(); i ++ ) one [ i ] -= two [ i ];
    return one;
}

vector <double> addTwo ( vector <double> one, vector <double> two ){ if ( one.size() != two.size()) {return one;}
    for ( int i = 0; i < one.size(); i ++ ) one [ i ] += two [ i ];
    return one;
}

vector <double> multiplyTwo ( vector <double> one, vector <double> two ){ if ( one.size() != two.size()) {return one;}
    for ( int i = 0; i < one.size(); i ++ ) one [ i ] *= two [ i ];
    return one;
}


double lenVec ( vector <double> one ) {

    double sum = 0;

    for ( auto v : one ) {

        sum += v*v;
    }

    sum *= 10000;

    return sqrt(sum)/100;
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