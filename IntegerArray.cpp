#include "IntegerArray.h"
#include <exception>
#include <iostream>
#include "ExceptionCode.h"

using namespace std;

IntegerArray::IntegerArray(int length) : length_(length)
{
	if (length <= 0)
	{
		cout << "Bad length exception is occured in the method 'IntegerArray(int length)': ";
		cout << "bad length = ";
		//throw "bad_length";
		throw ExceptionCode(length);
	}
	data_ = new int[length];
}

IntegerArray::IntegerArray(const IntegerArray& other)
{
	if (other.length_ <= 0)
	{
		cout << "Bad length exception is occured in the method 'IntegerArray(int length)': ";
		cout << "bad length = ";
		//throw "bad_length";
		throw ExceptionCode(other.length_);
	}
	length_ = other.length_;
	data_ = other.data_;
}

/*IntegerArray::~IntegerArray()
{
	delete[] data_;
}*/

int IntegerArray::getLength() const
{
	return length_;
}

void IntegerArray::erase()
{
	delete[] data_;
	data_ = nullptr;
	length_ = 0;
}

int& IntegerArray::operator[](int index)
{
	if (index < 0 || index >= length_)
	{
		cout << "Bad range exception is occured in the method 'operator[]': ";
		cout << "bad index = ";
		throw ExceptionCode(index);
		//throw "bad_range";
	}
	return data_[index];
}

void IntegerArray::reallocate(int newLength)
{
	if (newLength <= 0)
	{
		cout << "Bad length exception is occured in the method 'reallocate(int newLength)': ";
		cout << "bad length = ";
		//throw "bad_length";
		throw ExceptionCode(newLength);
	}

	erase();

	data_ = new int[newLength];
	length_ = newLength;
}

void IntegerArray::resize(int newLength)
{
	if (newLength < 0)
	{
		cout << "Exception is occured in the method 'resize(int newLength)': ";
		cout << "bad length = ";
		//throw "bad_length";
		throw ExceptionCode(newLength);
	}

	if (newLength == length_)
	{
		return;
	}

	if (newLength == 0)
	{
		erase();
		return;
	}

	int* tmp = new int[length_];

	if (length_ > 0)
	{
		int num = 0;
		if (newLength > length_)
		{
			num = length_;
		}
		else
		{
			num = newLength;
		}
		for (int i = 0; i < num; i++)
		{
			tmp[i] = data_[i];
		}

		delete[] data_;
		data_ = tmp;
		length_ = newLength;
	}
}

void IntegerArray::insertBefore(int index, int value)
{
	if (index < 0 || index >= length_)
	{
		cout << "Bad range exception is occured in the method 'insertBefore(int index, int value)': ";
		cout << "bad index = ";
		throw ExceptionCode(index);
		//throw "bad_range";
	}
	int* tmp = new int[length_ + 1];
	for (int i = 0; i < index; ++i)
	{
		tmp[i] = data_[i];
	}

	tmp[index] = value;

	for (int i = index; i < length_; ++i)
	{
		tmp[i + 1] = data_[i];
	}

	delete[] data_;
	data_ = tmp;
	length_ = length_ + 1;
}

void IntegerArray::remove(int index)
{
	if (index < 0 || index >= length_)
	{
		cout << "Bad range exception is occured in the method 'remove(int index)': ";
		cout << "bad index = ";
		throw ExceptionCode(index);
		//throw "bad_range";
	}
	if (length_ == 1)
	{
		erase();
		return;
	}

	int* tmp = new int[length_ - 1];

	for (int i = 0; i < index; i++)
	{
		tmp[i] = data_[i];
	}

	for (int i = index; i < length_ - 1; i++)
	{
		tmp[i] = data_[i + 1];
	}

	delete[] data_;
	data_ = tmp;
	length_ = length_ - 1;
}

void IntegerArray::insertAtBegin(int value)
{
	insertBefore(0, value);
}

void IntegerArray::insertAtEnd(int value)
{
	int* tmp = new int[length_ + 1];
	for (int i = 0; i < length_; i++)
	{
		tmp[i] = data_[i];
	}

	tmp[length_] = value;

	for (int i = length_; i < length_; i++)
	{
		tmp[i + 1] = data_[i];
	}

	delete[] data_;
	data_ = tmp;
	length_ = length_ + 1;
}

int IntegerArray::searchByIndex(int index)
{
	if (index < 0 || index >= length_)
	{
		cout << "Bad range exception is occured in the method 'searchByIndex(int index)': ";
		cout << "bad index = ";
		throw ExceptionCode(index);
		throw "bad_range";
	}

	int num = 0;

	for (int i = 0; i < length_; i++)
	{
		if (index == i)
		{
			num = data_[i];
		}
	}
	return num;
}

void IntegerArray::sortAscend()
{
	for (int i = 0; i < length_; i++)
		for (int j = i + 1; j < length_; j++)
		{
			if (data_[i] > data_[j])
			{
				data_[i] ^= data_[j];
				data_[j] ^= data_[i];
				data_[i] ^= data_[j];
			}
		}
}

void IntegerArray::sortDescend()
{
	for (int i = 0; i < length_; i++)
		for (int j = i + 1; j < length_; j++)
		{
			if (data_[j] > data_[i])
			{
				data_[j] ^= data_[i];
				data_[i] ^= data_[j];
				data_[j] ^= data_[i];
			}
		}
}