#include "GeneralPurpouse.h"
#include "HouseHolder.h"
#include "Matrix.h"

using namespace std;

int main () {

    Matrix matrix_A = GenerateMatrixA ( 4 );

    Matrix matrix_H = matrix_A;

    Matrix matrix_R = matrix_A;

    Matrix matrix_Q;
    matrix_Q.CreateIdentityMatrix(4);

    CountryRoadsTakeMeHome ( matrix_A, matrix_R, matrix_Q, 4);

    //wypisz
    ofstream of ("../wynik.txt");

    of << "------------- Rozkład -------------\n\n";
    
    matrix_A.WriteOutOnOfstream( &of, "D" );
    matrix_Q.WriteOutOnOfstream ( &of, "Q" );
    matrix_R.WriteOutOnOfstream ( &of, "R" );
    (matrix_Q*matrix_R).WriteOutOnOfstream ( &of, "D=Q*R");

    of << "------------- Wylicznie wektorów -------------\n\n";

    matrix_H.WriteOutOnOfstream( &of, "H na początku" );
    Matrix matrix_P;
    matrix_P.CreateIdentityMatrix(4);
    FindMatrixH ( matrix_H, matrix_P, 4, 200 );
    
    matrix_H.WriteOutOnOfstream( &of, "H po przekształceniach" );
    matrix_P.WriteOutOnOfstream (&of, "P");

    of << "----> Wartości własne\n\n";
    for ( int i = 0; i < 4; i ++ ) {

        of << matrix_H [ i ] [ i ] << "\t";
    }
    of << "\n\n";

    of << "----> Wektory wartości własnych\n\n";

    Matrix X [ 4 ];

    for ( int i = 0; i < 4; i ++ ) {

        X [ i ].CreateMatrixOfZeroes ( 4, 1 );
        CreateIthOwnVector ( X [ i ], matrix_H, i );
        X [ i ].normaliseVector();

        X [ i ] = matrix_P * X [ i ];
        X [ i ].WriteOutOnOfstream ( &of, "X" + to_string ( i ) );
    }

    of.close();


   /*of.open ("../doWykresow/equation.txt");

     WriteOutMatrixOnOfstreamInAHelpfulWayForPython ( &of, X ) ;

    of.close();

    system ( "python3 ../doWykresow/graph.py");*/
}