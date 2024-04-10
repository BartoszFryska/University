#include "GeneralPurpouse.h"
#include "GaussMethod.h"
#include "GaussJordanMethod.h"
#include "LUMethod.h"
#include "NajwiekszySpadekDoRURL.h"
#include "MetodaBisekcji.h"

using namespace std;

int main () {

    const int n = 50;

    vector < vector < double > > matrix_H = GenerateMatrixH ( n );

    double a = GetS ( matrix_H );
    double b = -a;
    double lambda = CountLambda ( a, b );

    vector < double > x = ReturnX( matrix_H, a, b, lambda );
    vector < vector <double > > X;

    for ( int i = 0; i < 5; i ++ ) {

        X.push_back ( ownVectorX ( x [ i ], matrix_H ));
    }
    
    //wypisz
    ofstream of ("../wynik.txt");
    
    WriteOutMatrixOnOfstream ( &of, matrix_H, "H" );
    WriteOutSingleMatrixHorizontalyOnOfstream ( &of, x, "X [i]" );
    for ( int i = 0; i < 5; i ++ ) {

        WriteOutSingleMatrixHorizontalyOnOfstream ( &of, X [ i ], "x" + to_string(i) );
    }

    of.close();

    of.open ("../doWykresow/equation.txt");

     WriteOutMatrixOnOfstreamInAHelpfulWayForPython ( &of, X ) ;

    of.close();

    system ( "python3 ../doWykresow/graph.py");
}