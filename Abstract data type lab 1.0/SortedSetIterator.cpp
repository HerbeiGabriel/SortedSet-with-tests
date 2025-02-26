#include "SortedSetIterator.h"
#include <exception>
#include <iostream>

using namespace std;

SortedSetIterator::SortedSetIterator(const SortedSet& m) : multime(m)
{
	index = 0;
}
//constant;


void SortedSetIterator::first() {
	index = 0;
}
//constant;


void SortedSetIterator::next() {;
	if (!valid()) {
		throw std::invalid_argument("invalid_index");
	}
	index++;
}
//constant;


TElem SortedSetIterator::getCurrent()
{
	if (!valid()) {
		throw std::invalid_argument("invalid_index");
	}
	else return multime.elements[index];
	
}
//constant;

bool SortedSetIterator::valid() const {
	if (index >= 0 && index < multime.size())
		return true;
	return false;
}
//constant;
