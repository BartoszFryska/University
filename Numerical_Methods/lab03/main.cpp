#include "GeneralPurpouse.h"
#include "GaussMethod.h"
#include "GaussJordanMethod.h"
#include "LUMethod.h"
#include "NajwiekszySpadekDoRURL.h"
#include "SprzezonyGradientDoRURL.h"

using namespace std;

int main () {

    const int n = 1000;

    vector < vector < double > > matrix_A = GenerateMatrixA ( n );


    vector < double > vector_b11 = GenerateVectorBForFirstTask ( n );
    vector < double > vector_b12 = GenerateVectorBForFirstTask ( n );
    vector < double > vector_b21 = GenerateVectorBForFirstTask ( n );
    vector < double > vector_b22 = GenerateVectorBForFirstTask ( n );

    vector < double > vector_x11 = VectorOfZeroes ( n );
    vector < double > vector_x12 = VectorOfZeroes ( n );
    vector < double > vector_x21 = VectorOfZeroes ( n );
    for ( int i = 0; i < n; i ++ ) vector_x21 [ i ] = 1;
    vector < double > vector_x22 = VectorOfZeroes ( n );
    for ( int i = 0; i < n; i ++ ) vector_x22 [ i ] = 1;



    ofstream of ("../wynik.txt");

    WriteOutMatrixOnOfstream ( &of, matrix_A, "A" );
    WriteOutSingleMatrixVerticalyOnOfstream ( &of, vector_b11, "old b" );
    WriteOutSingleMatrixVerticalyOnOfstream ( &of, vector_x11, "old x1" );
    WriteOutSingleMatrixVerticalyOnOfstream ( &of, vector_x21, "old x2" );

    vector < double > vector_r11 = FindLargestFallFirstValue ( vector_x11, vector_b11, matrix_A, "iteracje11_FirstValueE-6.txt" );
    vector < double > vector_r21 = FindLargestFallFirstValue ( vector_x21, vector_b21, matrix_A, "iteracje21_FirstValueE-6.txt" );

    WriteOutSingleMatrixVerticalyOnOfstream ( &of, vector_r11, "For the first value (1.0e-6) and vector x1:\nnew r" );
    WriteOutSingleMatrixVerticalyOnOfstream ( &of, vector_b11, "new b" );
    WriteOutSingleMatrixVerticalyOnOfstream ( &of, vector_x11, "new x1" );

    WriteOutSingleMatrixVerticalyOnOfstream ( &of, vector_r21, "For the first value (1.0e-6) and vector x2:\new r" );
    WriteOutSingleMatrixVerticalyOnOfstream ( &of, vector_b21, "new b" );
    WriteOutSingleMatrixVerticalyOnOfstream ( &of, vector_x21, "new x2" );   

    vector < double > vector_r12 = FindLargestFallSecondValue ( vector_x12, vector_b12, matrix_A, "iteracje12_SecondValueE-3.txt" );
    vector < double > vector_r22 = FindLargestFallSecondValue ( vector_x22, vector_b22, matrix_A, "iteracje22_SecondValueE-3.txt" );

    WriteOutSingleMatrixVerticalyOnOfstream ( &of, vector_r12, "For the second value (1.0e-3) and vector x1:\nnew r" );
    WriteOutSingleMatrixVerticalyOnOfstream ( &of, vector_b12, "new b" );
    WriteOutSingleMatrixVerticalyOnOfstream ( &of, vector_x12, "new x1" );

    WriteOutSingleMatrixVerticalyOnOfstream ( &of, vector_r22, "For the second value (1.0e-3) and vector x2:\new r" );
    WriteOutSingleMatrixVerticalyOnOfstream ( &of, vector_b22, "new b" );
    WriteOutSingleMatrixVerticalyOnOfstream ( &of, vector_x22, "new x2" );   

    of.close();

    // second task 

    of.open( "../wynik2.txt" );

    vector < double > vector_b_second = GenerateVectorBForSecondTask ( n );
    vector < double > vector_x_second = VectorOfZeroes ( n );

    WriteOutMatrixOnOfstream ( &of, matrix_A, "A" );
    WriteOutSingleMatrixVerticalyOnOfstream ( &of, vector_b_second, "old b" );
    WriteOutSingleMatrixVerticalyOnOfstream ( &of, vector_x_second, "old x" );

     vector < double > vector_r_second = MethodCongulatedGradient ( vector_x_second, vector_b_second, matrix_A, "iteracje_2ndTask.txt" );

    WriteOutSingleMatrixVerticalyOnOfstream ( &of, vector_r_second, "Second task:\nnew r" );
    WriteOutSingleMatrixVerticalyOnOfstream ( &of, vector_b_second, "new b" );
    WriteOutSingleMatrixVerticalyOnOfstream ( &of, vector_x_second, "new x" );   

    of.close();

    for ( int i = 0; i < 100000000; i ++ ) {}
    
    system ( "python3 ../doWykresow/graph.py");
}