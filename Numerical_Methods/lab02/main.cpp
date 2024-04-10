#include "GeneralPurpouse.h"
#include "GaussMethod.h"
#include "GaussJordanMethod.h"
#include "LUMethod.h"

using namespace std;

int main () {

    const int n = 4;

 vector < vector < float > > matrix_A = GenerateMatrixA ( n );

    
//vector < vector < float > > matrix_A = GenerateRandomSquareMatrix ( n );

//vector < vector < float > > matrix_A = { { 0.1, 0.3, -0.02, 0.11 }, { 0.44, 0.1243, -0.02, -0.11 }, { 1.1, -0.6, -0.02, -0.11 }, { 0.02, 0.3, -0.123, 0.578 } };

    vector < vector < float > > matrix_L = MatrixZero ( n );
    vector < vector < float > > matrix_U = MatrixZero ( n );

    GenerateMatrixesLU ( matrix_A, matrix_L, matrix_U, n );
    vector < vector < float > > NEW_matrix_A = MultiplyMatrices ( matrix_L, matrix_U );

    ofstream of ("../wynik.txt");

    WriteOutMatrixOnOfstreamInAHelpfulWay ( &of, matrix_A);

    of << '\n';
    WriteOutMatrixOnOfstream ( &of, matrix_A, "A" );
    WriteOutMatrixOnOfstream ( &of, matrix_L, "L" );
    WriteOutMatrixOnOfstream ( &of, matrix_U, "U" );
    WriteOutMatrixOnOfstream ( &of, NEW_matrix_A, "LU" );

    vector < vector < float > > reversed_A = ReverseMatrixA ( NEW_matrix_A );

    WriteOutMatrixOnOfstream ( &of, reversed_A, "inversed A" );

    vector < vector < float > > matrix_A_times_reversed_A = MultiplyMatrices ( matrix_A, reversed_A );

    WriteOutMatrixOnOfstreamWithSetprecision ( &of, matrix_A_times_reversed_A, "A * inversed A" );

    float det_A = WriteOutDiagonalElementsOfAnUMatrixAndDet_UAndReturnIt ( matrix_U, "przekatna_w_U.txt" );

    float norma_A = CountANorm ( matrix_A );
    float norma_reversed_A = CountANorm ( reversed_A  );

    float norma_końcowa_macierzy_A = norma_A * norma_reversed_A;
    
    of.close();
    of.open ( "../wskazniki_uwarunkowania.txt" );

    of << "||A|| = " << norma_A << '\n';
    
    of.close();
}