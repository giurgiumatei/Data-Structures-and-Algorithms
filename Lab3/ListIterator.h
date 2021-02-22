#pragma once
#include "IteratedList.h"

//DO NOT CHANGE THIS PART
class IteratedList;
typedef int TElem;

class ListIterator{
	friend class IteratedList;
private:
	//TODO - Representation 

	//DO NOT CHANGE THIS PART
	const IteratedList& list;
	ListIterator(const IteratedList& list);
public:
	int array_index;
	void first();
	void next();
	void previous();
	bool valid() const;
    TElem getCurrent() const;
	
	
};


