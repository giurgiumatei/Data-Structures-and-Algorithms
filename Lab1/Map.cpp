#include <iostream>
#include "Map.h"
#include "MapIterator.h"
using namespace std;


Map::Map() {
	
	this->elements_counter = 0;
	this->capacity = 100;
	this->elements = (TElem*)malloc(this->capacity * sizeof(TElem));


}

Map::~Map() {
	cout << "Map was destroyed!"<<endl;
}

TValue Map::add(TKey c, TValue v){
	
	if (this->elements_counter == this->capacity)
	{
		this->capacity += 100;
		this->elements = (TElem*)realloc(this->elements,this->capacity * sizeof(TElem));

	}

	TElem new_element;

	new_element.first = c;
	new_element.second = v;
	
	if (this->search(c) == NULL_TVALUE)
	{
		this->elements[this->elements_counter] = new_element;
		this->elements_counter += 1;

	}

	else
	{

		int index = this->search_by_key(c);
		TValue old_value = this->elements[index].second;
		this->elements[index].second = v;
		return old_value;
		

	}




	return NULL_TVALUE;
}

int Map::search_by_key(TKey c)
{
	for (int i = 0; i < this->elements_counter; i++)
	{
		if (this->elements[i].first == c)
		{
			return i;

		}
	}

	return -1;
}

TValue Map::search(TKey c) const{
	for (int i = 0; i < this->elements_counter; i++)
	{
		if (this->elements[i].first == c)
		{
			return this->elements[i].second;

		}
	}
	return NULL_TVALUE;
}

TValue Map::remove(TKey c){


	int index = this->search_by_key(c);
	if (index == -1)
	{
		return NULL_TVALUE;
	}
	TValue old_value = this->elements[index].second;
	for (int i = index; i < this->elements_counter - 1; i++)
	{
		this->elements[i] = this->elements[i + 1];

	}

	this->elements_counter -= 1;

	return old_value;
	
}


int Map::size() const {
	//TODO - Implementation
	return this->elements_counter;
}

bool Map::isEmpty() const{
	//TODO - Implementation
	return this->elements_counter == 0;
}

MapIterator Map::iterator() const {
	return MapIterator(*this);
}

bool Map::filter(Condition cond,TElem element)
{
	
	if (cond(element.first) == true)
	{
		this->add(element.first, element.second);
		return true;
	}

	return false;
}

bool Map::Condition_Function(TKey c)
{
	if (c < 0)
	{
		return false;
	}

	return true;
}



