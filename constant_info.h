#pragma once
#include "common.h"
#include <fstream>
#include <vector>
#include <iomanip>

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

    virtual void display(const std::vector<constant_info*> &info) {};
  
    virtual void outputVal(const std::vector<constant_info*> &info) {};
private:
	u1 tag;
};