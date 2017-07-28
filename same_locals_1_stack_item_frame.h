#pragma once
#include "stack_map_frame.h"
#include "verification_type_info.h"

class same_locals_1_stack_item_frame : public stack_map_frame
{
public:
    same_locals_1_stack_item_frame(u1 frame_type) :stack_map_frame(frame_type) {};

    

private:
    verification_type_info info;
};