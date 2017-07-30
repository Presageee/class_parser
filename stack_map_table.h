#pragma once
#include "attribute_info.h"

extern stack_map_frame_factory frame_factory;

class stack_map_table : public attribute_info
{
public:
    stack_map_table(u2 attribute_name_index) : attribute_info(attribute_name_index)
    {

    }

    void readInfo(std::ifstream &in)
    {
        attribute_info::readInfo(in);

        char tmp[2];
        in.read(tmp, 2);

        this->number_of_entries = _2_u2(tmp);

        char type[1];
        for (int i = 0; i < number_of_entries; i++)
        {
            stack_map_frame *frame = nullptr;
            
            in.read(type, 1);
            frame_factory.getInstance(type[0], &frame);

            frames.push_back(frame);
        }
    }

    void display(const std::vector<constant_info*> &info)
    {
        std::cout << "Stack_Map_Table:" << std::endl;
        std::cout << "entries : " << number_of_entries << std::endl;
        for (auto &frame : frames)
            frame->display(info);
    }

private:
    u2 number_of_entries;
    std::vector<stack_map_frame *> frames;
};