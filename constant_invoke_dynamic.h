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

    void display(const std::vector<constant_info*> &info)
    {

        std::cout << std::setw(20) << "InvokeHandler";

        if (ERR == CHECK_INDEX(bootstrap_method_attr_index))
        {
            PRINT("[error] >>> index out of -1");
            exit(0);
        }

        u2 real_bootstrap_method_attr_index = bootstrap_method_attr_index - 1;

        if (OK == CHECK_INDEX(real_bootstrap_method_attr_index))
        {
            std::string msg("#");
            std::cout << std::setw(20) << msg.append(std::to_string(real_bootstrap_method_attr_index)) << ",";

        }

        if (ERR == CHECK_INDEX(name_and_type_index))
        {
            PRINT("[error] >>> index out of -1");
            exit(0);
        }

        u2 real_name_and_type_index = name_and_type_index - 1;

        if (OK == CHECK_INDEX(real_name_and_type_index))
        {
            std::cout << "#" << real_name_and_type_index;
        }
    }
private:
    u2 bootstrap_method_attr_index;
    u2 name_and_type_index;
};