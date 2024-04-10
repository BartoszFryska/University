#ifndef __GAUSSMETHOD_H__
#define __GAUSSMETHOD_H__

#include <iostream>
#include <vector>

using namespace std;

void TriangulateSquareMatrix ( vector < vector <double> > &matrix, vector <double> &y, const int n );  

/**
 * @brief matrix_A NEEDS to be triangulated first
*/
vector < double > CalculateCInGauss (  vector < vector <double> > matrix_A, vector <double> matrix_Y,  const int n );


/**
 * @brief matrix_A DOES NOT NEED to be triangulated first
*/
vector < double > CalculateCUsingGauss ( vector < vector <double> > matrix_A, vector <double> matrix_Y,  const int n );

#endif