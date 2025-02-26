#include "SortedSet.h"
#include "SortedSetIterator.h"
#include <iostream>

SortedSet::SortedSet(Relation r1) {
	cap = 5;
	elements = new TElem[cap];
	s = 0;
	r = r1;

}
//constant;
SortedSet::~SortedSet() {
	free(elements);
}
//constant;
bool SortedSet::add(TComp elem) {
	int x = 0;
	if (!search(elem)) {
		if (isEmpty()) {
			s++;
			elements[0] = elem;
			return true;
		}
		else {
			for (int i = 0;i < s;i++)
				if (r(elem, elements[i])) {
					x = 1;
					if (s+1 == cap) {
						cap = cap * 2;
						TElem* newarray = new TElem[cap];
						for (int c = 0;c < s ;c++)
							newarray[c] = elements[c];
						delete [] elements;
						elements = newarray;
					}
					s++;
					for (int j = s-1 ;j > i;j--)
						elements[j] = elements[j - 1];
					elements[i] = elem;
					return true;
				}
				if(x==0){
					if (s + 1 == cap) {
						cap = cap * 2;
						TElem* newarray = new TElem[cap];
						for (int c = 0;c < s;c++)
							newarray[c] = elements[c];
						delete[] elements;
						elements = newarray;
					}
					s++;
					elements[s-1] = elem;
					return true;
				}
		}
	}
	else return false;
}
//worst case:constant;
//best case:thata(n);
void SortedSet::print() {
	std::cout << "The elements of the set are: \n";
	for (int i = 0;i <= s - 1;i++)
		std::cout << elements[i] << " ";
}
//O(n);

bool SortedSet::remove(TComp elem) {
	for(int i=0; i<s;i++)
		if (elements[i] == elem) {
			for (int j = i;j < s;j++)
				elements[j] = elements[j + 1];
			elements[s-1] = NULL;
			s = s - 1;
			return true;
		}
	return false;
}
//worst case:constant;
//best case:thata(n);
int SortedSet::size()const {
	return s;
}
//constant


bool SortedSet::search(TElem elem) const {
	for (int i = 0;i <= s - 1;i++)
		if (elements[i] == elem)
			return true;
	return false;
}
//O(n)
SortedSetIterator SortedSet::iterator() const {
	return SortedSetIterator(*this);
}
//constant

bool SortedSet::isEmpty() const {
	if (s == 0)
		return true;
	else return false;
}
//constant