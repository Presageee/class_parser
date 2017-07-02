#pragma once
#include "constant_info.h"

class constant_integer : public constant_info
{
public:
    constant_integer(u1 tag):constant_info(tag)
    {
        
    }

    void readInfo(std::ifstream &in)
    {
        char data[4];
        in.read(data, 4);
        this->val = _2_u4(data);
    }
private:
    u4 val;
};