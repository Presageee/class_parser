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

    void readInfo(std::ifstream &in)
    {
        char a_tmp[2];
        char l_tmp[4];
        in.read(a_tmp, 2);
        in.read(l_tmp, 4);
        this->attribute_name_index = _2_u2(a_tmp);
        this->attribute_length = _2_u4(l_tmp);
        this->info = new char[this->attribute_length + 1];
        info[this->attribute_length] = '\0';
        in.read(info, this->attribute_length);
    }
private:
    u2 attribute_name_index;
    u4 attribute_length;
    char *info;
};