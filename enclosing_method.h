#pragma once
#include "attribute_info.h"

class enclosing_method : public attribute_info
{
public:
    enclosing_method(u2 attribute_name_index) :attribute_info(attribute_name_index) {};

    void readInfo(std::ifstream &in)
    {
        attribute_info::readInfo(in);

        char byte[2];
        in.read(byte, 2);
        class_index = _2_u2(byte);

        in.read(byte, 2);
        method_index = _2_u2(byte);
    }

    void display(const std::vector<constant_info*> &info)
    {
        std::cout << "EnclosingMethod:" << std::endl;
        std::cout << std::setw(20) << "Class";
        if (ERR == CHECK_INDEX(class_index))
        {
            PRINT("[error] >>> index out of -1");
            exit(0);
        }

        u2 real_class_index = class_index - 1;

        if (OK == CHECK_INDEX(real_class_index))
        {
            std::string msg("#");
            std::cout << std::setw(20) << msg.append(std::to_string(real_class_index));
        }
        std::cout << std::endl;

        std::cout << std::setw(20) << "Method";
        if (ERR == CHECK_INDEX(method_index))
        {
            PRINT("[error] >>> index out of -1");
            exit(0);
        }

        u2 real_method_index = method_index - 1;

        if (OK == CHECK_INDEX(real_method_index))
        {
            std::string msg("#");
            std::cout << std::setw(20) << msg.append(std::to_string(real_method_index));
        }
        std::cout << std::endl;
    }
private:
    u2 class_index;
    u2 method_index;
};