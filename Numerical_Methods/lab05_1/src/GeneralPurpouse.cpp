#include "GeneralPurpouse.h"

Matrix GenerateMatrixA ( const int n) {

    Matrix matrix_A(n);

    const double KCH = 592;
    const double  KCC = 1580;
    const double  MH = 1;
    const double  MC = 12;
    const double amu = 1.6605e-27;

    matrix_A [ 0 ] [ 0 ] = KCH / MH;
    matrix_A [ 0 ] [ 1 ] = (- KCH) / MH;
     matrix_A [ 1 ] [ 0 ] = (- KCH) / MC;
     matrix_A [ 1 ] [ 1 ] = ( KCH + KCC ) / MC;
     matrix_A [ 1 ] [ 2 ] = (- KCC) / MC;
     matrix_A [ 2 ] [ 1 ] = (- KCC) / MC;
     matrix_A [ 2 ] [ 2 ] = matrix_A [ 1 ] [ 1 ];
    matrix_A [ 3 ] [ 2 ] = matrix_A [ 0 ] [ 1 ];
    matrix_A [ 2 ] [ 3 ] = matrix_A [ 1 ] [ 0 ];
     matrix_A [ 3 ] [ 3 ] = matrix_A [ 0 ] [ 0 ];

    return matrix_A;
}
