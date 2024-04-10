#include "GeneralPurpouse.h"
#include "LUMethod.h"
#include "GaussMethod.h"

vector < vector <float> > GenerateMatrixA ( const int n) {

    vector < vector < float > > matrix_A;

    matrix_A.clear();

    int q = 2;

    vector < float > temp;

    temp.clear();

    for ( int row = 0; row < n; row ++ ) {

        for ( int col = 0; col < n; col ++ ) {

            temp.push_back ( (float ) 1 / (col + row + q) );
        }

        matrix_A.push_back ( temp );
        temp.clear();
    }

    return matrix_A;
}

vector <float> GenerateMatrixY (vector < vector <float> > matrix_A, vector < float > c, int n ) {

    float temp_val = 0;

    vector < float > y;

    for ( int row = 0; row < n; row ++ ) {

        for ( int col = 0; col < n; col ++ ) {

            temp_val += ( float ) matrix_A [ row ] [ col ] * c [ col ];
        }

        y.push_back ( temp_val );

        temp_val = 0;
    }

    return y;
}


void WriteOutMatrix ( vector < vector < float > > matrix, string text ) {

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

void WriteOutSingleMatrixVerticaly ( vector < float > matrix, string text ) {

    int n_row = sizeof ( matrix );

    cout << text << ":\n";
    
    for ( int row = 0; row < n_row; row ++ ) {


        cout << matrix [ row ] << '\n';
    }
    cout << '\n';
}

void WriteOutMatrixOnOfstream ( ofstream * of, vector < vector < float > > matrix, string text ) {

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

vector < vector < float > > MultiplyMatrices ( vector < vector < float > > A, vector < vector < float > > B ) {

    int n = A.size();

    vector < vector < float > > newMatrix = MatrixZero ( n );

    for ( int i = 0; i < n; ++i ) {

        for ( int j = 0; j < n; ++j ) {

            float sum = 0; 

            for(int z = 0; z < n; ++z)
                sum += A [ i ] [ z ] * B [ z ] [ j ];
            
            newMatrix [ i ] [ j ] = sum;
     }
  }

    return newMatrix;
}

vector < vector < float > > ReverseMatrixA ( vector < vector < float > > matrix_A ) {

    MultiplyASquareMatrix ( matrix_A, 0.100 );

    vector < vector < float > > tempReversedMatrix;

    vector < float > temp_matrix_b;

    const int n = matrix_A.size();

    for ( int i = 0; i < n; i ++ ) {

        temp_matrix_b = generateSingleMatrixWithOne1 ( n, i );

        tempReversedMatrix.push_back ( CalculateCUsingGauss ( matrix_A, temp_matrix_b, n ) );

        temp_matrix_b.clear();
    }

    vector < vector < float > > ReversedMatrix = MatrixOfZeroes ( n );

    for ( int x = 0; x < n; x ++ ) {

        for ( int y = 0; y < n; y ++ ) {

            ReversedMatrix [ x ] [ y ] = tempReversedMatrix [ y ] [ x ];
        }
    }

    MultiplyASquareMatrix ( ReversedMatrix, 0.100 );

    return ReversedMatrix;
}

vector < vector < float > > MatrixOfZeroes ( const int n ) {

    vector < vector < float > > matrix;

    vector < float > vec;

    
    for ( int i = 0; i < n; i ++ ) {

        vec.push_back ( 0.0 );
    }

    for ( int i = 0; i < n; i ++ ) {

        matrix.push_back ( vec );
    }

    return matrix;
}

vector < vector < float > > GenerateRandomSquareMatrix ( const int n ) {

    int checker = 0;
    float tempVal = 0;

    vector < vector < float > > matrix;
    vector <float> temp;

    for ( int i = 0; i < n; i ++ ) {

        for ( int j = 0; j < n; j ++ ) {

            checker = rand() % 2;

            tempVal = (float) rand() / 1000;

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

void WriteOutMatrixOnOfstreamInAHelpfulWay ( ofstream * of, vector < vector < float > > matrix) {

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

void MultiplyASquareMatrix ( vector < vector < float > > &matrix, const float multiplier ) {

    const int n = matrix.size();

    for  (int x = 0; x < n; x ++ ) {

        for ( int y = 0; y < n; y ++ ) {

            matrix [ x ] [ y ] *= multiplier;
        }
    }

    return;
}

void WriteOutMatrixOnOfstreamWithSetprecision ( ofstream * of, vector < vector < float > > matrix, string text ) {

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

float CountANorm ( vector < vector < float > > matrix ) {

    float val = 0.0;

    const int n = matrix.size();

    for ( int i = 0; i < n; i ++ ) {

        for ( int j = 0; j < n; j ++ ) {

            val = max ( val, ( matrix [ i ] [ j ] < 0 ) ? matrix [ i ] [ j ] * (-1) : matrix [ i ] [ j ] );
        }
    }

    return val;
}