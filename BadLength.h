#pragma once
#include <exception>

using namespace std;

class BadLength : public exception
{
private:
	int length_;
public:
	BadLength(int length);
	~BadLength() = default;
	int getLength() const;

};

