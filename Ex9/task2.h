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
};



#endif /* TASK2_H */