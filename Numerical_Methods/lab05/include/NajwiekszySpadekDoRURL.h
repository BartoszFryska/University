#ifndef __NAJWIEKSZYSPADEKDORURLN_H__
#define __NAJWIEKSZYSPADEKDORURLN_H__

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector < double> FindLargestFall ( vector <double> &x, vector <double> &b, vector < vector < double > > matrix_A );

double ReturnAlpha ( vector < double > toTransponate, vector < double > otherVector );

double ReturnRK ( vector < double > r );

#endif