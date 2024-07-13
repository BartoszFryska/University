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

class functiontwo {

    public:

    functiontwo(){}

    double countFunction ( double x );

    double countDerivativeOfAFunction ( double x );

    double countDoubleDerivativeOfAFunction ( double x );

    double findZeroPlace ( double x0 );
};

vector<double> do_wzor_13( vector<double> x, const int n );

#endif