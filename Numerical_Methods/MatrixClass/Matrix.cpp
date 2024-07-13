#include "Matrix.h"

Matrix::Matrix (){}

Matrix::Matrix ( size_t n ){

    CreateMatrixOfZeroes ( n );
}

Matrix::Matrix ( size_t row, size_t col ) {

    CreateMatrixOfZeroes ( row, col );
}

void Matrix::CreateMatrixOfZeroes ( size_t n ) {

    contents.clear();
    rows = n;
    cols = n;

    std::vector < double > vec;

    for ( int i = 0; i < n; i ++ ) {

        vec.push_back ( 0.0 );
    }

    for ( int i = 0; i < n; i ++ ) {

        contents.push_back ( vec );
    }

    return;
}

void Matrix::CreateMatrixOfZeroes ( size_t row, size_t col ) {

    contents.clear();
    rows = row;
    cols = col;

    std::vector < double > vec;

    for ( int i = 0; i < col; i ++ ) {

        vec.push_back ( 0.0 );
    }

    for ( int i = 0; i < row; i ++ ) {

        contents.push_back ( vec );
    }

    return;
}

void Matrix::CreateIdentityMatrix ( size_t n ) {

    (*this).CreateMatrixOfZeroes ( n );

    for ( int i = 0; i < n; i ++ ) {

        (*this).contents [ i ] [ i ] = 1.0;
    }

    return;
}

void Matrix::WriteOutOnCout ( std::string text ) {

    std::cout << text << ":\n";

    for ( int row = 0; row < rows; row ++ ) {

        for ( int col= 0; col < cols; col ++ ) {

            std::cout <<std::setw ( 10 ) << contents [ row ] [ col ] << "\t";
        }

        std::cout << '\n';
    }

    std::cout << '\n';
}

void Matrix::WriteOutOnOfstream ( std::ofstream * of, std::string text ) {

    *of << text << ":\n";

    for ( int row = 0; row < rows; row ++ ) {

        for ( int col= 0; col < cols; col ++ ) {

            *of << std::setw ( 10 ) << contents [ row ] [ col ] << " ";
        }

        *of << '\n';
    }
    *of << '\n';
}

Matrix Matrix::operator * ( Matrix multi ) {

    Matrix newMatrix ( this->Rows(), multi.Columns() );

    if ( this->Columns() != multi.Rows() ) {

        return newMatrix;
    }

    size_t n = this->Columns();

    for ( int row = 0; row < this->Rows(); row++ ) {

        for ( int col = 0; col < multi.Columns(); col++ ) {

            double sum = 0; 

            for ( int z = 0; z < n; z++ )
                sum += (*this) [ row ] [ z ] * multi [ z ] [ col ];
            
            newMatrix [ row ] [ col ] = sum;
     }
  }

    return newMatrix;
}

Matrix Matrix::operator - ( Matrix matrix ) {

    if ( (*this).Rows() != matrix.Rows() || (*this).Columns() != matrix.Columns() ) {

        return (*this);
    }

    size_t row = (*this).Rows();
    size_t col = (*this).Columns();

    Matrix copy = (*this);

    for ( int r = 0; r < row; r ++ ) {

        for ( int c = 0 ; c < col; c ++ ) {

            copy [ r ] [ c ] -=  matrix [ r ] [ c ];
        }
    }

    return copy;
}

Matrix Matrix::operator + ( Matrix matrix ) {

    if ( (*this).Rows() != matrix.Rows() || (*this).Columns() != matrix.Columns() ) {

        return (*this);
    }

    size_t row = (*this).Rows();
    size_t col = (*this).Columns();

    Matrix copy = (*this);

    for ( int r = 0; r < row; r ++ ) {

        for ( int c = 0 ; c < col; c ++ ) {

            copy [ r ] [ c ] +=  matrix [ r ] [ c ];
        }
    }

    return copy;
}

Matrix Matrix::operator / ( Matrix multi ) {

    multi = multi.reverse();

    return (*this) * multi;
}

Matrix Matrix::operator * ( const double a ) {

    Matrix copy = (*this);

    for ( int row = 0; row < copy.Rows(); row ++ ) {

        for ( int col = 0; col < copy.Columns(); col ++ ) {

            copy [ row ] [ col ] *= a;
        }
    }

    return copy;
}

Matrix Matrix::operator / ( const double a ) {

    double c = (double) 1.0 / a;

    return (*this) * c;
}

std::vector < double > & Matrix::operator [] ( size_t a ) {

    return (*this).contents [ a ];
} 

Matrix Matrix::reverse () {

    if ( rows != cols ) {

        return (*this);
    }

    Matrix tempReversedMatrix ( rows );

    Matrix temp_matrix_b ( rows, 1 );

    *this = (*this) * 0.1; 

    for ( int i = 0; i < rows; i ++ ) {

        temp_matrix_b.CreateMatrixOfZeroes ( rows, 1 );

        temp_matrix_b [ i ] [ 0 ] = 1;

        Matrix temp = MATRIX::SolveXForAXequalsY ( *this, temp_matrix_b ) ;

        for ( int j = 0; j < rows; j ++ ) {
            
            tempReversedMatrix [ j ] [ i ] = temp [ j ] [ 0 ];
        }
    }

    tempReversedMatrix = tempReversedMatrix * 0.100 ;

    *this = (*this) / 0.1; 

    return tempReversedMatrix;
}

Matrix Matrix::transponate () {

    Matrix matrix ( cols, rows );

    for ( int r = 0; r < rows; r ++ ) {

        for ( int c = 0; c < cols; c ++ ) {

            matrix [ c ] [ r ] = (*this) [ r ] [ c ];
        }
    }

    return matrix;
}


double Matrix::det () {

    if ( rows != cols ) {

        return -1;
    }

    double det = 1.0;

    size_t n = rows;

    for (int i = 0; i < n; i++) {

        int pivot = i;

        for (int j = i + 1; j < n; j++) {

            if (std::max( contents[j][i], -contents[j][i]) > std::max(contents[pivot][i], -contents[pivot][i]) ) {

                pivot = j;
            }
        }

        if (pivot != i) {
            
            contents [ i ].swap ( contents [ pivot ] );

            det *= -1;
        }

        if ( contents [ i ] [ i ] == 0 ) {

            return 0;
        }

        det *= contents [ i ] [ i ];

        for ( int j = i + 1; j < n; j++ ) {

            double factor = contents [ j ] [ i ] / contents [ i ][ i ];

            for (int k = i + 1; k < n; k++) {

                contents [ j ] [ k ] -= factor * contents [ i ] [ k ];
            }
        }
    }

    return det;
}

Matrix Matrix::returnColumn ( size_t i ) {

    Matrix tmp ( rows, 1 );

    if ( i >= cols ) {

        return tmp;
    }

    for ( int row = 0; row < rows; row ++ ) {

        tmp [ row ] [ 0 ] = contents [ row ] [ i ];
    }

    return tmp;
}

Matrix Matrix::returnRow ( size_t i ) {

    Matrix tmp ( 1, cols );

    if ( i >= rows ) {

        return tmp;
    }

    for ( int col = 0; col < cols; col ++ ) {

        tmp [ 0 ] [ col ] = contents [ i ] [ col ];
    }

    return tmp;
}

double Matrix::returnVectorNorm ( ) {

    if ( Columns() != 1 ) {

        return 0;
    }

    double n = ( transponate() * (*this)) [0] [0];

    return sqrt ( n );
}

void Matrix::normaliseVector() {

    (*this) = (*this) / returnVectorNorm();
    return;
}


Matrix MATRIX::SolveXForAXequalsY ( Matrix A, Matrix Y ) {

    if ( A.Rows() != A.Columns() || A.Rows() != Y.Rows() ) {

        Matrix c ( A.Rows(), 1 );

        return c;
    }

    float  multiplier = 0;

    for ( int current_row = 0; current_row < A.Columns(); current_row ++ ) {

        for ( int row_to_delete_from = current_row + 1; row_to_delete_from < A.Rows(); row_to_delete_from ++ ) {

            multiplier = A [ row_to_delete_from ] [ current_row ] / A [ current_row ] [ current_row ];

            A [ row_to_delete_from ] [ current_row ] = 0.0000000;

            for ( int col = current_row + 1; col < A.Rows(); col ++ ) {

                A [ row_to_delete_from ] [ col ] -= multiplier * A [ current_row ] [ col ]; 
            }

            Y [ row_to_delete_from ] [ 0 ] -= ( multiplier ) * Y [ current_row ] [ 0 ];
        }
    }

    Matrix c_ForGauss ( A.Rows(), 1 );

    float temp = 0;

    for ( int row = A.Rows() - 1; row >= 0; row -- ) {

        temp = Y [ row ] [ 0 ];

        for ( int col = A.Rows() - 1; col > row; col -- ) {

            temp -= A [ row ] [ col ] * c_ForGauss [ A.Rows() - 1 - col ] [ 0 ];
        }

        temp /= A [ row ] [ row ];

        c_ForGauss [ A.Rows() - row - 1 ] [ 0 ] = temp;
    }

    Matrix temp2 ( A.Rows(), 1 );

    for ( int i = A.Rows() - 1; i >= 0; i -- ) {

        temp2 [ A.Rows() - i - 1 ] [ 0 ] = c_ForGauss [ i ] [ 0 ];
    }

    return temp2;
}

// Matrix Matrix::operator=( Matrix matrix ){

//     CreateMatrixOfZeroes ( matrix.Rows(), matrix.Columns());

//     for ( int row = 0; row < rows; row ++ ) {

//         for ( int col = 0; col < cols; col ++ ) {

//             contents [ row ] [ col ] = matrix [ row ] [ col ];
//         }
//     }

//     return (*this);
// }