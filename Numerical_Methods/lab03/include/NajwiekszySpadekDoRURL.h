#ifndef __NAJWIEKSZYSPADEKDORURLN_H__
#define __NAJWIEKSZYSPADEKDORURLN_H__

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector < double > SubctractVector ( vector <double> a, vector < double > b );

vector < double > AddVector ( vector <double> a, vector < double > b );

vector < double > MultiplyVectorByAScalar ( vector <double> a, const double number);

vector < double> FindLargestFallFirstValue ( vector <double> &x, vector <double> &b, vector < vector < double > > matrix_A, std::string filename );

vector < double> FindLargestFallSecondValue ( vector <double> &x, vector <double> &b, vector < vector < double > > matrix_A, std::string filename );

double ReturnVectorTransponatedMultipliedByAVector ( vector < double > toTransponate, vector < double > otherVector );

double ReturnEuqlidesNorm ( vector < double > r );

#endif