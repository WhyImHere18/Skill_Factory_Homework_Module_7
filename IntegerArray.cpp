#include "IntegerArray.h"
#include <exception>
#include <iostream>
#include "BadRange.h"
#include "BadLength.h"

using namespace std;

IntegerArray::IntegerArray(int length) : length_(length)
{
	if (length <= 0)
	{
		cout << "Bad length exception is occurred in the method 'IntegerArray(int length)': ";
		throw BadLength(length);
	}
	data_ = new int[length];
}

IntegerArray::IntegerArray(const IntegerArray& other)
{
	if (other.length_ <= 0)
	{
		cout << "Bad length exception is occurred in the method 'IntegerArray(int length)': ";
		throw BadLength(other.length_);
	}
	length_ = other.length_;
	data_ = other.data_;
}

IntegerArray::~IntegerArray()
{
	cout << endl;
	cout << "'~IntegerArray()' destructor is running..." << endl;
	cout << "length = " << length_ << endl;
	for (int i = 0; i < length_; i++)
	{
		cout << data_[i] << " ";
	}
	delete[] data_;
	cout << "The container is destroyed" << endl;
}

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
		cout << "Bad range exception is occurred in the method 'operator[]': ";
		throw BadRange(index);
	}
	return data_[index];
}

void IntegerArray::reallocate(int newLength)
{
	if (newLength <= 0)
	{
		cout << "Bad length exception is occurred in the method 'reallocate(int newLength)': ";
		throw BadLength(newLength);
	}

	erase();

	data_ = new int[newLength];
	length_ = newLength;
}

void IntegerArray::resize(int newLength)
{
	if (newLength < 0)
	{
		cout << "Bad length is occurred in the method 'resize(int newLength)': ";
		throw BadLength(newLength);
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
		cout << "Bad range exception is occurred in the method 'insertBefore(int index, int value)': ";
		throw BadRange(index);
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
		cout << "Bad range exception is occurred in the method 'remove(int index)': ";
		throw BadRange(index);
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
		cout << "Bad range exception is occurred in the method 'searchByIndex(int index)': ";
		throw BadRange(index);
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