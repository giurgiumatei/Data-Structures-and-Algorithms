#include "Matrix.h"
#include <exception>
using namespace std;


Matrix::Matrix(int nrLines, int nrCols) {
	   
	this->number_of_lines = nrLines;
	this->number_of_columns = nrCols;
	this->size = 0;
	Node* first_element = NULL;
	Node* last_element = NULL;


}


int Matrix::nrLines() const {
	return this->number_of_lines;
	
}


int Matrix::nrColumns() const {
	return this->number_of_columns;
}


TElem Matrix::element(int i, int j) const {
	
	if (i >= this->number_of_lines || j >= this->number_of_columns || j < 0 || i < 0)
	{
		throw std::runtime_error("invalid matrix");
	}


	Node* element = this->first_element;

	if (this->first_element == NULL)
	{
		return NULL_TELEM;
	}

	for (int index = 0; index < this->size; index++)
	{

		if (element->i_index == i && element->j_index == j)
		{
			return element->value;

		}

		element=element->next;
	}

	return NULL_TELEM;

}

TElem Matrix::modify(int i, int j, TElem e) {
	
	if (i >= this->number_of_lines || j >= this->number_of_columns || j < 0 || i < 0)
	{
		throw std::runtime_error("invalid matrix");
	}


	Node* element = this->first_element;
	TElem old_value;



	if (this->first_element == NULL)
	{
		Node* new_node = new Node();
		new_node->value = e;
		new_node->previous = NULL;
		new_node->next = NULL;
		new_node->i_index = i;
		new_node->j_index = j;
		this->first_element = new_node;
		this->last_element = new_node;
		this->size++;

		return NULL_TELEM;
	}




	for (int index = 0; index < this->size; index++)
	{

		if (element->i_index == i && element->j_index == j)
		{

			old_value = element->value;
			element->value = e;
			return old_value;

		}

		element=element->next;
	}


	element = this->first_element;

	for (int index = 0; index < size-1; index++)
	{
		element = element->next;
	}

	Node* new_node = new Node();
	new_node->value = e;
	new_node->previous = element;
	new_node->next = NULL;
	new_node->i_index = i;
	new_node->j_index = j;
	this->size++;
	element->next = new_node;
	this->last_element = new_node;

	return NULL_TELEM;


}
MatrixIterator Matrix::iterator() const {
	return MatrixIterator{ *this };
}


