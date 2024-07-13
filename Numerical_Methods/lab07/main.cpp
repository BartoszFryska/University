#include "function.h"
#include "Matrix.h"

using namespace std;

int main () {

    function fun; //w przedziale <a, b>

    double a = -5;
    double b = 5;

    ofstream ofx ( "../doWykresow/x_values.txt" );
    ofstream ofy ( "../doWykresow/y_values.txt" );

    for ( double i = a; i <= b; i += 0.001 ) {

        ofx << i << " ";
        ofy << fun.countFunction ( i  ) << " ";
    }

    ofx.close();
    ofy.close();

    // n = 5

    int n = 5;

    vector < double > pointsx;
    for ( int i = 0; i <= n; i ++ ) {

        pointsx.push_back ( a + ((double) (b - a) / n) * i );
    }
    vector < double > pointsy;
    for ( int i = 0; i <= n; i ++ ) {

        pointsy.push_back ( fun.countFunction (pointsx [i]) );
    }
    endFunction end1 ( n );

    ofy.open ( "../doWykresow/y5_values.txt" );

   for ( double i = a; i <= b; i += 0.001 ) {

        ofy << end1.countFunctionEnd(pointsx,pointsy,i) << " ";
    }

    ofy.close();

    // n = 10
    
    n = 10;

    pointsx.clear();
    for ( int i = 0; i <= n; i ++ ) {

        pointsx.push_back ( a + ((double) (b - a) / n) * i );
    }
    pointsy.clear();
    for ( int i = 0; i <= n; i ++ ) {

        pointsy.push_back ( fun.countFunction (pointsx [i]) );
    }
    endFunction end2 ( n );

    ofy.open ( "../doWykresow/y10_values.txt" );

   for ( double i = a; i <= b; i += 0.001 ) {

        ofy << end2.countFunctionEnd(pointsx,pointsy,i) << " ";
    }

    ofy.close();

    // n = 15
    
    n = 15;

    pointsx.clear();
    for ( int i = 0; i <= n; i ++ ) {

        pointsx.push_back ( a + ((double) (b - a) / n) * i );
    }
    pointsy.clear();
    for ( int i = 0; i <= n; i ++ ) {

        pointsy.push_back ( fun.countFunction (pointsx [i]) );
    }
    endFunction end3 ( n );

    ofy.open ( "../doWykresow/y15_values.txt" );

   for ( double i = a; i <= b; i += 0.001 ) {

        ofy << end3.countFunctionEnd(pointsx,pointsy,i) << " ";
    }

    ofy.close();

    // n = 20
    
    n = 20;

    pointsx.clear();
    for ( int i = 0; i <= n; i ++ ) {

        pointsx.push_back ( a + ((double) (b - a) / n) * i );
    }
    pointsy.clear();
    for ( int i = 0; i <= n; i ++ ) {

        pointsy.push_back ( fun.countFunction (pointsx [i]) );
    }
    endFunction end4 ( n );

    ofy.open ( "../doWykresow/y20_values.txt" );

   for ( double i = a; i <= b; i += 0.001 ) {

        ofy << end4.countFunctionEnd(pointsx,pointsy,i) << " ";
    }

    ofy.close();

    ///////////////////////// czybyszew zera 

    // n = 5

    n = 5;

    pointsx.clear();
    for ( int i = 0; i <= n; i ++ ) {

        pointsx.push_back ( 0.5 * ( ( b - a ) * cos ( M_PI * ( 2. * i + 1  ) / ( 2. * n + 2 ) ) + b + a ) );
    }
    pointsy.clear();
    for ( int i = 0; i <= n; i ++ ) {

        pointsy.push_back ( fun.countFunction (pointsx [i]) );
    }
    endFunction end5 ( n );

    ofy.open ( "../doWykresow/y5_values_czyby.txt" );

   for ( double i = a; i <= b; i += 0.001 ) {

        ofy << end5.countFunctionEnd(pointsx,pointsy,i) << " ";
    }

    ofy.close();

    // n = 10
    
    n = 10;

    pointsx.clear();
    for ( int i = 0; i <= n; i ++ ) {

        pointsx.push_back ( 0.5 * ( ( b - a ) * cos ( M_PI * ( 2. * i + 1  ) / ( 2. * n + 2 ) ) + b + a ) );
    }
    pointsy.clear();
    for ( int i = 0; i <= n; i ++ ) {

        pointsy.push_back ( fun.countFunction (pointsx [i]) );
    }
    endFunction end6 ( n );

    ofy.open ( "../doWykresow/y10_values_czyby.txt" );

   for ( double i = a; i <= b; i += 0.001 ) {

        ofy << end6.countFunctionEnd(pointsx,pointsy,i) << " ";
    }

    ofy.close();

    // n = 15
    
    n = 15;

    pointsx.clear();
    for ( int i = 0; i <= n; i ++ ) {

        pointsx.push_back ( 0.5 * ( ( b - a ) * cos ( M_PI * ( 2. * i + 1  ) / ( 2. * n + 2 ) ) + b + a ) );
    }
    pointsy.clear();
    for ( int i = 0; i <= n; i ++ ) {

        pointsy.push_back ( fun.countFunction (pointsx [i]) );
    }
    endFunction end7 ( n );

    ofy.open ( "../doWykresow/y15_values_czyby.txt" );

   for ( double i = a; i <= b; i += 0.001 ) {

        ofy << end7.countFunctionEnd(pointsx,pointsy,i) << " ";
    }

    ofy.close();

    // n = 20
    
    n = 20;

    pointsx.clear();
    for ( int i = 0; i <= n; i ++ ) {

        pointsx.push_back ( 0.5 * ( ( b - a ) * cos ( M_PI * ( 2. * i + 1  ) / ( 2. * n + 2 ) ) + b + a ) );
    }
    pointsy.clear();
    for ( int i = 0; i <= n; i ++ ) {

        pointsy.push_back ( fun.countFunction (pointsx [i]) );
    }
    endFunction end8 ( n );

    ofy.open ( "../doWykresow/y20_values_czyby.txt" );

   for ( double i = a; i <= b; i += 0.001 ) {

        ofy << end8.countFunctionEnd(pointsx,pointsy,i) << " ";
    }

    ofy.close();

    system ( "python3 ../doWykresow/graph.py");
}