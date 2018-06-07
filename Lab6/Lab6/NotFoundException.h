#pragma once
#ifndef _NOTFOUNDEXCEPTION
#define _NOTFOUNDEXCEPTION

#include <stdexcept>
#include <string>

using namespace std;

class NotFoundException : public logic_error
{
public:
	NotFoundException(const string& message = "");
};
#endif // !_NOTFOUNDEXCEPTION
