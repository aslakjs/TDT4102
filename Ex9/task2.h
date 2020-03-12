/*----------------------------------------------------
TITLE:  Assignment 9: task2.h
COURSE: TDT4102 - Programming
AUTHOR: Aslak J. Strand (c)
----------------------------------------------------*/

#ifndef TASK2_H
#define TASK2_H

#include <utility>

class Matrix {
private:
    int rows;
    int columns;
    double **matrix;
public:
    Matrix();
    explicit Matrix(int row);
    Matrix(int row, int col);
    Matrix(const Matrix &theMatrix);
    ~Matrix();
    double get(int row, int col) const;
    void set(int row, int col, double value);
    int getRows(void) const;
    int getColumns(void) const;
    bool isValid(void) const;
    void printMatrix(void);
    void initMatrixValue(void);
    Matrix &operator=(Matrix old) {
        std::swap(matrix, old.matrix);
        return *this;
    }



    Matrix &operator+=(Matrix cpy) {
        if ((this->getRows() != cpy.getRows()) || 
         (this->getColumns() != cpy.getColumns())) {
            this->matrix = nullptr;
            cpy.matrix = nullptr;
            return *this;
        }
        else {
            for (int i = 0; i < this->getRows(); i++) {
                for (int j = 0; j < this->getColumns(); j++) {
                    this->matrix[i][j] += cpy.matrix[i][j];
                }
            }
            return *this;
        }
    }






    Matrix &operator+(Matrix old) {
        if ((this->getRows() != old.getRows()) || (this->getColumns() != old.getColumns())) {
            old.matrix = nullptr;
            return *this;
        }
        else {
            for (int i = 0; i < old.getRows(); i++) {
                for (int j = 0; j < old.getColumns(); j++) {
                    this->matrix[i][j] = old.matrix[i][j] + this->matrix[i][j];
                }
            }
            return *this;
        }
    }
};



#endif /* TASK2_H */