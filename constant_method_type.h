#pragma once
#include "constant_info.h"

class constant_method_type : public constant_info
{
public:
    constant_method_type(u1 tag):constant_info(tag)
    {
        
    }

    void readInfo(std::ifstream &in)
    {
        char tmp[2];
        in.read(tmp, 2);
        this->description_index = _2_u2(tmp);
    }

    void display(const std::vector<constant_info*> &info)
    {
        if (ERR == CHECK_INDEX(description_index))
        {
            PRINT("[error] >>> index out of -1");
            exit(0);
        }

        u2 real_description_index = description_index - 1;

        if (OK == CHECK_INDEX(real_description_index))
        {
            //info[real_class_index]->display(info);
            std::cout << "#" << real_description_index << ",";
        }

    }
private:
    // description_index is method description
    u2 description_index;
};