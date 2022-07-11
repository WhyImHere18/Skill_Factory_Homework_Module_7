#include "BadRange.h"

using namespace std;

BadRange::BadRange(int index) : index_(index) {}

int BadRange::getIndex() const
{
	return index_;
}