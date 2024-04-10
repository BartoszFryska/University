#ifndef __LUMETHOD_H__
#define __LUMETHOD_H__


#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void GenerateMatrixesLU ( vector < vector < double > > matrix_A, vector < vector < double > > &matrix_L, vector < vector < double > > &matrix_U, const int n );

vector < vector < double > > MatrixZero ( const int n );

vector < double > generateSingleMatrixWithOne1 ( const int n, const int n_th_position );

double WriteOutDiagonalElementsOfAnUMatrixAndDet_UAndReturnIt ( vector < vector < double > > matrix_U, string filename );

#endif