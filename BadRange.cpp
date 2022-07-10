#include "BadRange.h"

using namespace std;

BadRange::BadRange(int index) : index_(index)
{

}

const char* BadRange::what() const noexcept
{
	return "Bad index";
}

int BadRange::getIndex() const
{
	return index_;
}


