#ifndef __METODABISEKCJI_H__
#define __METODABISEKCJI_H__

#include <iostream>
#include <vector>
#include <math.h>
#include<cstdlib>
#include <fstream>
#include <iomanip>
#include <map>

using namespace std;

double CountLambda ( double a, double b );

double GetS ( vector < vector < double > > matrix_H );

vector < double > CountP ( vector < vector < double > > matrix_H , const int n, const double lambda );

double returnOwnValue ( vector < vector < double > > matrix_H, int N, int IT_MAX , double lambda );

vector < double > ReturnX( vector < vector < double > > matrix_H, double a, double b, double lambda );

vector < double > ownVectorX ( const double x, vector < vector < double > > matrix_H );

int returnHowManytimsSignChanged (vector < vector < double > > matrix_H, const int n, const double lambda  );

#endif