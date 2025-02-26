#include "SortedSet.h"
#include "SortedSetIterator.h"
#include "ShortTest.h"
#include "ExtendedTest.h"
#include <assert.h>
#include <iostream>
bool r3(TComp e1, TComp e2) {
	if (e1 <= e2) {
		return true;
	}
	else {
		return false;
	}
}
int main() {
	testAll();
	testAllExtended();
}