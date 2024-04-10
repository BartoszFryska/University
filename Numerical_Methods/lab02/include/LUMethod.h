#ifndef __LUMETHOD_H__
#define __LUMETHOD_H__


#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void GenerateMatrixesLU ( vector < vector < float > > matrix_A, vector < vector < float > > &matrix_L, vector < vector < float > > &matrix_U, const int n );

vector < vector < float > > MatrixZero ( const int n );

vector < float > generateSingleMatrixWithOne1 ( const int n, const int n_th_position );

float WriteOutDiagonalElementsOfAnUMatrixAndDet_UAndReturnIt ( vector < vector < float > > matrix_U, string filename );

#endif