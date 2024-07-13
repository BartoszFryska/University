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

double lenVec ( vector <double> one );

class function {

    public:

    function(){}

    double countFunction ( vector < double > r );

    double countDx ( vector < double > r );

    double countDy ( vector < double > r );
};


vector < double > countVectorR ( vector <double> rPrev, double epsilon );

void coutVector ( vector < double > v, std::string name );

void ofstreamVector ( ofstream *of, vector < double > v, std::string name );



#endif