#ifndef __GAUSSJORDNANMETHOD_H__
#define __GAUSSJORDNANMETHOD_H__

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void MakeTriangulatedMatrixADiagonalMatrix ( vector < vector <double> > &matrix, vector < double > &y, const int n );

void MakeMatrixADiagonalMatrix ( vector < vector <double> > &matrix, vector < double > &y, const int n );

vector < double > CalculateCInGaussJordan (  vector < vector <double> > matrix_A, vector <double> matrix_Y,  const int n );

#endif