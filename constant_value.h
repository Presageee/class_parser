#pragma once
#include "attribute_info.h"

class constant_value : public attribute_info
{
public:
    constant_value(u2 attribute_name_index) :attribute_info(attribute_name_index)
    {

    }

    void readInfo(std::ifstream &in)
    {
        attribute_info::readInfo(in);
        char tmp[2];
        in.read(tmp, 2);
        this->constant_value_index = _2_u2(tmp);
    }

    void display(const std::vector<constant_info*> &info)
    {

    }
private:
    u2 constant_value_index;
};