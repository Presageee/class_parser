#pragma once
#include "common.h"
#include <fstream>

class attribute_info
{
public:
    attribute_info()
    {

    }
    attribute_info(u2 attribute_name_index)
    {
        this->attribute_name_index = attribute_name_index;
    }
    ~attribute_info()
    {
       
    }

   virtual void readInfo(std::ifstream &in)
    {
        char l_tmp[4];
        in.read(l_tmp, 4);
        this->attribute_length = _2_u4(l_tmp);
    }

    virtual void disaply(const std::vector<constant_info*> &info)
    {
        if (ERR == CHECK_INDEX(attribute_name_index))
        {
            PRINT("[error] >>> index out of -1");
            exit(0);
        }

        u2 real_attribute_name_index = attribute_name_index - 1;

        if (OK == CHECK_INDEX(real_attribute_name_index))
        {
            //std::cout << std::setw(20) << "#" << real_attribute_name_index;
            info[real_attribute_name_index]->outputVal(info);
        }

    }

private:
    u2 attribute_name_index;
    u4 attribute_length;
};