#include "NajwiekszySpadekDoRURL.h"
#include "GeneralPurpouse.h"

vector < double > SubctractVector ( vector <double> a, vector < double > b ) {

    const int n1 = a.size();
    const int n2 = b.size();

    if ( n1 != n2 ) {

        return a;
    }

    for ( int i = 0; i < n1; i ++ ) {

        a [ i ] -= b [ i ];
    }

    return a;
}

vector < double > AddVector ( vector <double> a, vector < double > b ) {

    const int n1 = a.size();
    const int n2 = b.size();

    if ( n1 != n2 ) {

        return a;
    }

    for ( int i = 0; i < n1; i ++ ) {

        a [ i ] += b [ i ];
    }

    return a;
}

vector < double > MultiplyVectorByAScalar ( vector <double> a, const double number) {

    const int n = a.size();

    for ( int i = 0; i < n; i ++ ) {

        a [ i ] *= number;
    }

    return a;
}

double ReturnEuqlidesNorm ( vector < double > r ) {

    double number = 0.0;

    const int n = r.size();

    for ( int i = 0; i < n; i ++ ) {

        number += r [ i ] * r [ i ];
    }

    return sqrt ( number );
}

double ReturnVectorTransponatedMultipliedByAVector ( vector < double > toTransponate, vector < double > otherVector ) {

    double alpha = 0.0;

    const int n = toTransponate.size();

    for ( int i = 0; i < n; i ++ ) {

        alpha += toTransponate [ i ] * otherVector [ i ];
    }

    return alpha;
}

vector < double> FindLargestFallFirstValue ( vector <double> &x, vector <double> &b, vector < vector < double > > matrix_A, std::string filename ) {

    ofstream of ( "../" + filename );
    ofstream wykres1 ( "../doWykresow/wyk_rk_" + filename );
    ofstream wykres2 ( "../doWykresow/wyk_xk_" + filename );

    const int n = x.size();

    vector < double > r = VectorOfZeroes ( n );
    vector < double > xk;
    double alpha;

    int k = 0;

    do {
        r.clear();
        k ++;

        r = SubctractVector ( b, MultiplySquareMatrixByAVector ( matrix_A, x ));

        alpha = ReturnVectorTransponatedMultipliedByAVector ( r, r );

        alpha /= ReturnVectorTransponatedMultipliedByAVector ( r, MultiplySquareMatrixByAVector ( matrix_A, r ) );

        xk = x;

        x = AddVector ( x, MultiplyVectorByAScalar ( r, alpha ) );

        // wypisywanie

        of << "\nIteracja " << k << '\n';
        of << "Norma eukidesowa ||rk|| = " << ReturnEuqlidesNorm ( r ) << '\n';
        of << "Wartosc alpha k = " << alpha << '\n';
        of << "Norma eukilidesowa ||xk|| = " << ReturnEuqlidesNorm ( xk ) << '\n';

        wykres1 <<  ReturnEuqlidesNorm ( r ) << ( (ReturnEuqlidesNorm ( r ) > 1.0e-6) ? " " : "" );
        wykres2 <<  ReturnEuqlidesNorm ( xk ) << ( (ReturnEuqlidesNorm ( r ) > 1.0e-6) ? " " : "" );
        //

    } while ( ReturnEuqlidesNorm ( r ) > 1.0e-6  );

    of.close();
    wykres1.close();
    wykres2.close();

    return r;   
}

vector < double> FindLargestFallSecondValue ( vector <double> &x, vector <double> &b, vector < vector < double > > matrix_A, std::string filename ) {

    ofstream of ( "../" + filename );
    
    const int n = x.size();

    vector < double > r = VectorOfZeroes ( n );
    vector < double > xk;
    double alpha;

    int k = 0;

    do {
        r.clear();
        k ++;

        r = SubctractVector ( b, MultiplySquareMatrixByAVector ( matrix_A, x ));

        alpha = ReturnVectorTransponatedMultipliedByAVector ( r, r );

        alpha /= ReturnVectorTransponatedMultipliedByAVector ( r, MultiplySquareMatrixByAVector ( matrix_A, r ) );

        xk = x;

        x = AddVector ( x, MultiplyVectorByAScalar ( r, alpha ) );

        // wypisywanie

        of << "\nIteracja " << k << '\n';
        of << "Norma eukidesowa ||rk|| = " << ReturnEuqlidesNorm ( r ) << '\n';
        of << "Wartosc alpha k = " << alpha << '\n';
        of << "Norma eukilidesowa ||xk|| = " << ReturnEuqlidesNorm ( xk ) << '\n';

        //

    } while ( ReturnEuqlidesNorm ( r ) > 1.0e-3  );

    of.close();

    return r;   
}