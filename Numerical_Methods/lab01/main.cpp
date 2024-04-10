#include "GeneralPurpouse.h"
#include "GaussMethod.h"
#include "GaussJordanMethod.h"

///#include "implot.h"
///#include "implot_internal.h"

using namespace std;

int main () {

    //srand((unsigned) time(NULL));

  //  vector < double > x = { -2, -1, 0.1, 1, 2, 3 };

    //vector < double > c = { 0.5 , -1, 2, -0.2, 3, -70 };

    //int n = c.size ();

    const int n = 100;

    vector < double > x = GenerateRandomVector ( n );

   vector < vector < double > > matrix_A = GenerateMatrixA ( x, n );

  //  vector < vector < double > > matrix_A = GenerateRandomSquareMatrix ( n );

    vector < double > c = GenerateRandomVector ( n );

    vector < double > y = GenerateMatrixY ( matrix_A, c, n );

                                                                                                  // Gauss algorithm

    vector < vector <double > > matrix_A_ForGauss = matrix_A;
    vector < double > y_ForGauss = y;

    TriangulateSquareMatrix ( matrix_A_ForGauss, y_ForGauss, n );
    vector < double > c_ForGauss = CalculateCInGauss ( matrix_A_ForGauss, y_ForGauss, n );
  //  FixMistakesInMatrix ( &matrix_A_ForGauss );

                                                                                                 // Gauss-Jordan algorithm

    vector < vector <double > > matrix_A_ForGaussJordan = matrix_A;
    vector < double > y_ForGaussJordan = y;

    TriangulateSquareMatrix ( matrix_A_ForGaussJordan, y_ForGaussJordan, n );
    MakeTriangulatedMatrixADiagonalMatrix ( matrix_A_ForGaussJordan, y_ForGaussJordan, n );
    //MakeMatrixADiagonalMatrix ( matrix_A_ForGaussJordan, y_ForGaussJordan, n );
    vector < double > c_ForGaussJordan = CalculateCInGaussJordan ( matrix_A_ForGaussJordan, y_ForGaussJordan, n );
    FixMistakesInMatrix ( &matrix_A_ForGaussJordan );

    ofstream of ( "../wynik.txt" );

    WriteOutMatrixOnOfstream ( &of, matrix_A, "Original A");
    WriteOutMatrixOnOfstream ( &of, matrix_A_ForGauss, "Gauss A" );
    WriteOutMatrixOnOfstream ( &of, matrix_A_ForGaussJordan, "GaussJordan A" );

    WriteOutSingleMatrixVerticalyOnOfstream ( &of, c, "Original c");
    WriteOutSingleMatrixVerticalyOnOfstream ( &of, c_ForGauss, "Gauss c");
    WriteOutSingleMatrixVerticalyOnOfstream ( &of, c_ForGaussJordan, "GaussJordan c");

    WriteOutSingleMatrixVerticalyOnOfstream ( &of, y, "Original Y");
    WriteOutSingleMatrixVerticalyOnOfstream ( &of, y_ForGauss, "Gauss Y");
    WriteOutSingleMatrixVerticalyOnOfstream ( &of, y_ForGaussJordan, "GaussJordan Y");

    of.close();

    /*float x [ 100 ];
    for ( int i = 1; i <= 100; i ++ ) {

        x [ i - 1 ] = i;
    }*/

    /*double c1 [ n ];
    for ( int i = 0;  i < n; i ++ ) {

        c1 [ i ] = c [ i ] - c_ForGauss [ i ];

        if ( c1 [ i ] < 0 ) {

            c1 [ i ] *= -1;
        } 
    }

    double c2 [ n ];
    for ( int i = 0;  i < n; i ++ ) {

        c2 [ i ] = c [ i ] - c_ForGauss [ i ];

        if ( c2 [ i ] < 0 ) {

            c2 [ i ] *= -1;
        } 
    }*/

    /*
    ImGui::CreateContext();
    ImPlot::CreateContext();

    if ( ImPlot::BeginPlot ("Scatter Plot") ) {

        ImPlot::SetupAxes ( "x", "y" );
        ImPlot::PlotScatter ( "o(g)", x, y, 100 );
        ImPlot::SetNextMarkerStyle ( ImPlotMarker_Circle );
        ImPlot::EndPlot ();
    }

    ImPlot::DestroyContext();
    ImGui::DestroyContext();
    ImGui::End();
    */

   ofstream outMtLaben ( "../cvalues.txt" );

   for ( int i = 0; i < n; i ++ ) {

       // outMtLaben << c1 [ i ] << " ";
       outMtLaben << c_ForGauss [ i ] << " ";
   }

    outMtLaben << '\n';

    for ( int i = 0; i < n; i ++ ) {

       // outMtLaben << c1 [ i ] << " ";
        outMtLaben << c_ForGaussJordan [ i ] << " ";
   }

   outMtLaben << '\n';

   map < double, double > macza;

   for ( int i = 0; i < n; i ++ ) {

        macza [ x [ i ] ] = y [ i ]     ;
   }



  /* for ( int i = 0; i < n; i ++ ) {

        outMtLaben << x [ i ] << " ";
   }

   outMtLaben << '\n';

    for ( int i = 0; i < n; i ++ ) {

        outMtLaben << y [ i ] << " ";
   }*/

   for ( const auto & pair : macza ) {

        outMtLaben << pair.first << ' ';
   }

   outMtLaben << '\n';

   for ( const auto & pair : macza ) {

        outMtLaben << pair.second << ' ';
   }

   outMtLaben.close();
}

// x : -2 -1 0 1 2 3
// c0 = 0,5 : c1 = -1 : c2 = 2 : c3 = -0.2 : c4 = 3 : c5 = -70