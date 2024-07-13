#include "Simpson.h"

double returnX ( int k, double h, double a ) {

    return k*h + a;
}

double Simpson::countCalka ( double a, double b, function *f, int N, double m, double k ) {

    double end = 0;

    double h = (b-a) / (N-1);

    for ( int n = 1; n <= (N-1)/2; n ++ ) {

        end += 1. * f->countFunction ( returnX ( 2 * n - 2, h, a ), k, m );
        end += 4. * f->countFunction ( returnX ( 2 * n - 1, h, a ), k, m );
        end += 1. * f->countFunction ( returnX ( 2 * n - 0, h, a ), k, m );
    }

    end *= h;
    end /= 3.;

    return end;
}