#pragma once
#include "attribute_info.h"

class local_variable_table : public attribute_info
{
public:
    local_variable_table(u2 attribute_name_index) :attribute_info(attribute_name_index) {};

    void readInfo(std::ifstream &in)
    {
        attribute_info::readInfo(in);

        char byte[2];
        in.read(byte, 2);
        local_variable_table_length = _2_u2(byte);

        for (int i = 0; i < local_variable_table_length: i++)
        {
            local_var_table* table = new local_var_table;
            table->readInfo(in);

            tables.push_back(table);
        }
    }

    void display(const std::vector<constant_info*> &info)
    {
        std::cout << "LocalVariableTable:" << std::endl;
        for (auto &val : tables)
            val->display(info);
    }

private:
    typedef union local_var_table
    {
        u2 start_pc;
        u2 length;
        u2 name_index;
        u2 descriptor_index;
        u2 index;

        void readInfo(std::ifstream &in)
        {
            char byte[2];

            in.read(byte, 2);
            start_pc = _2_u2(byte);

            in.read(byte, 2);
            length = _2_u2(byte);

            in.read(byte, 2);
            name_index = _2_u2(byte);

            in.read(byte, 2);
            descriptor_index = _2_u2(byte);

            in.read(byte, 2);
            index = _2_u2(byte);
        }

        void display(const std::vector<constant_info*> &info)
        {
            std::cout << "startPc => " << start_pc << std::endl;
            std::cout << "pcLength => " << length << std::endl;

            if (ERR == CHECK_INDEX(name_index))
            {
                PRINT("[error] >>> index out of -1");
                exit(0);
            }

            u2 real_name_index = name_index - 1;

            if (OK == CHECK_INDEX(real_name_index))
            {
                std::string msg("#");
                std::cout << std::setw(20) << msg.append(std::to_string(real_name_index));
            }
            std::cout << std::endl;

            if (ERR == CHECK_INDEX(descriptor_index))
            {
                PRINT("[error] >>> index out of -1");
                exit(0);
            }

            u2 real_descriptor_index = descriptor_index - 1;

            if (OK == CHECK_INDEX(real_descriptor_index))
            {
                std::string msg("#");
                std::cout << std::setw(20) << msg.append(std::to_string(real_descriptor_index));
            }
            std::cout << std::endl;

            if (ERR == CHECK_INDEX(index))
            {
                PRINT("[error] >>> index out of -1");
                exit(0);
            }

            u2 real_index = index - 1;

            if (OK == CHECK_INDEX(real_index))
            {
                std::string msg("#");
                std::cout << std::setw(20) << msg.append(std::to_string(real_index));
            }
            std::cout << std::endl;


        }
    };

    u2 local_variable_table_length;
    std::vector<local_var_table *> tables;
};