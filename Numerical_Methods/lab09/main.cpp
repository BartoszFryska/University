#include "function.h"
#include "Matrix.h"

using namespace std;

#define N 100

int main () {

    vector < double > x;
    x = countVectorX ( N );

    function1 fun_orig1;

    vector < double > y_original_1;
    for ( auto X : x ) {

        y_original_1.push_back ( fun_orig1.countFunction ( X ) );
    }

    function2 fun_orig2;

    vector < double > y_original_2;
    for ( auto X : x ) {

        y_original_2.push_back ( fun_orig2.countFunction ( X ) );
    }

    function3 fun_orig3;

    vector < double > y_original_3;
    for ( auto X : x ) {

        y_original_3.push_back ( fun_orig3.countFunction ( X ) );
    }

    function4 fun_orig4;

    vector < double > y_original_4;
    for ( auto X : x ) {

        y_original_4.push_back ( fun_orig4.countFunction ( X ) );
    }

    Function fun_new_1;
    fun_new_1.countAndCout_aj_bi(0, x, N, fun_orig1);

    vector < double > y_new_1;
    for ( auto X : x ) {

        y_new_1.push_back ( fun_new_1.countFunction ( X, x, N, fun_orig1 ) );
    }

    Function fun_new_2;
    fun_new_2.countAndCout_aj_bi(0, x, N, fun_orig2);

    vector < double > y_new_2;
    for ( auto X : x ) {

        y_new_2.push_back ( fun_new_2.countFunction ( X, x, N, fun_orig2 ) );
    }

    Function_WithoutDefaultMcMs fun_new_3_5_0;
    fun_new_3_5_0.countAndCout_aj_bi(0, x, N, fun_orig3, 5, 0);

    vector < double > y_new_3_5_0;
    for ( auto X : x ) {

        y_new_3_5_0.push_back ( fun_new_3_5_0.countFunction ( X, x, N, fun_orig3, 5, 0 ) );
    }

    Function_WithoutDefaultMcMs fun_new_3_5_5;
    fun_new_3_5_5.countAndCout_aj_bi(0, x, N, fun_orig3, 5, 5);

    vector < double > y_new_3_5_5;
    for ( auto X : x ) {

        y_new_3_5_5.push_back ( fun_new_3_5_5.countFunction ( X, x, N, fun_orig3, 5, 5 ) );
    }

    Function_WithoutDefaultMcMs fun_new_3_10_10;
    fun_new_3_10_10.countAndCout_aj_bi(0, x, N, fun_orig3, 10, 10);

    vector < double > y_new_3_10_10;
    for ( auto X : x ) {

        y_new_3_10_10.push_back ( fun_new_3_10_10.countFunction ( X, x, N, fun_orig3, 10, 10 ) );
    }

    Function_WithoutDefaultMcMs fun_new_4_5_5;
    fun_new_4_5_5.ofstreamAndCout_aj_bi(0, x, N, fun_orig4, 5, 5);

    vector < double > y_new_4_5_5;
    for ( auto X : x ) {

        y_new_4_5_5.push_back ( fun_new_4_5_5.countFunction ( X, x, N, fun_orig4, 5, 5 ) );
    }

    Function_WithoutDefaultMcMs fun_new_4_30_30;
    fun_new_4_30_30.ofstreamAndCout_aj_bi(0, x, N, fun_orig4, 30, 30);

    vector < double > y_new_4_30_30;
    for ( auto X : x ) {

        y_new_4_30_30.push_back ( fun_new_4_30_30.countFunction ( X, x, N, fun_orig4, 30, 30 ) );
    }

    ofstream of ( "../values1.txt");
    ofstreamVector ( &of, x, "wartoci x");
    ofstreamVector ( &of, y_original_1, "wartoci y orygnalne");
    ofstreamVector ( &of, y_new_1, "wartoci y nowe");
    of.close();

    of.open("../values2.txt");
    ofstreamVector ( &of, x, "wartoci x");
    ofstreamVector ( &of, y_original_2, "wartoci y orygnalne");
    ofstreamVector ( &of, y_new_2, "wartoci y nowe");
    of.close();

    of.open("../values3_5_0.txt");
    ofstreamVector ( &of, x, "wartoci x");
    ofstreamVector ( &of, y_original_3, "wartoci y orygnalne");
    ofstreamVector ( &of, y_new_3_5_0, "wartoci y nowe");
    of.close();

    of.open("../values3_5_0.txt");
    ofstreamVector ( &of, x, "wartoci x");
    ofstreamVector ( &of, y_original_3, "wartoci y orygnalne");
    ofstreamVector ( &of, y_new_3_5_0, "wartoci y nowe");
    of.close();

    of.open("../values3_5_5.txt");
    ofstreamVector ( &of, x, "wartoci x");
    ofstreamVector ( &of, y_original_3, "wartoci y orygnalne");
    ofstreamVector ( &of, y_new_3_5_5, "wartoci y nowe");
    of.close();

    of.open("../values3_10_10.txt");
    ofstreamVector ( &of, x, "wartoci x");
    ofstreamVector ( &of, y_original_3, "wartoci y orygnalne");
    ofstreamVector ( &of, y_new_3_10_10, "wartoci y nowe");
    of.close();

    of.open("../values4_5_5.txt");
    ofstreamVector ( &of, x, "wartoci x");
    ofstreamVector ( &of, y_original_4, "wartoci y orygnalne");
    ofstreamVector ( &of, y_new_4_5_5, "wartoci y nowe");
    of.close();

    of.open("../values4_30_30.txt");
    ofstreamVector ( &of, x, "wartoci x");
    ofstreamVector ( &of, y_original_4, "wartoci y orygnalne");
    ofstreamVector ( &of, y_new_4_30_30, "wartoci y nowe");
    of.close();

    system ( "python3 ../doWykresow/graph.py");
}
