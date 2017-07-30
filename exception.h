#pragma once
#include "attribute_info.h"

class exception : public attribute_info
{
public:
    exception(u2 attribute_name_index) :attribute_info(attribute_name_index) {};

    void readInfo(std::ifstream &in)
    {
        attribute_info::readInfo(in);

        char number[2];
        in.read(number, 2);
        number_of_exceptions = _2_u2(number);

        char byte[2];
        for (int i = 0; i < number_of_exceptions; i++)
        {
            u2* index = nullptr;

            in.read(byte, 2);
            *index = _2_u2(byte);

            exception_indexs.push_back(index);
        }
    }

    void display(const std::vector<constant_info *> &info)
    {
        for (auto &val : exception_indexs)
        {
            std::cout << std::setw(20) << "Exception";
            if (ERR == CHECK_INDEX(*val))
            {
                PRINT("[error] >>> index out of -1");
                exit(0);
            }

            u2 real_exception_index = *val - 1;

            if (OK == CHECK_INDEX(real_exception_index))
            {
                //info[real_class_index]->display(info);
                std::string msg("#");
                std::cout << std::setw(20) << msg.append(std::to_string(real_exception_index));
            }
        }
    }
private:
    u2 number_of_exceptions;
    std::vector<u2 *> exception_indexs;
};