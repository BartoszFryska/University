#include "LUMethod.h"

void GenerateMatrixesLU ( vector < vector < float > > matrix_A, vector < vector < float > > & matrix_L, vector < vector < float > > & matrix_U, const int n ) {

    float temp = 0;

    for ( int i = 0; i < n; i ++ ) {

        for ( int j = i; j < n; j ++ ) {

            for ( int k = 0; k <= i - 1; k ++ ) {

                temp += matrix_L [ i ] [ k ] * matrix_U [ k ] [ j ];
            }

            matrix_U [ i ] [ j ] = matrix_A [ i ] [ j ] - temp;

            temp = 0;
        }

        for ( int j = i + 1; j < n; j ++ ) {

            for ( int k = 0; k <= i - 1; k ++ ) {

                temp += matrix_L [ j ] [ k ] * matrix_U [ k ] [ i ];
            }

            matrix_L [ j ] [ i ] = matrix_A [ j ] [ i ] - temp;
            matrix_L [ j ] [ i ] /= matrix_U [ i ] [ i ];

            temp = 0;
        }
    }

    for ( int i = 0; i < n; i ++ ) {

            matrix_L [ i ] [ i ] = 1;
        }
}

vector < vector < float > > MatrixZero ( const int n ) {

    vector < vector < float > > returning;

    vector < float > temp;

    for ( int i = 0; i < n; i ++ ) {

        temp.push_back ( 0 );
    }

    for ( int i = 0; i < n; i ++ ) {

        returning.push_back ( temp );
    }

    return returning;
}

vector < float > generateSingleMatrixWithOne1 ( const int n, const int n_th_position ) {

    vector < float > returning;

    for ( int i = 0; i < n; i ++ ) {

        if ( n_th_position == i ) {

            returning.push_back ( 1.0 );
            continue;
        }

        returning.push_back ( 0.0 );
    }

    return returning;
}

float WriteOutDiagonalElementsOfAnUMatrixAndDet_UAndReturnIt ( vector < vector < float > > matrix_U, string filename ) {

    const int n = matrix_U.size();

    string filename2 = "../" + filename;

    ofstream of;

    of.open ( filename2 );

    float det_U = 1.0;

    of << "Wartości na diagonali macierzy U : ";

    for ( int x = 0; x < n; x ++ ) {

        det_U *= matrix_U [ x ] [ x ];

        of << matrix_U [ x ] [ x ] << " ";
    }

    of << '\n';

    of << "Wyznacznik macierzy A : " << det_U << '\n';

    of.close();

    return det_U;
}