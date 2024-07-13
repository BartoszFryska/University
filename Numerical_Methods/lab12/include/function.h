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

class function {

    public:

    function(){}

    virtual double countFunction ( double x, double k, double m ){return 0.0;};

    virtual double countIntegralFunction ( double k, double m, double a, double b ){return 0.0;};
};

class functionOne : public function {

    public:

    functionOne(){}

     double countFunction ( double x, double k , double m  );

     double countIntegralFunction ( double k , double m, double a, double b);
};



void coutVector ( vector < double > v, std::string name );

void ofstreamVector ( ofstream *of, vector < double > v, std::string name );




#endif