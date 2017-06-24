#pragma once
#include "common.h"
#include "constant_info.h"
#include "filed_info.h"
#include "method_info.h"

class classFile
{
public:
    
private:
    u4 magic;
    u2 minor_version;
    u2 major_version;
    u2 constant_pool_count;
    constant_info* info;
    u2 access_flags;
    u2 this_class;
    u2 spuer_class;
    u2 interfaces_count;
    u2* interfaces;
    u2 field_count;
    field_info* fields;
    u2 method_count;
    method_info* methods;
    u2 attributes_count;
    attribute_info* attributes;
};