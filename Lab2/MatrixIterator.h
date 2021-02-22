#pragma once
#include "Matrix.h"

typedef int TElem;

//class Matrix;

class MatrixIterator {
friend class Matrix;
private:
    const Matrix& matrix;
    int currentPosition;
    MatrixIterator(const Matrix& matrix);

public:
    void first();
    void next();
    bool valid() const;
    TElem getCurrent();
};
