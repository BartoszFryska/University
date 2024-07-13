#include "function.h"

int main () {

    function fun; //w przedziale <a, b>

    double a = 0.5;
    double b = 2.4;

    std::ofstream of ( "../doWykresow/function.txt" );
    fun.writeOutFunctionOnOfStream ( &of, 0.0001, a, b );
    of.close();
    system ( "python3 ../doWykresow/graph.py");

    double x01 =  fun.findZeroPlace ( a );

    double x02 = fun.findZeroPlace ( b );

    std::cout << "u(x):\n\n";

    functionU funU;

    double xu01 = funU.findZeroPlaceForU ( 0.5 );
    double xu02 = funU.findZeroPlaceForU ( b );
}