#ifndef __GAUSSJORDNANMETHOD_H__
#define __GAUSSJORDNANMETHOD_H__

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void MakeTriangulatedMatrixADiagonalMatrix ( vector < vector <float> > &matrix, vector < float > &y, const int n );

void MakeMatrixADiagonalMatrix ( vector < vector <float> > &matrix, vector < float > &y, const int n );

vector < float > CalculateCInGaussJordan (  vector < vector <float> > matrix_A, vector <float> matrix_Y,  const int n );

#endif