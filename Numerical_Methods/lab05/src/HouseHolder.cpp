#include "HouseHolder.h"
#include <numeric>

template<typename Iter_T>
long double vectorNorm(Iter_T first, Iter_T last) {
  return sqrt(inner_product(first, last, first, 0.0L));
}


vector < double > TakeX ( vector < vector <double > > matrix_A, const int ncol ) {

    const int n = matrix_A.size();
    vector < double > x;

    for ( int i = 0; i < n; i ++ ) {

        if ( i < ncol ) {

            x.push_back (0);
            continue;
        }
        x.push_back ( matrix_A [ i ] [ ncol ] );
    }

    return x;
}

vector < double > ReturnE ( const int n, const int i ) {

    vector < double > e;

    for ( int j = 0; j < n; j ++ ) {

        if ( j != i ) {

            e.push_back (0);
            continue;
        }
        
        e.push_back (1.0);
    }

    return e;
}

void CountryRoadsTakeMeHome ( vector < vector <double > > &matrix_A, vector < vector <double > > &matrix_R, vector < vector <double > > &matrix_Q, const int n ) {

    vector < double > x;
    vector < double > u;
    vector < double > v;
    vector < vector < double > > VVt;
    vector < vector < double > > Qt;
    
    for ( int i = 0; i < n - 1; i ++ ) {

        x = TakeX ( matrix_R, i );
        u = SubctractVector ( x , MultiplyVectorByAScalar ( ReturnE (n, i), vectorNorm ( x.begin(), x.end() )));
        v = MultiplyVectorByAScalar ( u, (double) 1.0 / vectorNorm ( u.begin(), u.end() )  );

        cout << "v" + to_string ( i ) + ":\n";
        for ( auto a : v ) {

            cout << a << '\n';
        }
        cout << '\n';

        VVt = multiplyVectorsToFormAMatrix ( v, v );

        Qt = substractMatrix ( matrixOfOnes ( n ), multiplyMatrixByAScalar ( VVt, 2.0 ));

        matrix_Q = MultiplyMatrices ( Qt , matrix_Q);
        matrix_R = MultiplyMatrices ( Qt, matrix_R );
    }


}