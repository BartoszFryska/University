#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream>
#include <vector>
#include <math.h>
#include<cstdlib>
#include <fstream>
#include <iomanip>

class Matrix {

private:
    size_t rows, cols;
    std::vector < std::vector < double > > contents;

public:
    Matrix ();
    Matrix ( size_t n );
    Matrix ( size_t row, size_t col );
    void CreateMatrixOfZeroes ( size_t n );
    void CreateMatrixOfZeroes ( size_t row, size_t col );
    void CreateIdentityMatrix ( size_t n );
    void WriteOutOnCout ( std::string text );
    void WriteOutOnOfstream ( std::ofstream * of, std::string text );
    Matrix operator * ( Matrix multi );
    Matrix operator - ( Matrix matrix );
    Matrix operator + ( Matrix matrix );
    Matrix operator / ( Matrix multi );
    Matrix operator * ( const double a );
    Matrix operator / ( const double a );
    std::vector < double > & operator [] ( size_t a ); 
    Matrix reverse ();
    Matrix transponate ();
    size_t Columns () { return cols; };
    size_t Rows () { return rows; };
    double det ();
    Matrix returnColumn ( size_t i );
    Matrix returnRow ( size_t i );
    double returnVectorNorm ();
    void normaliseVector();
    //Matrix operator=( Matrix matrix );
};

//Matrix operator * ( Matrix matrix, const double a ) { return matrix.operator*(a); }

//Matrix operator / ( Matrix matrix, const double a ) { return matrix.operator/(a); }


#endif