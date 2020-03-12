/*----------------------------------------------------
TITLE:  Assignment 9: task2.cpp
COURSE: TDT4102 - Programming
AUTHOR: Aslak J. Strand (c)
----------------------------------------------------*/

#include <iostream>
#include "task2.h"
using namespace std;

Matrix::Matrix() {
    matrix = nullptr;
}
Matrix::Matrix(int row) : rows{row}, columns{row} {
    matrix = new double*[rows];
    for(int i = 0; i < rows; ++i) {
        matrix[i] = new double[columns];
    }
    initMatrixValue();
}
Matrix::Matrix(int row, int col) : rows{row}, columns{col} {
    matrix = new double*[rows];
    for(int i = 0; i < rows; ++i) {
        matrix[i] = new double[columns];
    }
    initMatrixValue();
}
Matrix::Matrix(const Matrix &theMatrix) : matrix{nullptr} {
    if (theMatrix.matrix == nullptr) {
        this->matrix = nullptr;
    }
    else {
        this->matrix = new double*[theMatrix.rows];
        for (int i = 0; i < theMatrix.rows; i++) {
            this->matrix[i] = new double[theMatrix.columns];
        }
        *matrix = *theMatrix.matrix;
    }
}
void Matrix::initMatrixValue(void) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = 0.0;
        }
    }
}
Matrix::~Matrix() {
    for(int i = 0; i < rows; ++i) {
        delete [] matrix[i];
    }
    delete [] matrix;
}
double Matrix::get(int row, int col) const {
    if (!isValid()) {return -1;}
    return ( matrix[row][col] );
}
void Matrix::set(int row, int col, double value) {
    if (isValid()) {matrix[row][col] = value;}
}
int Matrix::getRows(void) const {
    return rows;
}
int Matrix::getColumns(void) const {
    return columns;
}
bool Matrix::isValid(void) const {
    if (matrix == nullptr) {return false;}
    else {return true;}
}
void Matrix::printMatrix(void) {
    if (!isValid()) {cout << "\n\nUnvalid matrix.\n\n"; return;}
    cout << "\t|";
    for (int i = 0; i < columns; i++) {
        cout << "\t" << i;
    }
    cout << endl;
    cout << "_________";
    for (int i = 0; i < columns; i++) {
        cout << "________";
    }
    cout << endl << "\t|";
    for (int i = 0; i < rows; i++) {
        cout << endl << i << "\t|";
        for (int j = 0; j < columns; j++) {
            cout << "\t" << get(i,j);
        }
    }
}