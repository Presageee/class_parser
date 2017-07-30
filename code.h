#pragma once
#include "attribute_info.h"

class code : public attribute_info
{
public:
    code(u2 attribute_name_index) :attribute_info(attribute_name_index)
    {

    }

    ~code()
    {
        if (!codes)
            delete[] codes;
    }

    void readInfo(std::ifstream &in)
    {
        attribute_info::readInfo(in);

        char tmp[2];
        in.read(tmp, 2);
        this->max_stack = _2_u2(tmp);

        in.read(tmp, 2);
        this->max_locals = _2_u2(tmp);

        char cl[4];
        in.read(cl, 4);
        this->code_length = _2_u4(cl);
        
        codes = new char[code_length];
        in.read(codes, code_length);

        in.read(tmp, 2);
        this->exception_table_length = _2_u2(tmp);

        for (int i = 0; i < exception_table_length; i++)
        {
            exception* ex = new exception;
            in.read(tmp, 2);
            ex->start_pc = _2_u2(tmp);

            in.read(tmp, 2);
            ex->end_pc = _2_u2(tmp);

            in.read(tmp, 2);
            ex->handler_pc = _2_u2(tmp);

            in.read(tmp, 2);
            ex->catch_type = _2_u2(tmp);

            exception_table.push_back(ex);
        }

        in.read(tmp, 2);
        this->attributes_count = _2_u2(tmp);
        //todo read attributes
    }

    void display(std::vector<constant_info*> &info)
    {
        //todo
    }
private:
    u2 max_stack;
    u2 max_locals;
    u4 code_length;
    char* codes;
    u2 exception_table_length;
    typedef struct 
    {
        u2 start_pc;
        u2 end_pc;
        u2 handler_pc;
        u2 catch_type;
    } exception;
    std::vector<exception*> exception_table;
    u2 attributes_count;
    std::vector<attribute_info*> attributes;
};