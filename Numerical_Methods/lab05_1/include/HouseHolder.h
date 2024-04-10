#ifndef __HOUSEHOLDR_H__
#define __HOUSEHOLDR_H__

#include <iostream>
#include <vector>
#include <math.h>
#include<cstdlib>
#include <fstream>
#include <iomanip>
#include <map>
#include "GeneralPurpouse.h"
#include "Matrix.h"

double returnVectorNorm ( Matrix v );

Matrix ReturnE ( const int n, const int i );

void CountryRoadsTakeMeHome ( Matrix &matrix_A, Matrix &matrix_R, Matrix &matrix_Q, const int n );

void FindMatrixH ( Matrix &matrix_H, Matrix & matrix_P, const int n, const int IT );

void CreateIthOwnVector ( Matrix &X, Matrix matrix_H, const int i );

void ZeroLargestThanI ( Matrix &x, const int i );

#endif