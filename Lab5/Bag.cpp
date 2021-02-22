#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
#include <cmath>
using namespace std;

//O(n)
Bag::Bag() {
	capacity = 10;
	size_of_hashtable = 0;
	hashtable = new Node * [capacity];
	for (int i = 0; i < capacity; ++i) {
		hashtable[i] = nullptr;
	}
}

//theta(1)
void Bag::add(TElem elem) {
	if ((float)size_of_hashtable / (float)capacity >= ALPHA) {
		resize(2 * capacity);
	}
	auto position = hash_function(elem);
	auto new_node = new Node;
	new_node->value = elem;
	new_node->next = hashtable[position];
	hashtable[position] = new_node;
	size_of_hashtable++;
}

//WC=theta(m), AC=O(n), BC=theta(1)
bool Bag::remove(TElem elem) {
	if (size_of_hashtable == 0) {
		return false;
	}
	auto current_node = hashtable[hash_function(elem)];
	Node* previous_node = nullptr;
	bool exists = false;
	while (current_node != nullptr) {
		if (current_node->value == elem) {
			if (previous_node == nullptr) {
				hashtable[hash_function(elem)] = current_node->next;
				delete current_node;
			}
			else {
				previous_node->next = current_node->next;
				delete current_node;
			}
			size_of_hashtable--;
			exists = true;
			break;
		}
		previous_node = current_node;
		current_node = current_node->next;
	}
	return exists;
}

//WC=theta(m), AC=O(n), BC=theta(1)
bool Bag::search(TElem elem) const {
	if (size_of_hashtable == 0) {
		return false;
	}
	auto current_node = hashtable[hash_function(elem)];
	while (current_node != nullptr) {
		if (current_node->value == elem) {
			return true;
		}
		current_node = current_node->next;
	}
	return false;
}
//WC=theta(m), AC=O(n), BC=theta(1)
int Bag::nrOccurrences(TElem elem) const {
	int position = hash_function(elem);
	auto current_node = hashtable[position];
	int occurrences = 0;
	while (current_node != nullptr) {
		if (current_node->value == elem) {
			occurrences++;
		}
		current_node = current_node->next;
	}
	return occurrences;
}

//theta(1)
int Bag::size() const {
	return size_of_hashtable;
}

//theta(1)
bool Bag::isEmpty() const {
	
	if (size_of_hashtable == 0)
	{
		return true;
	}
	
	return false;
}

//theta(1)
BagIterator Bag::iterator() const {
	return BagIterator(*this);
}

//theta(m)
Bag::~Bag() {
	for (int i = 0; i < capacity; ++i) {
		auto current_node = hashtable[i];
		while (current_node != nullptr) {
			auto previous_node = current_node;
			current_node = current_node->next;
			delete previous_node;
		}
	}
	delete[]hashtable;
}

//BC=theta(1), AC=O(n), WC=theta(m)
int Bag::removeAllOccurrences(TElem elem)
{
	int number_of_occurences = this->nrOccurrences(elem);
	int number_returned = number_of_occurences;
	while (number_of_occurences)
	{
		this->remove(elem);
		number_of_occurences--;


	}

	return number_returned;
}


//theta(m)
void Bag::resize(int new_capacity) 
{
	Node** new_hashtable = new Node * [new_capacity];
	for (int i = 0; i < new_capacity; ++i) {
		new_hashtable[i] = nullptr;
	}
	auto old_capacity = capacity;
	capacity = new_capacity;
	for (int i = 0; i < old_capacity; ++i) {
		auto current_node = hashtable[i];
		while (current_node != nullptr) {
			auto previous_node = current_node;
			auto position = hash_function(current_node->value);
			Node* newNode = new Node;
			newNode->next = new_hashtable[position];
			newNode->value = current_node->value;
			new_hashtable[position] = newNode;
			current_node = current_node->next;
			delete previous_node;
		}
	}
	delete[]hashtable;
	hashtable = new_hashtable;
}

//theta(1)
int Bag::hash_function(TElem elem) const //hash function using a simple division
{

	return abs(elem % capacity);
}