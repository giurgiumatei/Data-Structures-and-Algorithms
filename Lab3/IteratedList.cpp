
#include <exception>
#include "ListIterator.h"
#include "IteratedList.h"

IteratedList::IteratedList() {
	this->capacity = 500000;
	this->size_of_array = 0;
	this->DLLANodes = new DLLANode * [this->capacity];
	this->first_empty = 0;
	this->head = 0;
	this->tail = 0;
	this->list_index = 0;
	DLLANode* emptynode = new DLLANode();
	for (int i = 0; i < this->capacity; i++)
	{
		emptynode->next = i + 1;
		emptynode->info = NULL_TELEM;
		emptynode->previous = i - 1;
		this->DLLANodes[i] = emptynode;
	}
}
void IteratedList::resize()
{
	this->capacity *= 2;
	DLLANode* emptynode = new DLLANode();

	DLLANode** glass = new DLLANode * [this->capacity];

	for (int i = 0; i < this->size_of_array; i++)
	{
		glass[i] = this->DLLANodes[i];
	}

	delete[] this->DLLANodes;

	for (int i = 0; i <= this->capacity; i++)
	{

		emptynode->next = i + 1;
		emptynode->info = NULL_TELEM;
		emptynode->previous = i - 1;
		this->DLLANodes[i] = emptynode;
	}

	this->DLLANodes = glass;


}

int IteratedList::array_to_list_index(int array_index)
{
	if (array_index < 0 || array_index < this->capacity)

	{

		return -1;
	}
	TElem empty = NULL_TELEM;

	int parse_index = this->head, l_index = 0;

	while (parse_index != array_index)
	{
		l_index++;
		parse_index = this->DLLANodes[parse_index]->next;

	}

	return l_index;
}

int IteratedList::list_to_array_index(int list_index)
{

	int a_index = this->head;
	TElem empty = NULL_TELEM;

	if (this->DLLANodes[a_index]->info == empty)
	{
		return -1;
	}


	while (list_index)
	{
		list_index--;
		a_index = this->DLLANodes[a_index]->next;
		if (this->DLLANodes[a_index]->info == empty)
		{
			return -1;
		}

	}

	return a_index;
}

int IteratedList::first_empty_function()
{
	TElem empty = NULL_TELEM;
	for (int i = 0; i < this->capacity; i++)
	{
		if (this->DLLANodes[i]->info == empty)
		{
			return i;
		}
	}
	return -1;
}

void IteratedList::addExtraCase(TElem e)
{
	DLLANode* new_node = new DLLANode();
	int f_empty = this->first_empty_function();
	new_node->info = e;
	new_node->previous = -1;
	this->DLLANodes[f_empty] = new_node;
	this->DLLANodes[f_empty]->next = first_empty_function();
	
	this->size_of_array++;



}

TElem IteratedList::remove_head(ListIterator& pos)//90% sigur
{
	TElem old_element;

	old_element = this->DLLANodes[this->head]->info;
	this->DLLANodes[this->head]->info = NULL_TELEM;
	if (this->size_of_array != 1)
	{
		this->head = this->DLLANodes[this->head]->next;
		this->DLLANodes[this->head]->previous = -1;
	}
	else
	{
		this->head = 0;
		this->tail = 0;
	}
	this->size_of_array--;
	return old_element;
}

TElem IteratedList::remove_tail(ListIterator& pos)
{
	
	TElem old_element;
	old_element = this->DLLANodes[this->tail]->info;
	this->DLLANodes[this->tail]->info = NULL_TELEM;
	this->tail = this->DLLANodes[this->tail]->previous;
	this->DLLANodes[this->tail]->next = this->first_empty_function();
	this->size_of_array--;
	return old_element;



}

int IteratedList::size() const {
	return this->size_of_array;
}

bool IteratedList::isEmpty() const {
	if (this->size_of_array == 0)
	{
		return true;
	}
	return false;
}

ListIterator IteratedList::first()  {

	
	return ListIterator(*this);
}

TElem IteratedList::getElement(ListIterator pos) const {
	if (!pos.valid())
	{
		throw std::exception();
	}
	return pos.getCurrent();
}

TElem IteratedList::remove(ListIterator& pos) {
	if (!pos.valid())
	{
		throw std::exception();
	}

	if (pos.array_index == this->head)
	{
		return this->remove_head(pos);
	}

	if (pos.array_index == this->tail)
	{
		return this->remove_tail(pos);
	}
	

	TElem old_element;



	
	int preceding_element_array_index = this->DLLANodes[pos.array_index]->previous;
	int succeding_element_array_index= this->DLLANodes[pos.array_index]->next;
	
	old_element = this->DLLANodes[pos.array_index]->info;
	this->DLLANodes[pos.array_index]->info = NULL_TELEM;
	this->DLLANodes[preceding_element_array_index]->next = this->DLLANodes[pos.array_index]->next;
	this->DLLANodes[succeding_element_array_index]->previous = this->DLLANodes[pos.array_index]->previous;
	pos.array_index=this->DLLANodes[pos.array_index]->next;

	this->size_of_array--;



	return old_element;
}

ListIterator IteratedList::search(TElem e) { // ?
	ListIterator it = this->first();

	try {

		while (it.getCurrent() != e)
		{
			it.next();

		}
	}
	catch (std::exception&) 
	{
		return it;
	}

	return it;
}

TElem IteratedList::setElement(ListIterator pos, TElem e) {
	
	TElem old_element;
	if (!pos.valid())
	{
		throw std::exception();
	}
	old_element = this->DLLANodes[pos.array_index]->info;
	this->DLLANodes[pos.array_index]->info = e;


	return old_element;


}

void IteratedList::addToPosition(ListIterator& pos, TElem e) {
	if (!pos.valid())
	{
		throw std::exception();
	}



	if (this->size_of_array + 1 == this->capacity)
	{
		this->resize();
	}

	

	if (pos.array_index== tail)
	{
		this->addToEnd(e);
		return;
	}


	int preceding_element_array_index = this->DLLANodes[pos.array_index]->previous;
	int succeding_element_array_index = this->DLLANodes[pos.array_index]->next;
	DLLANode* new_node = new DLLANode();
	int f_empty = this->first_empty_function();
	new_node->info = e;
	new_node->previous = pos.array_index;
	new_node->next = this->DLLANodes[pos.array_index]->next;
	this->DLLANodes[succeding_element_array_index]->previous = f_empty;
	this->DLLANodes[f_empty] = new_node;

	this->DLLANodes[pos.array_index]->next = f_empty;
	
	
	pos.array_index = f_empty;
	this->DLLANodes[this->tail]->next = this->first_empty_function();

	

	this->size_of_array++;


}

void IteratedList::addToEnd(TElem e) {
	if(this->size_of_array + 1 == this->capacity)
	{
		this->resize();
	}
	
	if (this->size_of_array == 0)
	{
		this->addExtraCase(e);
		return;
	}
	

	DLLANode* new_node = new DLLANode();
	int f_empty = this->first_empty_function();
	
	new_node->info = e;
	new_node->previous = this->tail;
	this->DLLANodes[f_empty] = new_node;
	this->DLLANodes[f_empty]->next = this->first_empty_function();
	this->DLLANodes[this->tail]->next = f_empty;
	this->tail = f_empty;
	this->size_of_array++;

}

void IteratedList::addToBeginning(TElem e)
{

	if (this->size_of_array + 1 == this->capacity)
	{
		this->resize();
	}

	
	if (this->size_of_array == 0)
	{
		this->addExtraCase(e);
		return;
	}
	
	DLLANode* new_node = new DLLANode();
	int f_empty = this->first_empty_function();
	new_node->info = e;
	new_node->previous = -1;
	new_node->next = this->head;
	this->DLLANodes[f_empty] = new_node;
	this->DLLANodes[this->head]->previous = f_empty;
	
	this->head = f_empty;
	this->DLLANodes[this->tail]->next = this->first_empty_function();


	this->size_of_array++;

}

IteratedList::~IteratedList() {
	delete[] this->DLLANodes;
}
