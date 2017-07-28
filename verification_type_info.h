#pragma once
#include "common.h"
#include <fstream>

class verification_type_info
{
public:
    verification_type_info() {};

    verification_type_info(u1 tag)
    {
        this->tag = tag;
    }

    virtual void readInfo(std::ifstream &in) {};

    virtual void display(std::vector<constant_info*> &info) {};

private:
    u1 tag;
};
