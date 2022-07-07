#include "ExceptionCode.h"
#include <iostream>

using namespace std;

ExceptionCode::ExceptionCode(int code) : code_(code)
{

}

int ExceptionCode::getCode() const
{
	return code_;
}


