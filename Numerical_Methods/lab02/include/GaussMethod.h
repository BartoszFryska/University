#ifndef __GAUSSMETHOD_H__
#define __GAUSSMETHOD_H__

#include <iostream>
#include <vector>

using namespace std;

void TriangulateSquareMatrix ( vector < vector <float> > &matrix, vector <float> &y, const int n );  

/**
 * @brief matrix_A NEEDS to be triangulated first
*/
vector < float > CalculateCInGauss (  vector < vector <float> > matrix_A, vector <float> matrix_Y,  const int n );


/**
 * @brief matrix_A DOES NOT NEED to be triangulated first
*/
vector < float > CalculateCUsingGauss ( vector < vector <float> > matrix_A, vector <float> matrix_Y,  const int n );

#endif