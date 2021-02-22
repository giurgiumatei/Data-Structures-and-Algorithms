#include "ListIterator.h"
#include "IteratedList.h"
#include <exception>

ListIterator::ListIterator(const IteratedList& list) : list(list) {
	this->array_index = this->list.head;
}

void ListIterator::first() {
	this->array_index = this->list.head;
}

void ListIterator::next() {
	if (this->list.size_of_array == 0 || !(this->valid()))
	{

		throw std::exception();
	}


	this->array_index = this->list.DLLANodes[this->array_index]->next;
}

void ListIterator::previous() // new functionality, complexity Theta(1)
{
	if (this->list.size_of_array == 0 || !(this->valid()))
	{

		throw std::exception();
	}

	this->array_index = this->list.DLLANodes[this->array_index]->previous;

}

bool ListIterator::valid() const {
	TElem empty;
	empty = NULL_TELEM;
	
	if (this->list.size_of_array == 0 || this->list.DLLANodes[array_index]->info == empty)
	{
		return false;
	}
	return true;
}

TElem ListIterator::getCurrent() const {
	if (this->valid())
	{

		return this->list.DLLANodes[this->array_index]->info;
	}

	throw std::exception();
}






