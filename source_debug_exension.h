#pragma once
#include "attribute_info.h"

class source_debug_extension :public attribute_info
{
public:
    source_debug_extension(u2 attribute_name_index) : attribute_info(attribute_name_index) {};

    void readInfo(std::ifstream &in)
    {
        attribute_info::readInfo(in);

        data = new char[getAttributeLength()];
        in.read(data, getAttributeLength());
    }

    void display(const std::vector<constant_info*> &info)
    {
        std::cout << "SourceDebugExtension:" << std::endl;

        std::cout << data << std::endl;
    }

private:
    char *data = nullptr;
};