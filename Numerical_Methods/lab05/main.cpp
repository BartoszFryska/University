#include "GeneralPurpouse.h"
#include "GaussMethod.h"
#include "GaussJordanMethod.h"
#include "LUMethod.h"
#include "NajwiekszySpadekDoRURL.h"
#include "MetodaBisekcji.h"
#include "HouseHolder.h"
#include "Matrix.h"

using namespace std;

int main () {

   /* const int n = 4;

    vector < vector < double > > matrix_A = GenerateMatrixA ( n );

    vector < vector <double > > matrix_R = matrix_A;
    vector < vector < double > > matrix_Q = matrixOfOnes ( n );

    CountryRoadsTakeMeHome ( matrix_A, matrix_R, matrix_Q, n );

    vector < vector < double > > matrix_Q_t = transponateAMatrix ( matrix_Q );

    //wypisz
    ofstream of ("../wynik.txt");
    
    WriteOutMatrixOnOfstream ( &of, matrix_A, "A" );
    WriteOutMatrixOnOfstream ( &of, matrix_Q, "Q" );
    WriteOutMatrixOnOfstream ( &of, matrix_R, "R" );
    WriteOutMatrixOnOfstream( &of, matrix_Q_t, "Qt" );
    WriteOutMatrixOnOfstream( &of, MultiplyMatrices ( matrix_Q_t, matrix_R ), "A=Q*R" );

    of.close();*/

    Matrix matrix_one ( 6 );

    for ( int i = 0; i < matrix_one.Rows(); i ++ ) {

      double fi = 2;

        for ( int j = 0; j < matrix_one.Columns(); j ++ ) {

            matrix_one [ i ] [ j ] = (double) 1 / ( fi + 2 * i + j );
        }
    }

    matrix_one.WriteOutOnCout("one");

    const double a = 3.69;

    (matrix_one * a).WriteOutOnCout("one*number");


   /*of.open ("../doWykresow/equation.txt");

     WriteOutMatrixOnOfstreamInAHelpfulWayForPython ( &of, X ) ;

    of.close();

    system ( "python3 ../doWykresow/graph.py");*/
}