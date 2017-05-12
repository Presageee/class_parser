#pragma once
#include "constant_info.h"

class constant_integer : constant_info
{
public:
    friend void readInfo(const std::ifstream &in)
    {
        char data[4];
        in.read(data, 4);
        this->val = _2_u4(data);
    }
private:
    u4 val;
};