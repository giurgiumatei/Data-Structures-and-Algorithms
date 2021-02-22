#include "Map.h"
#include "MapIterator.h"
#include <exception>
#include <stdexcept>
using namespace std;


MapIterator::MapIterator(const Map& d) : map(d)
{
	

	this->position = 0;
	this->elements_iterated = 0;
}


void MapIterator::first() {
	this->position = 0;
	this->elements_iterated = 0;
}


void MapIterator::next() {

	if (!this->valid())
	{
		throw std::invalid_argument("");

	}

	this->position++;
	this->elements_iterated++;


}


TElem MapIterator::getCurrent(){
	if (!this->valid())
	{
		throw std::invalid_argument("");

	}
	return this->map.elements[this->position];
}


bool MapIterator::valid() const {
	return this->position < this->map.elements_counter;
}



