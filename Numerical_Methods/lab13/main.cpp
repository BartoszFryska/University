#include "function.h"
#include "Matrix.h"

using namespace std;

int main () {

    functionOne funOne;
    functionTwo funTwo;
    functionThree funThree;

    ofstream of;

    of.open ("../funOneDifferences.txt");
    double c1a = funOne.countIntegralFunctionAnalitic ( 0, 2 );
    
    for ( int N = 2; N <= 20; N ++ ) {
        of << abs ( funOne.countIntegralFunction( 0, 2, N ) - c1a ) << ' '; 
    }
    of.close();

    of.open ("../funTwoDifferencesK5.txt");
    double c2a_5 = funTwo.countIntegralFunctionAnalitic ( 5 );
    for ( int N = 2; N <= 20; N ++ ) {
        of << abs ( funTwo.countIntegralFunction(N, 5) - c2a_5 ) << ' '; 
    }
    of.close();

    of.open ("../funTwoDifferencesK10.txt");
    double c2a_10 = funTwo.countIntegralFunctionAnalitic ( 10 );
    for ( int N = 2; N <= 20; N ++ ) {
        of << abs ( funTwo.countIntegralFunction(N, 10) - c2a_10 ) << ' '; 
    }
    of.close();

    of.open ("../funThreeDifferences.txt");
    double c3dok = funThree.returnIntegralFunctionAnalitic ( );
    for ( int N = 2; N <= 15; N ++ ) {
        of << abs ( funThree.countIntegralFunction(N) - c3dok ) << ' '; 
    }

    of.close();

    system ( "python3 ../doWykresow/graph.py");
}
