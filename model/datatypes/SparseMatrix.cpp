#include "SparseMatrix.h"

SparseMatrix::SparseMatrix(unsigned int a, unsigned int b) :
    Matrix(a, b, 0), dirtyBit(false), sparsity(-1) {}

void SparseMatrix::clear() {
    for (unsigned int i = 0; i < getRow(); i++)
        for (unsigned int j = 0; j < getCol(); j++)
            get(i,j) = 0;
}

double SparseMatrix::getSparsity() {
    if (!dirtyBit && sparsity != -1)
        return sparsity;

    dirtyBit = false;
    double cumulator = 0;
    for (unsigned int i = 0; i < getRow(); i++)
        for (unsigned int j = 0; j < getCol(); j++)
            if (get(i,j) == 0)
                cumulator++;
    sparsity = cumulator / static_cast<double>(getRow() * getCol());
    return sparsity;
}

double& SparseMatrix::get(unsigned int row, unsigned int col) {
    dirtyBit = true;
    return Matrix::get(row, col);
}

bool SparseMatrix::isSymmetric() const {
    if (getRow() != getCol())
        return false;
    unsigned int n = getRow();
    for (unsigned int i = 0; i < n; i++)
        for (unsigned int j = 0; j < n; j++)
            if (j > i && Matrix::get(i,j) != Matrix::get(j,i))
                return false;
    return true;
}

bool SparseMatrix::isDense() {
    if (getSparsity() <= 0.5)
        return true;
    return false;
}

/*
00 01 02 03
10 11 12 13
20 21 22 23
30 31 32 33
*/
