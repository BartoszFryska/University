#include "function.h"
#include "Matrix.h"

using namespace std;

int main () {

    vector <double> ro = {-0.75, 1.75};
    vector <double> rk1 = countVectorR ( ro, 1.0e-2 );
    vector <double> rk2 = countVectorR ( ro, 1.0e-3 );

    system ("python3 ../doWykresow/graph2.py");
}
