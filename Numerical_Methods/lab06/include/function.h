#ifndef __FUNCTION_H__
#define __FUNCTION_H__

#include <iostream>
#include <math.h>
#include <string.h>
#include <fstream>

class function {

    public:

    double countFunction ( double x );

    double countDerivativeOfAFunction ( double x );

    double countDoubleDerivativeOfAFunction ( double x );

    double findZeroPlace ( double x0 );

    void writeOutFunctionOnOfStream( std::ofstream *of, double jump, double a, double b );
};

class functionU : public function {

    public:

    double countFunctionU ( double x );

    double countDerivativeOfAFunctionU ( double x );

    double findZeroPlaceForU ( double x0 );
};

#endif