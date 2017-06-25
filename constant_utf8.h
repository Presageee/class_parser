#pragma once
#include "constant_info.h"

class constant_utf8 : public constant_info
{
public:
    constant_utf8(u1 tag)
    {
        constant_info(tag);
    }
	~constant_utf8()
	{
		if (nullptr != data)
		{
			delete[]data;
		}
	}
    
	void readInfo(std::ifstream &in) 
	{
		char tmp[3];
		in.read(tmp, 2);
		this->length = _2_u2(tmp);
		this->data = new char[this->length + 1];
    memset(this->data, 0, this->length + 1);
		in.read(this->data, this->length);
	}

private:
	u2 length;
	char *data;
};