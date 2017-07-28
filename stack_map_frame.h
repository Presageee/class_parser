#pragma once
#include "common.h"
#include <fstream>

class stack_map_frame
{
public:
    stack_map_frame()
    {

    }

    stack_map_frame(u1 frame_type)
    {
        this->frame_type = frame_type;
    }

    virtual void readInfo(std::ifstream &in) {};

    virtual void display() {};
private:
    u1 frame_type;
};