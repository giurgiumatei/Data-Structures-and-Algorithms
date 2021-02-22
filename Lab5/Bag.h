#pragma once
//DO NOT INCLUDE BAGITERATOR


//DO NOT CHANGE THIS PART
#define NULL_TELEM -111111;
#define ALPHA 0.50
typedef int TElem;
class BagIterator; 
class Bag;
typedef int (Bag::* HashFunction)(TElem);

class Node
{
public:
	TElem value;
	Node* next;

};


class Bag {

private:
	//TODO - Representation


	//DO NOT CHANGE THIS PART
	void resize(int new_capacity);
	//	HashFunction h;
	Node** hashtable;
	int capacity;//n
	int size_of_hashtable; //m
	//DO NOT CHANGE THIS PART
	friend class BagIterator;
	int hash_function(TElem elem) const;
public:
	//constructor
	Bag();

	//adds an element to the bag
	void add(TElem e);

	//removes one occurence of an element from a bag
	//returns true if an element was removed, false otherwise (if e was not part of the bag)
	bool remove(TElem e);

	//checks if an element appearch is the bag
	bool search(TElem e) const;

	//returns the number of occurrences for an element in the bag
	int nrOccurrences(TElem e) const;

	//returns the number of elements from the bag
	int size() const;

	//returns an iterator for this bag
	BagIterator iterator() const;

	//checks if the bag is empty
	bool isEmpty() const;

	//destructor
	~Bag();

	int removeAllOccurrences(TElem elem); //new functionality
};