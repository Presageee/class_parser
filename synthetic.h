#pragma once
#include "attribute_info.h"

class synthetic : public attribute_info
{
public:
    synthetic(u2 attribute_name_index) :attribute_info(attribute_name_index) {};

    void readInfo(std::ifstream &in)
    {
        attribute_info::readInfo(in);
    }

    void display(const std::vector<constant_info*> &info)
    {
        std::cout << "Synthetic" << std::endl;
    }
};