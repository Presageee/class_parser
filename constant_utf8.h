#pragma once
#include "constant_info.h"

class constant_utf8 : public constant_info
{
public:
	~constant_utf8()
	{
		if (nullptr != data)
		{
			delete[]data;
		}
	}
    
	friend void readInfo(const std::ifstream &in) 
	{
		char tmp[3];
		in.read(tmp, 2);
		this->length = _2_u2(tmp);
		char *buf = new char[this->length + 1];
        memset(buf, 0, this->length + 1);
		in.read(buf, this->len);
	}

private:
	u2 length;
	char *data;
};