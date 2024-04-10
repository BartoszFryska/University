#include "GeneralPurpouse.h"
#include "LUMethod.h"
#include "GaussMethod.h"

vector < vector <double> > GenerateMatrixA ( const int n) {

    vector < vector < double > > matrix_A;

    matrix_A.clear();

    const int m = 5;

    vector < double > temp;

    for ( int i = 0; i < n; i ++ ) {

        for ( int j = 0; j < n; j ++ ) {

            if ( abs ( i - j ) > m ) {

                temp.push_back ( 0.0 );

                continue;
            }

            temp.push_back ( (double) 1.0 / ( 1 + abs ( i - j ) ) );
        }

        matrix_A.push_back ( temp );

        temp.clear();
    }

    return matrix_A;
}

vector < double > GenerateVectorBForFirstTask ( const int n ) {

    vector < double > matrix_b;

    matrix_b.clear();

    for ( int i = 0; i < n; i ++ ) {

        matrix_b.push_back ( i );
    }

    return matrix_b;
}

vector < double > GenerateVectorBForSecondTask ( const int n ) {

    vector < double > matrix_b;

    matrix_b.clear();

    for ( int i = 0; i < n; i ++ ) {

        matrix_b.push_back ( i + 1 );
    }

    return matrix_b;
}

vector < double > VectorOfZeroes ( const int n ) {

    vector < double > zeroes;

    for ( int i = 0; i < n; i ++ ) {

        zeroes.push_back ( 0.0 );
    }

    return zeroes;
}

void WriteOutMatrix ( vector < vector < double > > matrix, string text ) {

    int n = matrix.size();

    cout << text << ":\n";

    for ( int row = 0; row < n; row ++ ) {

        for ( int col= 0; col < n; col ++ ) {

            cout << matrix [ row ] [ col ] << "\t\t";
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

    int n = matrix.size();

    *of << text << ":\n";

    for ( int row = 0; row < n; row ++ ) {

        for ( int col= 0; col < n; col ++ ) {

            *of << setw ( 10 ) << matrix [ row ] [ col ] << " ";
        }

        *of << '\n';
    }
    *of << '\n';
}

void WriteOutSingleMatrixVerticalyOnOfstream ( ofstream * of, vector < double> matrix, string text ) {

    int n_row = matrix.size();

    *of << text << ":\n";
    
    for ( int row = 0; row < n_row; row ++ ) {

        *of << matrix [ row ] << '\n';
    }
    *of << '\n';
}

vector < vector < double > > MultiplyMatrices ( vector < vector < double > > A, vector < vector < double > > B ) {

    int n = A.size();

    vector < vector < double > > newMatrix = MatrixZero ( n );

    for ( int i = 0; i < n; ++i ) {

        for ( int j = 0; j < n; ++j ) {

            double sum = 0; 

            for(int z = 0; z < n; ++z)
                sum += A [ i ] [ z ] * B [ z ] [ j ];
            
            newMatrix [ i ] [ j ] = sum;
     }
  }

    return newMatrix;
}

vector < vector < double > > ReverseMatrixA ( vector < vector < double > > matrix_A ) {

    MultiplyASquareMatrix ( matrix_A, 0.100 );

    vector < vector < double > > tempReversedMatrix;

    vector < double > temp_matrix_b;

    const int n = matrix_A.size();

    for ( int i = 0; i < n; i ++ ) {

        temp_matrix_b = generateSingleMatrixWithOne1 ( n, i );

        tempReversedMatrix.push_back ( CalculateCUsingGauss ( matrix_A, temp_matrix_b, n ) );

        temp_matrix_b.clear();
    }

    vector < vector < double > > ReversedMatrix = MatrixOfZeroes ( n );

    for ( int x = 0; x < n; x ++ ) {

        for ( int y = 0; y < n; y ++ ) {

            ReversedMatrix [ x ] [ y ] = tempReversedMatrix [ y ] [ x ];
        }
    }

    MultiplyASquareMatrix ( ReversedMatrix, 0.100 );

    return ReversedMatrix;
}

vector < vector < double > > MatrixOfZeroes ( const int n ) {

    vector < vector < double > > matrix;

    vector < double > vec;

    
    for ( int i = 0; i < n; i ++ ) {

        vec.push_back ( 0.0 );
    }

    for ( int i = 0; i < n; i ++ ) {

        matrix.push_back ( vec );
    }

    return matrix;
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

void WriteOutMatrixOnOfstreamInAHelpfulWay ( ofstream * of, vector < vector < double > > matrix) {

    int n = matrix.size();

    *of << "inv{";

    for ( int row = 0; row < n; row ++ ) {

        *of << '{';

        for ( int col= 0; col < n; col ++ ) {

            *of << matrix [ row ] [ col ] ;

            if ( col != n - 1 ) {

                *of << ',';
            }
        }

        *of << '}';

        if ( row != n - 1 ) {

            *of << ',';
        }
    }
    *of << "}";
    *of << '\n';
}

void MultiplyASquareMatrix ( vector < vector < double > > &matrix, const double multiplier ) {

    const int n = matrix.size();

    for  (int x = 0; x < n; x ++ ) {

        for ( int y = 0; y < n; y ++ ) {

            matrix [ x ] [ y ] *= multiplier;
        }
    }

    return;
}

vector < double > MultiplySquareMatrixByAVector ( vector < vector < double > > matrix, vector < double > vecto ) {

    vector < double > outMatrix;

    double temp = 0.0;

    const int n = matrix.size ();

    for ( int i = 0; i < n; i ++ ) {

        for ( int j = 0; j < n; j ++ ) {

            temp += matrix [ i ] [ j ] * vecto [ j ];
        }

    outMatrix.push_back ( temp );
        temp = 0.0;
    }

    return outMatrix;
}

void WriteOutMatrixOnOfstreamWithSetprecision ( ofstream * of, vector < vector < double > > matrix, string text ) {

    int n = matrix.size();

    *of << text << ":\n";

    for ( int row = 0; row < n; row ++ ) {

        for ( int col= 0; col < n; col ++ ) {

           /* if ( matrix [ row ] [ col ] < 0 && matrix [ row ] [ col ] > -0.001  ) {

                *of << setw ( 5 ) << setprecision ( 3 ) << 0 << " ";
                continue;
            }

            if ( matrix [ row ] [ col ] > 0 && matrix [ row ] [ col ] < 0.001  ) {

                *of << setw ( 5 ) << setprecision ( 3 ) << 0 << " ";
                continue;
            }*/

            *of << setw ( 10 ) << setprecision ( 3 ) << matrix [ row ] [ col ] << " ";
        }

        *of << '\n';
    }
    *of << '\n';
}

double CountANorm ( vector < vector < double > > matrix ) {

    double val = 0.0;

    const int n = matrix.size();

    for ( int i = 0; i < n; i ++ ) {

        for ( int j = 0; j < n; j ++ ) {

            val = max ( val, ( matrix [ i ] [ j ] < 0 ) ? matrix [ i ] [ j ] * (-1) : matrix [ i ] [ j ] );
        }
    }

    return val;
}