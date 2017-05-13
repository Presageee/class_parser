#pragma once
#include "common.h"
#include <fstream>

class attribute_info
{
public:
    ~attribute_info()
    {
        if (!info)
        {
            delete[]info;
        }
    }

    
private:
    u2 attribute_name_index;
    u4 attribute_length;
    u1 *info;
};