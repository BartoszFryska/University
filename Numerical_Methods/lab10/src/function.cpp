#include "function.h"

#define Ns 5
#define Nc 5

double ABS ( double x ) {

    return ( x < 0 ? -x : x );
}

double function::countFunction ( vector < double > r ) {

    double x = r [ 0 ];
    double y = r [ 1 ];

    return 5./2 * pow ( (pow ( x, 2 ) - y), 2 ) + pow( 1 - x, 2 );
}

vector <double> removeTwo ( vector <double> one, vector <double> two ) { if ( one.size() != two.size()) {return one;}
    for ( int i = 0; i < one.size(); i ++ ) one [ i ] -= two [ i ];
    return one;
}

vector <double> addTwo ( vector <double> one, vector <double> two ){ if ( one.size() != two.size()) {return one;}
    for ( int i = 0; i < one.size(); i ++ ) one [ i ] += two [ i ];
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

double function::countDx ( vector < double > r ) {

    vector < double > ex = { 1, 0 };
    double delta = 1.0e-4;

    ex [ 0 ] *= delta;

    function fun;

    vector < double > first_arg = addTwo(r, ex) ;
    
    vector < double > second_arg = removeTwo(r, ex) ;

    return ( fun.countFunction ( first_arg ) - fun.countFunction ( second_arg ) ) / 2. / delta; 
}

double function::countDy ( vector < double > r ) {

    vector < double > ey = { 0, 1 };
    double delta = 1.0e-4;

    ey [ 1 ] *= delta;

    function fun;

    vector < double > first_arg = addTwo(r, ey) ;
    
    vector < double > second_arg = removeTwo(r, ey) ;

    return ( fun.countFunction ( first_arg ) - fun.countFunction ( second_arg ) ) / 2 / delta; 
}


vector < double > countVectorR ( vector <double> rPrev, double epsilon ) {

    double h = 0.1;
    vector < double > operato = { 0, 0 };
    function fun;

    ofstream of ( "../iter"+to_string(epsilon)+".dat" );

    operato [ 0 ] = fun.countDx ( rPrev ) * h;
    operato [ 1 ] = fun.countDy ( rPrev ) * h;

    vector < double  > rCurr = removeTwo(rPrev, operato);

    ofstreamVector(&of, rCurr, "" );

    for ( int i = 0; i < 1000 && lenVec ( removeTwo(rCurr, rPrev) ) > epsilon; i++ ) {

        rPrev = rCurr;
        operato [ 0 ] = fun.countDx ( rPrev ) * h;
        operato [ 1 ] = fun.countDy ( rPrev ) * h;

        rCurr = removeTwo(rPrev, operato);

        ofstreamVector(&of, rCurr, "" );
    }

    return rCurr;
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