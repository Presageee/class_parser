#pragma once
#include "common.h"
#include <fstream>
class constant_info
{
public:
    constant_info()
    {

    }
	constant_info(u1 tag)
	{
		this->tag = tag;
	}
    virtual void readInfo(std::ifstream &in) {};
private:
	u1 tag;
};