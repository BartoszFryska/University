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

vector < vector <double> > GenerateMatrixA ( const int n );

vector < double > GenerateVectorB ( const int n );

void WriteOutMatrix ( vector < vector < double > > matrix, string text );

void WriteOutSingleMatrixVerticaly ( vector < double > matrix, string text );

void WriteOutMatrixOnOfstream ( ofstream * of, vector < vector < double > > matrix, string text );

void WriteOutSingleMatrixVerticalyOnOfstream ( ofstream * of, vector < double > matrix, string text );

void WriteOutSingleMatrixHorizontalyOnOfstream ( ofstream * of, vector < double > matrix, string text );

vector < vector < double > > MultiplyMatrices ( vector < vector < double > > A, vector < vector < double > > B );

vector < vector < double > > ReverseMatrixA ( vector < vector < double > > matrix_A ); 

vector < vector < double > > MatrixOfZeroes ( const int n );

vector < double > VectorOfZeroes ( const int n );

vector < vector < double > > GenerateRandomSquareMatrix ( const int n );

void WriteOutMatrixOnOfstreamInAHelpfulWay ( ofstream * of, vector < vector < double > > matrix );

void MultiplyASquareMatrix ( vector < vector < double > > &matrix, const double multiplier );

vector < double > MultiplySquareMatrixByAVector ( vector < vector < double > > matrix, vector < double > vector );

void WriteOutMatrixOnOfstreamWithSetprecision ( ofstream * of, vector < vector < double > > matrix, string text );

double CountANorm ( vector < vector < double > > matrix );

vector < double > SubctractVector ( vector <double> a, vector < double > b );

vector < double > AddVector ( vector <double> a, vector < double > b );

vector < double > MultiplyVectorByAScalar ( vector <double> a, const double number);

void WriteOutMatrixOnOfstreamInAHelpfulWayForPython ( ofstream * of, vector < vector < double > > matrix);

vector < vector < double > > transponateAMatrix ( vector < vector < double > > matrix );

vector < vector < double > > matrixOfOnes ( const int n );

vector < vector < double > > multiplyVectorsToFormAMatrix ( vector < double> v, vector < double > vt );

vector < vector < double > > multiplyMatrixByAScalar ( vector < vector <double> > matrix, const double scalar );

vector < vector < double > > substractMatrix ( vector < vector <double> > matrix_A, vector < vector <double> > matrix_B);

#endif