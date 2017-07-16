#pragma once
#include "common.h"
#include "attribute_info.h"
#include <fstream>
#include <vector>

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
        for (int i = 0; i < this->attributes_count; i++)
        {
            attribute_info* attr = new attribute_info();
            attr->readInfo(in);
            this->attributes.push_back(attr);
        }
    }

    void display(const std::vector<constant_info*> &info)
    {
        printAccessFlags();

        if (ERR == CHECK_INDEX(name_index))
        {
            PRINT("[error] >>> index out of -1");
            exit(0);
        }

        u2 real_name_index = name_index - 1;

        if (OK == CHECK_INDEX(real_name_index))
        {
            std::cout << "#" << real_name_index;
        }

        if (ERR == CHECK_INDEX(descriptor_index))
        {
            PRINT("[error] >>> index out of -1");
            exit(0);
        }

        u2 real_descriptor_index = descriptor_index - 1;

        if (OK == CHECK_INDEX(real_descriptor_index))
        {
            std::cout << std::setw(20) << "#" << real_descriptor_index;
        }

        for (auto &val : attributes)
        {
            val->disaply();
        }
    }

private:
    u2 access_flags;
    u2 name_index;
    u2 descriptor_index;
    u2 attributes_count;
    std::vector<attribute_info*> attributes;

    void printAccessFlags()
    {
        bool isOut = false;
        if (access_flags & F_ACC_PUBLIC)
        {
            std::cout << "PUBLIC";
            isOut = true;
        }
        else if (access_flags & F_ACC_PRIVATE)
        {
            std::cout << "PRIVATE";
            isOut = true;
        } 
        else if (access_flags & F_ACC_PROTECTED)
        {
            std::cout << "PROTECTED";
            isOut = true;
        }

        if (access_flags & F_ACC_STATIC)
        {
            CHECK_FIRST_OUTPUT(true);
            std::cout  << "STATIC";
            isOut = true;
        } 

        if (access_flags & F_ACC_FINAL)
        {
            CHECK_FIRST_OUTPUT(true);
            std::cout  << "FINAL";
            isOut = true;
        }
        else if (access_flags & F_ACC_VOLATILE)
        {
            CHECK_FIRST_OUTPUT(true);
            std::cout  << "VOLATILE";
            isOut = true;
        }

        if (access_flags & F_ACC_TRANSINT)
        {
            CHECK_FIRST_OUTPUT(true);
            std::cout << "TRANSINT";
            isOut = true;
        }

        if (access_flags & F_ACC_SYNTHETIC)
        {
            CHECK_FIRST_OUTPUT(true);
            std::cout << "SYNTHETIC";
            isOut = true;
        }

        if (access_flags & F_ACC_ENUM)
        {
            CHECK_FIRST_OUTPUT(true);
            std::cout << "ENUM";
            isOut = true;
        }
        std::cout << std::endl;
    }
};