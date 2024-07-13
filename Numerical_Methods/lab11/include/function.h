#ifndef __FUNCTION_H__
#define __FUNCTION_H__

#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>
#include <fstream>
#include <utility>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SWAP( a, b ) tempr = ( a ); ( a ) = ( b ); ( b ) = tempr
#define Tc 1.
#define OMEGA (2*M_PI/Tc)

using namespace std;

vector <double> removeTwo ( vector <double> one, vector <double> two );

vector <double> addTwo ( vector <double> one, vector <double> two );

vector <double> multiplyTwo ( vector <double> one, vector <double> two );

double lenVec ( vector <double> one );

class function {

    public:

    virtual double countFunction ( double t );
};

class functionOne  {

    public:

    double countFunction ( double t );
};

class functionOneVar {

    public:

    double countFunction ( double t );
};

class functionGauss  {

    public:

    double countFunction ( double t );
};

namespace FFT {


    void count ( double fun[], long nn, int isign);

    //double reverse ( double t, vector <double> ftt );
};

void coutVector ( vector < double > v, std::string name );

void ofstreamVector ( ofstream *of, vector < double > v, std::string name );




#endif