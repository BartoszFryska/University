#include "function.h"

double fRand(double fMin, double fMax){

    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

double functionOne::countFunction ( double t ) {

    return sin( OMEGA * t ) + sin ( 2. * OMEGA * t ) + sin ( 3. * OMEGA * t );
}

double functionOneVar::countFunction ( double t ) {

    double var = fRand ( -1./2, 1./2 );

    return sin( OMEGA * t ) + sin ( 2. * OMEGA * t ) + sin ( 3. * OMEGA * t ) + var;
}

double functionGauss::countFunction ( double t ) {

    const double sigma = (double) Tc / 20.;

    return 1. / sigma / sqrt ( 2 * M_PI ) * exp ( -pow (t,2) / (2 * pow (sigma,2)) );
}

vector <double> removeTwo ( vector <double> one, vector <double> two ) { if ( one.size() != two.size()) {return one;}
    for ( int i = 0; i < one.size(); i ++ ) one [ i ] -= two [ i ];
    return one;
}

vector <double> addTwo ( vector <double> one, vector <double> two ){ if ( one.size() != two.size()) {return one;}
    for ( int i = 0; i < one.size(); i ++ ) one [ i ] += two [ i ];
    return one;
}

vector <double> multiplyTwo ( vector <double> one, vector <double> two ){ if ( one.size() != two.size()) {return one;}
    for ( int i = 0; i < one.size(); i ++ ) one [ i ] *= two [ i ];
    return one;
}

void FFT::count (double fun[], long nn, int isign) {

    unsigned long n,mmax,m,j,istep,i;
	double wtemp,wr,wpr,wpi,wi,theta;
	double tempr,tempi;

	n=nn << 1;
	j=1;
	for (i=1;i<n;i+=2) {
		if (j > i) {
			SWAP(fun[j],fun[i]);
			SWAP(fun[j+1],fun[i+1]);
		}
		m=n >> 1;
		while (m >= 2 && j > m) {
			j -= m;
			m >>= 1;
		}
		j += m;
	}
	mmax=2;
	while (n > mmax) {
		istep=mmax << 1;
		theta=isign*(6.28318530717959/mmax);
		wtemp=sin(0.5*theta);
		wpr = -2.0*wtemp*wtemp;
		wpi=sin(theta);
		wr=1.0;
		wi=0.0;
		for (m=1;m<mmax;m+=2) {
			for (i=m;i<=n;i+=istep) {
				j=i+mmax;
				tempr=wr*fun[j]-wi*fun[j+1];
				tempi=wr*fun[j+1]+wi*fun[j];
				fun[j]=fun[i]-tempr;
				fun[j+1]=fun[i+1]-tempi;
				fun[i] += tempr;
				fun[i+1] += tempi;
			}
			wr=(wtemp=wr)*wpr-wi*wpi+wr;
			wi=wi*wpr+wtemp*wpi+wi;
		}
		mmax=istep;
	}
}

/*double FFT::reverse ( double t, vector <double> ftt ) {

    double value = 0;
    auto kv = [] (int k, double tmx ) { return 2.*M_PI/tmx*k; };

    for ( int k = 0; k < N; k ++ ) {

        value += sin ( )
    } 
}*/

double lenVec ( vector <double> one ) {

    double sum = 0;

    for ( auto v : one ) {

        sum += v*v;
    }

    sum *= 10000;

    return sqrt(sum)/100;
}



void coutVector ( vector < double > v, std::string name ) {

    cout << name << ":\n";
    for ( auto V : v ) {

        cout << V << ' ';
    }

    cout << '\n';
}

void ofstreamVector ( ofstream *of, vector < double > v, std::string name ) {

    for ( auto V : v ) {

        *of << V << ' ';
    }
    *of << "\n";
}