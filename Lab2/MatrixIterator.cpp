#pragma once
#include "MatrixIterator.h"

MatrixIterator::MatrixIterator(const Matrix& matrix) : matrix{ matrix }, currentPosition{ 0 } {

}

void MatrixIterator::first() {
    currentPosition = 0;
}

/**
 * subalgorithm next(matrixIterator):
 *      pre: matrixIterator is a MatrixIterator
 *      post: matrixIterator.currentPosition' = matrixIterator.currentPosition + 1
 *      throws an exception if the iterator is not valid
 *
 *      if (!valid(matrixIterator)) then
 *          throw exception
 *      end-if
 *      matrixIterator.currentPosition <-- matrixIterator.currentPosition + 1
 * end subalgorithm
 *
 * time complexity: Theta(1)
 */
void MatrixIterator::next() {
    if (!valid())
    {
        throw std::runtime_error("error");
    }
    ++currentPosition;
}

bool MatrixIterator::valid() const {
    return 0 <= currentPosition && currentPosition < matrix.number_of_lines * matrix.number_of_columns;
}

TElem MatrixIterator::getCurrent() {
    if (!valid())
    {
        throw std::runtime_error("error");
    }
    else
    {
        int i = 0, j = 0,counter=currentPosition;

        while (counter)
        {
            j++;

            if (j == matrix.number_of_columns)
            {
                j = 0;
                i++;
            }

            counter--;
        }

        return matrix.element(i, j);


    }
}