#ifndef __FUNCTION_H__
#define __FUNCTION_H__

#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>
#include <fstream>

using namespace std;

class function {

    public:
    virtual double countFunction ( double x ){return 0.0;};
};

class function1 : public function {

    public:
    double countFunction ( double x );
};

class function2 : public function  {

    public:
    double countFunction ( double x );
};

class function3 : public function  {

    public:
    double countFunction ( double x );
};

class function4 : public function  {

    public:
    double countFunction ( double x );
};

class Function {

    public:
    double countFunction ( double x, vector < double > X, int n, function &fun );
    void countAndCout_aj_bi ( double x, vector < double > X, int n, function &fun );
    void countAndCout_aj_bi ( double x, vector < double > X, int n, function &fun, double Ms, double Mc );
};

class Function_WithoutDefaultMcMs {

    public:
    double countFunction ( double x, vector < double > X, int n, function &fun, double Ms, double Mc );
    void countAndCout_aj_bi ( double x, vector < double > X, int n, function &fun, double Ms, double Mc );
    void ofstreamAndCout_aj_bi ( double x, vector < double > X, int n, function& fun, double Ms, double Mc  );
};

vector < double > countVectorX ( double n );

void coutVector ( vector < double > v, std::string name );

void ofstreamVector ( ofstream *of, vector < double > v, std::string name );

#endif