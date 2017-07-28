#pragma once
#include "stack_map_frame.h"

class same_frame : public stack_map_frame
{
public:
    same_frame(u1 frame_type) : stack_map_frame(frame_type) {};

    void readInfo(std::ifstream &in) {};

    void display()
    {
        stack_map_frame::display();
    }
};