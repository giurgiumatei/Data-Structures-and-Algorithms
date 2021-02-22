#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;

//WC=theta(m), AC=O(n), BC=theta(1)
BagIterator::BagIterator(const Bag& c): bag(c)
{
	if (bag.isEmpty()) {
		current_key = -1;
		current_value = nullptr;
	}
	else {
		current_key = 0;
		while (current_key < bag.capacity and bag.hashtable[current_key] == nullptr) {
			current_key++;
		}
		current_value = bag.hashtable[current_key];
	}
}

//theta(1)
void BagIterator::first() {
	if (bag.isEmpty()) {
		throw std::exception();
	}
	current_key = 0;
	while (bag.hashtable[current_key] == nullptr) {
		current_key++;
	}
	current_value = bag.hashtable[current_key];
}

//WC=theta(m), AC=O(n), BC=theta(1)
void BagIterator::next() {
	if (current_key == -1 or current_value == nullptr) {
		throw std::exception();
	}
	current_value = current_value->next;
	if (current_value == nullptr) {
		current_key++;
		while (current_key < bag.capacity and bag.hashtable[current_key] == nullptr) {
			current_key++;
		}
		if (current_key == bag.capacity) {
			current_key = -1;
		}
		else {
			current_value = bag.hashtable[current_key];
		}
	}
}

//theta(1)
bool BagIterator::valid() const {
	return current_key != -1 and current_value != nullptr;
}



//theta(1)
TElem BagIterator::getCurrent() const
{
	if (current_key == -1) {
		throw std::exception();
	}
	return current_value->value;
}
