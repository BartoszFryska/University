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

vector < vector <double> > GenerateMatrixA ( vector < double > x, const int n );

vector <double> GenerateMatrixY (vector < vector <double> > matrix_A, vector < double > c, const int n );

void WriteOutMatrix ( vector < vector < double > > matrix, string text );

void WriteOutSingleMatrixVerticaly ( vector < double > matrix, string text );

void WriteOutMatrixOnOfstream ( ofstream * of, vector < vector < double > > matrix, string text );

void WriteOutSingleMatrixVerticalyOnOfstream ( ofstream * of, vector < double > matrix, string text );

vector < vector < double > > GenerateRandomSquareMatrix ( const int n );

vector < double > GenerateRandomVector ( const int n );

void FixMistakesInMatrix ( vector <vector <double> > * matrix );

#endif