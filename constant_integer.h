#pragma once
#include "constant_info.h"

class constant_integer : constant_info
{
public:
    friend void readInfo(const std::ifstream &in)
    {

    }
private:
    u4 val;
};