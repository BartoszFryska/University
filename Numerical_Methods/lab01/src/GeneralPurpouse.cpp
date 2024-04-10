#include "GeneralPurpouse.h"

vector < vector <double> > GenerateMatrixA (vector < double > x, const int n) {

    vector < vector < double > > matrix_A;

    matrix_A.clear();

    vector < double > temp;

    temp.clear();

    for ( int row = 0; row < n; row ++ ) {

        for ( int col = 0; col < n; col ++ ) {

            temp.push_back ( pow ( x [ row ], col ) );
        }

        matrix_A.push_back ( temp );
        temp.clear();
    }

    return matrix_A;
}

vector <double> GenerateMatrixY (vector < vector <double> > matrix_A, vector < double > c, const int n ) {

    double temp_val = 0;

    vector < double > y;

    for ( int row = 0; row < n; row ++ ) {

        for ( int col = 0; col < n; col ++ ) {

            temp_val += ( double ) matrix_A [ row ] [ col ] * c [ col ];
        }

        y.push_back ( temp_val );

        temp_val = 0;
    }

    return y;
}

void WriteOutMatrix ( vector < vector < double > > matrix, string text ) {

    int n_col = matrix [0].size();
    int n_row = matrix.size();

    cout << text << ":\n";

    for ( int row = 0; row < n_row; row ++ ) {

        for ( int col= 0; col < n_col; col ++ ) {

            cout << matrix [ row ] [ col ] << '\t';
        }

        cout << '\n';
    }
    cout << '\n';
}

void WriteOutSingleMatrixVerticaly ( vector < double > matrix, string text ) {

    int n_row = matrix.size();

    cout << text << ":\n";
    
    for ( int row = 0; row < n_row; row ++ ) {


        cout << matrix [ row ] << '\n';
    }
    cout << '\n';
}

void WriteOutMatrixOnOfstream ( ofstream * of, vector < vector < double > > matrix, string text ) {

    int n_col = matrix [0].size();
    int n_row = matrix.size();

    *of << text << ":\n";

    for ( int row = 0; row < n_row; row ++ ) {

        for ( int col= 0; col < n_col; col ++ ) {

            *of << setprecision (3) << setw(10) << matrix [ row ] [ col ] << '\t';
        }

        *of << '\n';
    }
    *of << '\n';
}

void WriteOutSingleMatrixVerticalyOnOfstream ( ofstream * of, vector < double > matrix, string text ) {

    int n_row = matrix.size();

    *of << text << ":\n";
    
    for ( int row = 0; row < n_row; row ++ ) {

        *of << matrix [ row ] << '\n';
    }
    *of << '\n';
}


vector < vector < double > > GenerateRandomSquareMatrix ( const int n ) {

    int checker = 0;
    double tempVal = 0;

    vector < vector < double > > matrix;
    vector <double> temp;

    for ( int i = 0; i < n; i ++ ) {

        for ( int j = 0; j < n; j ++ ) {

            checker = rand() % 2;

            tempVal = (double) rand() / 1000;

            tempVal -= ((int) tempVal / 10) * 10;

            if ( tempVal == 0 ) {

                j --;
                continue;
            }

            if ( checker ) {

                tempVal *= -1;
            }

            temp.push_back ( tempVal );
        }

        matrix.push_back ( temp );
        temp.clear();
    }

    return matrix;
}

vector < double > GenerateRandomVector ( const int n ) {

    int checker = 0;
    double tempVal = 0;
    vector <double> temp;

    for ( int j = 0; j < n; j ++ ) {

            checker = (rand() % 2);

            tempVal = (double) rand();

            tempVal /= 1000;

            tempVal -= (double) ( ( (int) tempVal / 100 ) * 100 );

            if ( tempVal == 0.00 ) {

                j --;
                continue;
            }

            if ( checker ) {

                tempVal *= -1;
            }

            temp.push_back ( tempVal );
        }
    
    return temp;
}

void FixMistakesInMatrix ( vector <vector <double> > * matrix ) {

    const int n = matrix -> size();

    for ( int row = 0; row < n; row ++ ) {

        for ( int col = 0; col < n; col ++ ) {

            if ( matrix -> at ( row ) [ col ] < 1e-12  ) {

                matrix -> at ( row ) [ col ] = 0.0000000;
            }
        }
    }
}