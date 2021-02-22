#pragma once
#include <iostream>
#include "MatrixIterator.h"
using std::cout;
using std::endl;
//DO NOT CHANGE THIS PART
typedef int TElem;
#define NULL_TELEM 0


class Node
{
public:
	TElem value;
	Node* previous;
	Node* next;
	int i_index;
	int j_index;

	Node()
	{
		this->value = NULL_TELEM;

	}
	~Node()
	{
		cout << "Node was destroyed!" << endl;
	}
};


class Matrix {

	friend class MatrixIterator;
public:

	int number_of_lines, number_of_columns;
	Node* first_element;
	Node* last_element;
	int size;
	//constructor
	Matrix(int nrLines, int nrCols);

	//returns the number of lines
	int nrLines() const;

	//returns the number of columns
	int nrColumns() const;

	//returns the element from line i and column j (indexing starts from 0)
	//throws exception if (i,j) is not a valid position in the Matrix
	TElem element(int i, int j) const;

	//modifies the value from line i and column j
	//returns the previous value from the position
	//throws exception if (i,j) is not a valid position in the Matrix
	TElem modify(int i, int j, TElem e);
	MatrixIterator iterator() const;
};
