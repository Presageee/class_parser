#pragma once
#include "attribute_info.h"

class inner_classes : public attribute_info
{
public:
    inner_classes(u2 attribute_name_index) : attribute_info(attribute_name_index) {};

    void readInfo(std::ifstream &in)
    {
        attribute_info::readInfo(in);
        
        char number[2];
        in.read(number, 2);
        number_of_classes = _2_u2(number);

        for (int i = 0; i < number_of_classes; i++)
        {
            u_classes *uc = new u_classes();
            uc->readInfo(in);
            clazz.push_back(uc);
        }
    }

    void display(const std::vector<constant_info*> &info)
    {
        std::cout << "InnerClasses:" << std::endl;

        for (auto &val : clazz)
            val->display(info);
    }

private:
    u2 number_of_classes;

    typedef union classes 
    {
        u2 inner_class_info_index;
        u2 outer_class_info_index;
        u2 inner_name_index;
        u2 inner_class_access_flags;

        classes() {};

        classes(u2 inner_class_index, u2 outer_class_index, u2 inner_name_index, u2 access_flags) :
            inner_class_info_index(inner_class_index), outer_class_info_index(outer_class_index),
            inner_name_index(inner_name_index), inner_class_access_flags(access_flags) {};


        void readInfo(std::ifstream &in)
        {
            char index[2];

            in.read(index, 2);
            inner_class_info_index = _2_u2(index);

            in.read(index, 2);
            outer_class_info_index = _2_u2(index);

            in.read(index, 2);
            inner_name_index = _2_u2(index);

            in.read(index, 2);
            inner_class_access_flags = _2_u2(index);
        }

        void display(const std::vector<constant_info*> &info)
        {
            std::cout << std::setw(20) << "Class";
            if (ERR == CHECK_INDEX(inner_class_info_index))
            {
                PRINT("[error] >>> index out of -1");
                exit(0);
            }

            u2 real_inner_class_info_index = inner_class_info_index - 1;

            if (OK == CHECK_INDEX(real_inner_class_info_index))
            {
                std::string msg("#");
                std::cout << std::setw(20) << msg.append(std::to_string(real_inner_class_info_index)) << ",";
            }
            std::cout << std::endl;

            std::cout << std::setw(20) << "Class";
            if (ERR == CHECK_INDEX(outer_class_info_index))
            {
                PRINT("[error] >>> index out of -1");
                exit(0);
            }

            u2 real_outer_class_info_index = outer_class_info_index - 1;

            if (OK == CHECK_INDEX(real_outer_class_info_index))
            {
                std::string msg("#");
                std::cout << std::setw(20) << msg.append(std::to_string(real_outer_class_info_index)) << ",";
            }
            std::cout << std::endl;

            std::cout << std::setw(20) << "NameAndType";
            if (ERR == CHECK_INDEX(inner_name_index))
            {
                PRINT("[error] >>> index out of -1");
                exit(0);
            }

            u2 real_inner_name_index = inner_name_index - 1;

            if (OK == CHECK_INDEX(real_inner_name_index))
            {
                std::string msg("#");
                std::cout << std::setw(20) << msg.append(std::to_string(real_inner_name_index)) << ",";
            }
            std::cout << std::endl;

            printAccessFlags();

        }

        void printAccessFlags()
        {
            std::cout << "flags : ";
            bool isOut = false;
            if (inner_class_access_flags & C_ACC_PUBLIC)
            {
                std::cout << "PUBLIC";
                isOut = true;
            }

            if (inner_class_access_flags & C_ACC_FINAL)
            {
                CHECK_FIRST_OUTPUT(isOut);
                std::cout << "FINAL";
                isOut = true;
            }

            if (inner_class_access_flags & C_ACC_SUPER)
            {
                CHECK_FIRST_OUTPUT(isOut);
                std::cout << "SUPER";
                isOut = true;
            }

            if (inner_class_access_flags & C_ACC_INTERFACE)
            {
                CHECK_FIRST_OUTPUT(true);
                std::cout << "INTERFACE";
                isOut = true;
            }

            if (inner_class_access_flags & C_ACC_ABSTRACT)
            {
                CHECK_FIRST_OUTPUT(true);
                std::cout << "ABSTRACT";
                isOut = true;
            }

            if (inner_class_access_flags & C_ACC_SYNTHETIC)
            {
                CHECK_FIRST_OUTPUT(true);
                std::cout << "SYNTHETIC";
                isOut = true;
            }

            if (inner_class_access_flags & C_ACC_ANNOTATION)
            {
                CHECK_FIRST_OUTPUT(true);
                std::cout << "ANNOTATION";
                isOut = true;
            }

            if (inner_class_access_flags & C_ACC_ENUM)
            {
                CHECK_FIRST_OUTPUT(true);
                std::cout << "ENUM";
                isOut = true;
            }

            std::cout << std::endl;
        }
    }u_classes;

    std::vector<u_classes*> clazz;
};