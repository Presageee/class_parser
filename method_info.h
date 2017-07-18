#pragma once
#include "common.h"
#include "attribute_info.h"

class method_info
{
public:
    void readInfo(std::ifstream &in)
    {
        char tmp[2];
        in.read(tmp, 2);
        access_flags = _2_u2(tmp);
        in.read(tmp, 2);
        name_index = _2_u2(tmp);
        in.read(tmp, 2);
        descriptor_index = _2_u2(tmp);
        in.read(tmp, 2);
        attributes_count = _2_u2(tmp);
        //attributes = new attribute_info[attributes_count];
        for (int i = 0; i < attributes_count; i++)
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
            val->disaply(info);
        }
    }

    void outputVal(const std::vector<constant_info*> &info) 
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
            //std::cout << "#" << real_name_index;
            info[real_name_index]->outputVal(info);
        }

        if (ERR == CHECK_INDEX(descriptor_index))
        {
            PRINT("[error] >>> index out of -1");
            exit(0);
        }

        u2 real_descriptor_index = descriptor_index - 1;

        if (OK == CHECK_INDEX(real_descriptor_index))
        {
            //std::cout << std::setw(20) << "#" << real_descriptor_index;
            info[real_descriptor_index]->outputVal(info);
        }

        for (auto &val : attributes)
        {
            val->disaply(info);
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
        if (access_flags & M_ACC_PUBLIC)
        {
            std::cout << "PUBLIC";
        }
        else if (access_flags & M_ACC_PRIVATE)
        {
            std::cout << "PRIVATE";
        }
        else if (access_flags & M_ACC_PROTECTED)
        {
            std::cout << "PROTECTED";
        }

        if (access_flags & M_ACC_STATIC)
        {
            CHECK_FIRST_OUTPUT(true);
            std::cout << "STATIC";
            isOut = true;
        }

        if (access_flags & M_ACC_FINAL)
        {
            CHECK_FIRST_OUTPUT(true);
            std::cout << "FINAL";
            isOut = true;
        }
        else if (access_flags & M_ACC_ABSTRACT)
        {
            CHECK_FIRST_OUTPUT(true);
            std::cout << "ABSTRACT";
            isOut = true;
        }

        if (access_flags & M_ACC_SYNCHRONIZED)
        {
            CHECK_FIRST_OUTPUT(true);
            std::cout << "SYNCHRONIZED";
            isOut = true;
        }

        if (access_flags & M_ACC_SYNTHETIC)
        {
            CHECK_FIRST_OUTPUT(true);
            std::cout << "SYNTHETIC";
            isOut = true;
        }

        if (access_flags & M_ACC_BRIDGE)
        {
            CHECK_FIRST_OUTPUT(true);
            std::cout << "BRIDGE";
            isOut = true;
        }

        if (access_flags & M_ACC_VARARGS)
        {
            CHECK_FIRST_OUTPUT(true);
            std::cout << "VARARGS";
            isOut = true;
        }

        if (access_flags & M_ACC_NATIVE)
        {
            CHECK_FIRST_OUTPUT(true);
            std::cout << "NATIVE";
            isOut = true;
        }

        if (access_flags & M_ACC_STRICT)
        {
            CHECK_FIRST_OUTPUT(true);
            std::cout << "STRICT";
            isOut = true;
        }

        std::cout << std::endl;
    }
};