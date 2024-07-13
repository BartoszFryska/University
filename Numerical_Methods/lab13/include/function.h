#ifndef __FUNCTION_H__
#define __FUNCTION_H__

#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>
#include <fstream>

using namespace std;

vector <double> removeTwo ( vector <double> one, vector <double> two );

vector <double> addTwo ( vector <double> one, vector <double> two );

vector <double> multiplyTwo ( vector <double> one, vector <double> two );

double lenVec ( vector <double> one );

class functionOne {

    public:

    functionOne(){}

     double countFunction ( double x );

     double countIntegralFunction ( double a, double b, int N);

     double countIntegralFunctionAnalitic (double a, double b);
};

class functionTwo {

    public:

    functionTwo(){}

     double countFunction ( double x, double k );

     double countIntegralFunction (int N, double k);

     double countIntegralFunctionAnalitic ( double k );
};

class functionThree {

    public:

    functionThree(){}

     double countFunctionXSide ( double x );

     double countFunctionYSide ( double y );

    double countIntegralFunctionXSide ( double polozeniaWezlyKwadraturyOne [],double wezlyKwadraturyOne [], int N );
    double countIntegralFunctionYSide ( double polozeniaWezlyKwadraturyOne [],double wezlyKwadraturyOne [], int N );

     double countIntegralFunction ( int N);

     double returnIntegralFunctionAnalitic ();
};



void coutVector ( vector < double > v, std::string name );

void ofstreamVector ( ofstream *of, vector < double > v, std::string name );




#endif