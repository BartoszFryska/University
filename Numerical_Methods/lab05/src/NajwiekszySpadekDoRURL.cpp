#include "NajwiekszySpadekDoRURL.h"
#include "GeneralPurpouse.h"

double ReturnRK ( vector < double > r ) {

    double number = 0.0;

    const int n = r.size();

    for ( int i = 0; i < n; i ++ ) {

        number += r [ i ] * r [ i ];
    }

    return sqrt ( number );
}

double ReturnAlpha ( vector < double > toTransponate, vector < double > otherVector ) {

    double alpha = 0.0;

    const int n = toTransponate.size();

    for ( int i = 0; i < n; i ++ ) {

        alpha += toTransponate [ i ] * otherVector [ i ];
    }

    return alpha;
}

vector < double> FindLargestFall ( vector <double> &x, vector <double> &b, vector < vector < double > > matrix_A ) {

    ofstream of ( "../iteracje.txt" );

    const int n = x.size();

    vector < double > r = VectorOfZeroes ( n );
    double alpha;

    int k = 0;

    do {
        r.clear();
        k ++;

        r = SubctractVector ( b, MultiplySquareMatrixByAVector ( matrix_A, x ));

        alpha = ReturnAlpha ( r, r );

        alpha /= ReturnAlpha ( r, MultiplySquareMatrixByAVector ( matrix_A, r ) );

        x = AddVector ( x, MultiplyVectorByAScalar ( r, alpha ) );

        // wypisywanie

        of << "\nIteracja " << k << '\n';
        of << "Norma eukidesowa ||rk|| = " << ReturnRK ( r ) << '\n';
        of << "Wartosc alpha k = " << alpha << '\n';
        of << "Norma eukilidesowa ||xk|| = " << ReturnRK ( x ) << '\n';

    } while ( ReturnRK ( r ) > 1.0e-6  );

    of.close();

    return r;   
}