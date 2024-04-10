#ifndef __GENERALPURPOUSE_H__
#define __GENERALPURPOUSE_H__

#include <iostream>
#include <vector>
#include <math.h>
#include<cstdlib>
#include <fstream>
#include <iomanip>
#include <map>

using namespace std;

vector < vector <float> > GenerateMatrixA ( const int n );

vector <float> GenerateMatrixY (vector < vector <float> > matrix_A, vector < float > c, int n );

void WriteOutMatrix ( vector < vector < float > > matrix, string text );

void WriteOutSingleMatrixVerticaly ( vector < float > matrix, string text );

void WriteOutMatrixOnOfstream ( ofstream * of, vector < vector < float > > matrix, string text );

vector < vector < float > > MultiplyMatrices ( vector < vector < float > > A, vector < vector < float > > B );

vector < vector < float > > ReverseMatrixA ( vector < vector < float > > matrix_A ); 

vector < vector < float > > MatrixOfZeroes ( const int n );

vector < vector < float > > GenerateRandomSquareMatrix ( const int n );

void WriteOutMatrixOnOfstreamInAHelpfulWay ( ofstream * of, vector < vector < float > > matrix );

void MultiplyASquareMatrix ( vector < vector < float > > &matrix, const float multiplier );

void WriteOutMatrixOnOfstreamWithSetprecision ( ofstream * of, vector < vector < float > > matrix, string text );

float CountANorm ( vector < vector < float > > matrix );

#endif