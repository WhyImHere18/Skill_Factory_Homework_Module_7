#pragma once

class IntegerArray
{
private:
	int length_;
	int* data_;
public:
	IntegerArray() = default;
	
	IntegerArray(int length);

	IntegerArray(const IntegerArray& other);

	~IntegerArray() = default;

	int getLength() const;
	
	void erase();								// delete the array

	int& operator[](int index);					// re-defined operator [] - get the value by the index

	void reallocate(int newLength);				// re-allocate the array with the 'newLength' size 

	void resize(int newLength);					// resize the array

	void insertBefore(int index, int value);	// insert the 'value' before the value with the 'index'

	void remove(int index);				// remove a value with the 'index' from the array 

	void insertAtBegin(int value);		// insert the 'value' at the begin of the array

	void insertAtEnd(int value);		// insert the 'value' at the end of the array

	int searchByIndex(int index);		// search for a value by the 'index'

	void sortAscend();					// sort the array in ascending order

	void sortDescend();					// sort the array in descending order
};

