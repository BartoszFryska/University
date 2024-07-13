#include "function.h"
#include "Matrix.h"
#include <float.h>
#include <algorithm>

using namespace std;

int main () {

    double K = 12;
    int N_k = pow( 2., K );
    double tmin = 0;
    double tmax = 3*Tc;

    double dt = (double) (tmax - tmin) / N_k;

    double fone_val [ N_k ];
    functionOne fone;

    double foneVar_val [ 2 * N_k ];
    functionOneVar foneVar;

    double g1_val [ 2 * N_k ];
    double g2_val [ 2 * N_k ];
    functionGauss g;

    for ( int i = 0; i < N_k; i++ ) {
		double  x = dt * ( i );

		fone_val [i] = fone.countFunction(x);
        foneVar_val [ 2 * i + 1 ] = foneVar.countFunction(x);

		g1_val [ 2 * i + 1 ] = g2_val [ 2 * i + 1 ] = g.countFunction( x ) ;

		foneVar_val [ 2 * i ] = 0.;
        g1_val [ 2 * i ] = 0.;
        g2_val [ 2 * i ] = 0.;
	}

    ofstream of ( "../fone_val.txt" );
    if ( !of.is_open() ) {cerr << "Failed to open a file"; return 1;}
    for ( int i = 0; i < N_k; i ++ ) of << fone_val [ i ] << ' ';
    of.close();

    of.open ( "../foneVar_val.txt" );
    if ( !of.is_open() ) {cerr << "Failed to open a file"; return 1;}
    for ( int i = 0; i < N_k; i ++ ) of << foneVar_val [ 2 * i + 1 ] << ' ';
    of.close();

    FFT::count( foneVar_val, N_k, +1 );
	FFT::count( g1_val, N_k, +1 );
	FFT::count( g2_val, N_k, -1 );

    vector <double> g_val;
    for ( int i = 1; i <= 2 * N_k; i++ ) g_val.push_back ( g1_val[i] + g2_val[i] );

    for ( int i = 1; i <= N_k; i++ ) {
		double a1 = foneVar_val[2 * i - 1];
		double a2 = foneVar_val[2 * i];
		double b1 = g_val[2 * i - 1];
		double b2 = g_val[2 * i];

		foneVar_val[2 * i - 1] = a1 * b1 - a2 * b2;
		foneVar_val[2 * i] = a1 * b2 + a2 * b1;
	}

    FFT::count( foneVar_val, N_k, -1 );

    double f_max = -1.0e30;
    for ( int i = 1; i < N_k; i++ ) if ( foneVar_val[2 * i - 1] > f_max ) f_max = foneVar_val[2 * i - 1];
	for ( int i = 1; i < 2 * N_k; i++ ) foneVar_val[i] = foneVar_val[i] * 2.5 / f_max;
    
    of.open ( "../foneVarFourr_val.txt" );
    if ( !of.is_open() ) {cerr << "Failed to open a file"; return 1;}
    for ( int i = 0; i < N_k; i ++ ) of << foneVar_val [ 2*i + 1 ] << ' ';
    of.close();

    system ("python3 ../doWykresow/graph2.py");
}
