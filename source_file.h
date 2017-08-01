#pragma once
#include "attribute_info.h"

class source_file : public attribute_info
{
public:
    source_file(u2 attribute_name_index) : attribute_info(attribute_name_index) {};

    void readInfo(std::ifstream &in)
    {
        attribute_info::readInfo(in);

        char byte[2];
        in.read(byte, 2);
        sourcefile_index = _2_u2(byte);
    }

    void display(const std::vector<constant_info*> &info)
    {
        std::cout << "SourceFile: " << std::endl;

        if (ERR == CHECK_INDEX(sourcefile_index))
        {
            PRINT("[error] >>> index out of -1");
            exit(0);
        }

        u2 real_sourcefile_index = sourcefile_index - 1;

        if (OK == CHECK_INDEX(real_sourcefile_index))
        {
            std::string msg("#");
            std::cout << std::setw(20) << msg.append(std::to_string(real_sourcefile_index));
        }
        std::cout << std::endl;

    }
private:
    u2 sourcefile_index;
};