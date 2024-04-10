#include "LUMethod.h"

void GenerateMatrixesLU ( vector < vector < double > > matrix_A, vector < vector < double > > & matrix_L, vector < vector < double > > & matrix_U, const int n ) {

    double temp = 0;

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

vector < vector < double > > MatrixZero ( const int n ) {

    vector < vector < double > > returning;

    vector < double > temp;

    for ( int i = 0; i < n; i ++ ) {

        temp.push_back ( 0 );
    }

    for ( int i = 0; i < n; i ++ ) {

        returning.push_back ( temp );
    }

    return returning;
}

vector < double > generateSingleMatrixWithOne1 ( const int n, const int n_th_position ) {

    vector < double > returning;

    for ( int i = 0; i < n; i ++ ) {

        if ( n_th_position == i ) {

            returning.push_back ( 1.0 );
            continue;
        }

        returning.push_back ( 0.0 );
    }

    return returning;
}

double WriteOutDiagonalElementsOfAnUMatrixAndDet_UAndReturnIt ( vector < vector < double > > matrix_U, string filename ) {

    const int n = matrix_U.size();

    string filename2 = "../" + filename;

    ofstream of;

    of.open ( filename2 );

    double det_U = 1.0;

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