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
		this->len = (u1)tmp[0] << 8 | (u1)tmp[1];
		char *buf = new char[this->len + 1];
		in.read(buf, this->len);
	}

private:
	u2 len;
	char *data;
};