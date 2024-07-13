#include "function.h"

double silnia(unsigned int n) {
   if(n>1)
    return (double) n*silnia(n-1);
  else
    return 1.0;
}

double fRand(double fMin, double fMax){

    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}


double functionOne::countFunction( double x, double k, double m ) {

    return pow(x,m)*sin(k*x);
}

double functionOne::countIntegralFunction ( double m, double k, double a, double b ) {

    const int N = 30;

    double sumA = 0.;
    double sumB = 0.;
    double temp = 0.0;
    double sumC = 0.0;

    ofstream of ( "../fMetIter_" + std::to_string(m).substr(0,1) + "_" + std::to_string(k).substr(0,1) + ".txt" );

    for ( int i = 0; i < N; i ++ ) {

        temp = (double) pow(k*a, 2*i + m + 2);
        temp /= (double) pow (k,m+1);
        temp /= (double) silnia( 2*i + 1);
        temp /=  (double) (2*i + m + 2);
        sumA = (double) temp * pow ( -1, i );

        temp = 0.0;
        temp = (double) pow( k*b , 2*i + m + 2);
        temp /= (double) pow (k, m + 1);
        temp /= (double) silnia( 2*i + 1);
        temp /= (double) (2*i + m + 2);
        sumB = (double) temp * pow ( -1, i );

        of << sumB - sumA << "\n";
        sumC += sumB - sumA;
    }

    of.close();

    return sumC;
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