#include "SquareMatrixController.h"
#include "../view/SquareMatrixKalk.h"

SquareMatrixController::SquareMatrixController(/*MatrixKalk* _view, */Matrix* _mat1, Matrix* _mat2)
    : MatrixController(/*_view, */_mat1, _mat2)
{
    if (/*(_view != nullptr && !qobject_cast<SquareMatrixKalk*>(_view))
            || */(_mat1 != nullptr && !dynamic_cast<SquareMatrix*>(_mat1))
            || (_mat2 != nullptr && !dynamic_cast<SquareMatrix*>(_mat2)))
    {
        throw InvalidMatrixTypeException("SquareMatrixController::SquareMatrixController(): Invalid Matrix type");
    }
}

void SquareMatrixController::buildMatrix(const QVector<KeypadInput*>& cells, unsigned int rows, unsigned int cols, int whichMatrix) {
    if (rows != cols)
        throw InvalidMatrixIndexes("SquareMatrixController::buildMatrix1(): rows != cols.");

    MatrixController::buildMatrix(cells,rows,cols,whichMatrix);
}

void SquareMatrixController::buildMatrix(unsigned int rows, unsigned int cols, int whichMatrix) {
    if (rows != cols)
        throw InvalidMatrixIndexes("SquareMatrixController::buildMatrix1(): rows != cols.");

    MatrixController::buildMatrix(rows,cols,whichMatrix);
}

//void SquareMatrixController::buildMatrix2(QVector<KeypadInput*> cells, unsigned int rows, unsigned int cols) {
//    if (rows != cols)
//        throw InvalidMatrixIndexes("SquareMatrixController::buildMatrix2(): rows != cols.");

//    MatrixController::buildMatrix2(cells,rows,cols);
//}

//void SquareMatrixController::buildMatrix2(unsigned int rows, unsigned int cols) {
//    if (rows != cols)
//        throw InvalidMatrixIndexes("SquareMatrixController::buildMatrix2(): rows != cols.");

//    MatrixController::buildMatrix2(rows,cols);
//}

//SETTERS

void SquareMatrixController::setMatrix(const Matrix& mat, int whichMatrix) {
    if (mat.rowCount() != mat.colCount())
        throw InvalidMatrixTypeException("SquareMatrixController::setMatrix1(): Parameter mat is not a SquareMatrix.");

    MatrixController::setMatrix(mat, whichMatrix);
}

//void SquareMatrixController::setMatrix2(const Matrix& mat) {
//    if (mat.rowCount() != mat.colCount())
//        throw InvalidMatrixTypeException("SquareMatrixController::setMatrix2(): Parameter mat is not a SquareMatrix.");

//    MatrixController::setMatrix2(mat);
//}

//operations

double SquareMatrixController::determinant() const {
    //matrix1 ha sicuramente TD SquareMatrix*
    if (getMatrix() == nullptr)
        throw NullPointerException("SquareMatrixController::determinant(): Attempted to dereference a null pointer.");

    return static_cast<SquareMatrix*>(getMatrix())->determinant();
}

SquareMatrix SquareMatrixController::getMinor(unsigned int x, unsigned int y) const {
    //matrix1 ha sicuramente TD SquareMatrix*
    if (getMatrix() == nullptr)
        throw NullPointerException("SquareMatrixController::determinant(): Attempted to dereference a null pointer.");

    return static_cast<SquareMatrix*>(getMatrix())->getMinor(x, y); //throws
}

bool SquareMatrixController::isSupTriangular() const {
    if (getMatrix() == nullptr)
        throw NullPointerException("SquareMatrixController::determinant(): Attempted to dereference a null pointer.");

    return static_cast<SquareMatrix*>(getMatrix())->supTriangular();
}

bool SquareMatrixController::isInfTriangular() const {
    if (getMatrix() == nullptr)
        throw NullPointerException("SquareMatrixController::determinant(): Attempted to dereference a null pointer.");

    return static_cast<SquareMatrix*>(getMatrix())->infTriangular();
}

bool SquareMatrixController::isDiagonal() const {
    if (getMatrix() == nullptr)
        throw NullPointerException("SquareMatrixController::determinant(): Attempted to dereference a null pointer.");

    return static_cast<SquareMatrix*>(getMatrix())->isDiagonal();
}

bool SquareMatrixController::isSymmetric() const {
    if (getMatrix() == nullptr)
        throw NullPointerException("SquareMatrixController::determinant(): Attempted to dereference a null pointer.");

    return static_cast<SquareMatrix*>(getMatrix())->isSymmetric();
}

