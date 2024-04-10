#ifndef __GAUSSMETHOD_H__
#define __GAUSSMETHOD_H__

#include <iostream>
#include <vector>

using namespace std;

void TriangulateSquareMatrix ( vector < vector <double> > &matrix, vector <double> &y, const int n );  

vector < double > CalculateCInGauss (  vector < vector <double> > matrix_A, vector <double> matrix_Y,  const int n );

#endif