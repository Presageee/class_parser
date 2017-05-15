#pragma once
#include "common.h"
#include "attribute_info.h"
#include <fstream>

class field_info
{
public:
    void readInfo(std::ifstream &in)
    {
        char tmp[2];
        in.read(tmp, 2);
        this->access_flags = _2_u2(tmp);
        in.read(tmp, 2);
        this->name_index = _2_u2(tmp);
        in.read(tmp, 2);
        this->descriptor_index = _2_u2(tmp);
        in.read(tmp, 2);
        this->attributes_count = _2_u2(tmp);
        this->attributes = new attribute_info[attributes_count];
        for (int i = 0; i < this->attributes_count; i++)
        {
            attribute_info* attr = new attribute_info();
            attr->readInfo(in);
            this->attributes[i] = *attr;
        }
    }
private:
    u2 access_flags;
    u2 name_index;
    u2 descriptor_index;
    u2 attributes_count;
    attribute_info *attributes;
};