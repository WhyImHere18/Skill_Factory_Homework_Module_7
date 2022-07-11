#include "BadLength.h"

BadLength::BadLength(int length) : length_(length)
{

}

int BadLength::getLength() const
{
	return length_;
}
