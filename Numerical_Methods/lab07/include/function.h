#ifndef __FUNCTION_H__
#define __FUNCTION_H__

#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>

using namespace std;

class function {

    public:

    function(){}

    double countFunction ( double x );

    double countDerivativeOfAFunction ( double x );

    double countDoubleDerivativeOfAFunction ( double x );

    double findZeroPlace ( double x0 );
};

class functionOmega : public function {

    protected:

    int n;
    public:

    functionOmega (int a) { n = a; }

    double countFunctionOme ( vector <double> X, double x, int i );

    double countDerivativeOfAFunctionOme ( vector <double> X, double x );
};

class endFunction : public functionOmega {

    public:

    endFunction ( int a ) : functionOmega( a ) {}

    double countFunctionEnd ( vector <double> X, vector <double> Y, double x );
};

#endif