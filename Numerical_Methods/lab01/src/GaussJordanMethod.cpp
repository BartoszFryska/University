#include "GaussJordanMethod.h"

void MakeTriangulatedMatrixADiagonalMatrix ( vector < vector <double> > &matrix, vector < double > &y, const int n ) {

    double  multiplier = 0;

    for ( int current_row = n-1; current_row >= 0; current_row -- ) {

        for ( int row_to_delete_from = current_row - 1; row_to_delete_from >= 0; row_to_delete_from -- ) {

            multiplier = matrix [ row_to_delete_from ] [ current_row ] / matrix [ current_row ] [ current_row ];

            matrix [ row_to_delete_from ] [ current_row ] = 0;

            y [ row_to_delete_from ] -= ( multiplier ) * y [ current_row ];
        }
    }

    for ( int row = 0; row < n; row ++ ) {

        y [ row ] /= matrix [ row ] [ row ];

        matrix [ row ] [ row ] = 1;
    }
}

void MakeMatrixADiagonalMatrix ( vector < vector <double> > &matrix, vector < double > &y, const int n ) {

    double  multiplier = 0;

    for ( int current_row = 0; current_row < n; current_row ++ ) {

        for ( int row_to_delete_from = 0; row_to_delete_from < n; row_to_delete_from ++ ) {

            if ( current_row == row_to_delete_from )
                continue;

            multiplier = matrix [ row_to_delete_from ] [ current_row ] / matrix [ current_row ] [ current_row ];

            matrix [ row_to_delete_from ] [ current_row ] = 0;

            y [ row_to_delete_from ] -= ( multiplier ) * y [ current_row ];
        }
    }

    for ( int row = 0; row < n; row ++ ) {

        y [ row ] /= matrix [ row ] [ row ];

        matrix [ row ] [ row ] = 1;
    }
}

vector < double > CalculateCInGaussJordan (  vector < vector <double> > matrix_A, vector <double> matrix_Y,  const int n ) {

    vector < double > c_ForGaussJordan;

    for ( int row = 0; row < n; row ++ ) {

        c_ForGaussJordan.push_back ( matrix_Y [ row ] / matrix_A [ row ] [ row ] );
    }

    return c_ForGaussJordan;
}