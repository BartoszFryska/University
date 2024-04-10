#include "SprzezonyGradientDoRURL.h"
#include "NajwiekszySpadekDoRURL.h"
#include "GeneralPurpouse.h"

vector < double> MethodCongulatedGradient ( vector <double> &x, vector <double> &b, vector < vector < double > > matrix_A, std::string filename ) {

    ofstream of ( "../" + filename );
    ofstream wykres1 ( "../doWykresow/wyk_rk_" + filename );
    ofstream wykres2 ( "../doWykresow/wyk_xk_" + filename );

    const int n = x.size();

    vector < double > r = SubctractVector ( b, MultiplySquareMatrixByAVector ( matrix_A, x ) );
    vector < double > v = r;

    vector < double > xk;
    vector < double > rk;
    vector < double > vk;

    double alpha, beta;

    int k = 0;

    while ( ReturnEuqlidesNorm ( r ) > 1.0e-6  ) {

        k ++;

        alpha = ReturnVectorTransponatedMultipliedByAVector ( r, r );
        alpha /= ReturnVectorTransponatedMultipliedByAVector ( v, MultiplySquareMatrixByAVector ( matrix_A, v ) );

        xk = x;
        x = AddVector ( x, MultiplyVectorByAScalar ( v, alpha ) );

        rk = r;
        r = SubctractVector ( r, MultiplyVectorByAScalar( MultiplySquareMatrixByAVector ( matrix_A, v ), alpha ) );

        beta = ReturnVectorTransponatedMultipliedByAVector ( r, r );
        beta /= ReturnVectorTransponatedMultipliedByAVector ( rk, rk );

        vk = v;
        v = AddVector ( r, MultiplyVectorByAScalar ( v, beta ) );

        // wypisywanie

        of << "\nIteracja " << k << '\n';
        of << "Norma eukidesowa ||rk|| = " << ReturnEuqlidesNorm ( rk ) << '\n';
        of << "Wartosc alpha k = " << alpha << '\n';
        of << "Wartosc beta k = " << beta << '\n';
        of << "Norma eukilidesowa ||xk|| = " << ReturnEuqlidesNorm ( xk ) << '\n';

        wykres1 <<  ReturnEuqlidesNorm ( rk ) << ( (ReturnEuqlidesNorm ( r ) > 1.0e-6) ? " " : "" );
        wykres2 <<  ReturnEuqlidesNorm ( xk ) << ( (ReturnEuqlidesNorm ( r ) > 1.0e-6) ? " " : "" );
    }

    of.close();
    wykres1.close();
    wykres2.close();

    return r;   
}