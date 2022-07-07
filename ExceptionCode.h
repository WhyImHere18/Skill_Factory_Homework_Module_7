#pragma once
#include <exception>
using namespace std;

class ExceptionCode : public exception
{
private:
	int code_;
public:
	ExceptionCode(int code);
	int getCode() const;
	~ExceptionCode() = default;
};

