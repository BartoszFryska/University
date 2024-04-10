#include "GaussMethod.h"

void TriangulateSquareMatrix ( vector < vector <double> > &matrix, vector < double > &y, const int n ){

    double  multiplier = 0;

    for ( int current_row = 0; current_row < n; current_row ++ ) {

        for ( int row_to_delete_from = current_row + 1; row_to_delete_from < n; row_to_delete_from ++ ) {

            multiplier = matrix [ row_to_delete_from ] [ current_row ] / matrix [ current_row ] [ current_row ];

            matrix [ row_to_delete_from ] [ current_row ] = 0.0000000;

            for ( int col = current_row + 1; col < n; col ++ ) {

                matrix [ row_to_delete_from ] [ col ] -= multiplier * matrix [ current_row ] [ col ]; 
            }
            y [ row_to_delete_from ] -= ( multiplier ) * y [ current_row ];
        }
    }
}

vector < double > CalculateCInGauss (  vector < vector <double> > matrix_A, vector <double> matrix_Y,  const int n ) {

    vector < double > c_ForGauss;

    double temp = 0;

    for ( int row = n - 1; row >= 0; row -- ) {

        temp = matrix_Y [ row ];

        for ( int col = n - 1; col > row; col -- ) {

            temp -= matrix_A [ row ] [ col ] * c_ForGauss [ n - 1 - col ];
        }

        temp /= matrix_A [ row ] [ row ];

        c_ForGauss.push_back ( temp );
    }

    vector <double> temp2;

    for ( int i = n - 1; i >= 0; i -- ) {

        temp2.push_back ( c_ForGauss [ i ]);
    }

    return temp2;
}

vector < double > CalculateCUsingGauss ( vector < vector <double> > matrix_A, vector <double> matrix_Y,  const int n ) {

    TriangulateSquareMatrix ( matrix_A, matrix_Y, n );

    return CalculateCInGauss ( matrix_A, matrix_Y, n );
}