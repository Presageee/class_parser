#pragma once

#include "constant_info.h"

class constant_invoke_dynamic : public constant_info
{
public:
    constant_invoke_dynamic(u1 tag):constant_info(tag)
    {
        
    }
    void readInfo(std::ifstream &in)
    {
        char b_tmp[2];
        char n_tmp[2];
        in.read(b_tmp, 2);
        in.read(n_tmp, 2);
        this->bootstrap_method_attr_index = _2_u2(b_tmp);
        this->name_and_type_index = _2_u2(n_tmp);
    }
private:
    u2 bootstrap_method_attr_index;
    u2 name_and_type_index;
};