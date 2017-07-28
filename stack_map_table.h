#pragma once
#include "attribute_info.h"

class stack_map_table : public attribute_info
{
public:
    stack_map_table(u2 attribute_name_index) : attribute_info(attribute_name_index)
    {

    }

    void readInfo(std::ifstream &in)
    {
        attribute_info::readInfo(in);

        char tmp[2];
        in.read(tmp, 2);

        this->number_of_entries = _2_u2(tmp);
    }

    void display(const std::vector<constant_info*> &info)
    {

    }

private:
    u2 number_of_entries;


};