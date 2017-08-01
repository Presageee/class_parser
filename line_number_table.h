#pragma once
#include "attribute_info.h"

class line_number_table : public attribute_info
{
public:
    line_number_table(u2 attribute_name_index) : attribute_info(attribute_name_index) {};

    void readInfo(std::ifstream &in)
    {
        attribute_info::readInfo(in);

        char byte[2];

        in.read(byte, 2);
        line_number_table_length = _2_u2(byte);

        for (int i = 0; i < line_number_table_length; i++)
        {
            line_table *table = new line_table;
            table->readInfo(in);

            tables.push_back(table);
        }

        
    }

    void display(const std::vector<constant_info *> &info)
    {
        std::cout << "LineNumberTable:" << std::endl;
        
        for (auto &val : tables)
            val->display(info);
    }

private:
    typedef union line_table
    {
        u2 start_pc;
        u2 line_number;

        void readInfo(std::ifstream &in)
        {
            char byte[2];
            in.read(byte, 2);
            start_pc = _2_u2(byte);

            in.read(byte, 2);
            line_number = _2_u2(byte);
        }

        void display(const std::vector<constant_info *> &in)
        {
            std::cout << "startPc => " << start_pc << std::endl;
            std::cout << "lineNumber => " << line_number << std::endl;
        }
    };
    u2 line_number_table_length;
    std::vector<line_table*> tables;
};