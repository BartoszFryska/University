#include "HouseHolder.h"
#include <numeric>

void ZeroLargestThanI ( Matrix &x, const int i ) {

    for ( int j = 0; j < i; j ++ ) {

        x [ j ] [ 0 ] = 0;
    }
}

double returnVectorNorm ( Matrix v ) {

    if ( v.Columns() != 1 ) {

        return 0;
    }

    double n = (v.transponate() * v) [0] [0];

    return sqrt ( n );
}

Matrix ReturnE ( const int n, const int i ) {

    Matrix e;
    e.CreateIdentityMatrix(n);

    return e.returnColumn(i);
}

void CountryRoadsTakeMeHome ( Matrix &matrix_A, Matrix &matrix_R, Matrix &matrix_Q, const int n ) {

    Matrix x ( n, 1 );
    Matrix u ( n, 1 );
    Matrix v ( n, 1 );
    Matrix Qt;
    
    for ( int i = 0; i < n - 1; i ++ ) {

        x = matrix_R.returnColumn( i );
        ZeroLargestThanI ( x, i );
        u = x  - (ReturnE (n, i) * returnVectorNorm(x) );
        v =  u * (1.0 / returnVectorNorm ( u ) );

       // v.WriteOutOnCout("\nv"+to_string(i));

        Matrix VVt =  v * v.transponate();

        Matrix I;
        I.CreateIdentityMatrix(n);

        Qt =  I -  VVt * 2.0;

        matrix_Q = Qt * matrix_Q;
        matrix_R = Qt * matrix_R ;
    }

    matrix_Q = matrix_Q.transponate();
}

void FindMatrixH ( Matrix &matrix_H, Matrix & matrix_P, const int n, const int IT ) {

    for ( int i = 0; i < IT; i ++ ) {

        Matrix matrix_R = matrix_H;
        Matrix matrix_Q;
        matrix_Q.CreateIdentityMatrix(4);

        CountryRoadsTakeMeHome ( matrix_H, matrix_R, matrix_Q, 4 );

        matrix_H = matrix_R * matrix_Q;
        matrix_P = matrix_P * matrix_Q;
    }
}

void CreateIthOwnVector ( Matrix &X, Matrix matrix_H, const int i ) {

    for ( int j = 3; j >= 0; j -- ) {

        if ( j > i ) {

            X [ j ] [ 0 ] = 0;

            continue;
        }

        if ( j == i ) {

            X [ j ] [ 0 ] = 1.0;

            continue;
        }

        double sum = 0;

        for ( int k = j+1; k <= i; k ++ ) {

            sum += matrix_H [ j ] [ k ] * X [ k ] [ 0 ];
        }

        X [ j ] [ 0 ] = (-1.0) * sum / ( matrix_H [ j ] [ j ] - matrix_H [ i ] [ i ] );
    }
}