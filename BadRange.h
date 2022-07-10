#pragma once
#include <exception>
using namespace std;

class BadRange : public exception
{
private:
	int index_;
public:
	BadRange(int index);
	virtual const char* what() const noexcept override;
	int getIndex() const;
	~BadRange() = default;
};

