#ifndef __HOUSEHOLDR_H__
#define __HOUSEHOLDR_H__

#include <iostream>
#include <vector>
#include <math.h>
#include<cstdlib>
#include <fstream>
#include <iomanip>
#include <map>
#include "MetodaBisekcji.h"
#include "GeneralPurpouse.h"

vector < double > TakeX ( vector < vector <double > > matrix_A, const int ncol );

vector < double > ReturnE ( const int n, const int i );

void CountryRoadsTakeMeHome ( vector < vector <double > > &matrix_A, vector < vector <double > > &matrix_R, vector < vector <double > > &matrix_Q, const int n );

#endif