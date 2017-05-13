#pragma once
#include "common.h"
#include "attribute_info.h"
#include <fstream>

class field_info
{
public:
    friend void readInfo(const std::ifstream &in)
    {

    }
private:
    u2 access_flags;
    u2 name_index;
    u2 descriptor_index;
    u2 attributes_count;
    attribute_info *attributes;
};