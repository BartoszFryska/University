#include "MetodaBisekcji.h"
#include "NajwiekszySpadekDoRURL.h"
#include <numeric>

template<typename Iter_T>
long double vectorNorm(Iter_T first, Iter_T last) {
  return sqrt(inner_product(first, last, first, 0.0L));
}


double CountLambda ( double a, double b ) {

    return ((double)( a + b ) / 2);
}

double GetS ( vector < vector < double > > matrix_H ) {

    double sum_temp = 0.0;
    double sum_max = 0.0;
    const int n = matrix_H.size();

    for ( int i = 0; i < n; i ++ ) {

        for ( int j = 0; j < n; j ++ ) {

            sum_temp += matrix_H [ i ] [ j ];
        }

        sum_max = max ( sum_max, sum_temp );
        sum_temp = 0.0;
    }

    return sum_max;
}

vector < double > CountP ( vector < vector < double > > matrix_H, const int n, const double lambda ) {

    double previous_last_p = 1.0;
    double current_p = 0.0;

    vector < double > p;

    p.push_back ( 1.0 );

    double last_p = matrix_H [ 0 ] [ 0 ] - lambda ;
    p.push_back  ( last_p );

    for ( int i = 1; i < n; i ++ ) {

        current_p = ( matrix_H [ i ] [ i ] - lambda ) * last_p;
        current_p -= matrix_H [ i - 1 ] [ i ] * matrix_H [ i - 1 ] [ i ] * previous_last_p;

        p.push_back ( current_p );

        previous_last_p = last_p;
        last_p = current_p;
        current_p = 0.0;
    }

  //  cout << lambda << '\n';
    cout << "p: ";
    for ( auto v : p ) {

        cout << v << " ";
    }
    cout << '\n' << '\n';
    return p;
}

double returnOwnValue ( vector < vector < double > > matrix_H, int N, int IT_MAX , double lambda, double a, double b ) {

    int chhanges = 0;

    for ( int i = 0; i < IT_MAX; i ++ ) {

        lambda = CountLambda( a, b );
        chhanges = returnHowManytimsSignChanged( matrix_H, matrix_H.size(), lambda );

        if( chhanges <= N ) {
            
            a = lambda;
            continue;
        }

        b = lambda;
    }

    return lambda;
}

vector < double > ReturnX( vector < vector < double > > matrix_H, double a, double b, double lambda ) {

    const int n = matrix_H.size();
    const int IT_MAX = 50;

    const double S = a;

    vector < double > X;

    double x;

    vector < double > P;

    for ( int I = 0; I < 5; I ++ ) {

        x = returnOwnValue ( matrix_H, I, IT_MAX, lambda, -S, S );

        X.push_back ( x );
    }

    return X;
}

vector < double > ownVectorX ( const double x, vector < vector < double > > matrix_H ) {

    vector < double > ownX;

    double x1 = 1;
    double x2 = ( x - matrix_H[0][0] ) / matrix_H[0][1];
    double x3;

    ownX.push_back( x1 );
    ownX.push_back( x2 );

    for( int i = 1; i < matrix_H.size()-1; i++ ){

        x3 = ( ( x - matrix_H[i][i] ) * x2 - matrix_H[i-1][i-2] * x1 ) / matrix_H[i][i+1];
        ownX.push_back( x3 );
        x1 = x2;
        x2 = x3;
    }
     double norm = vectorNorm( ownX.begin(), ownX.end() );
    for( int i = 0; i < ownX.size(); i++ ) ownX[i] = ownX[i] / ( double ) norm;

    return ownX;
}

int returnHowManytimsSignChanged ( vector < vector < double > > matrix_H, const int n, const double lambda  ) {

    double previous_last_p = 1;
    double last_p = matrix_H [0][0] - lambda;
    double current_p;

    int number_of_signs_changed = 0;

    if( ( ( previous_last_p < 0 ) && ( last_p > 0 ) ) || ( ( previous_last_p > 0 ) && ( last_p < 0 ) ) )
        number_of_signs_changed++;

    for( int i = 1; i < n; i++ ){

        current_p = ( ( matrix_H [ i ] [ i ] - lambda ) * last_p ) - ( previous_last_p * pow( matrix_H [ i - 1 ] [ i ], 2 ) );

        if( ( ( last_p < 0 ) && ( current_p > 0 ) ) || ( ( last_p > 0 ) && ( current_p < 0 ) ) )
            number_of_signs_changed++;

        previous_last_p = last_p;
        last_p = current_p;
    }

    return number_of_signs_changed;
}