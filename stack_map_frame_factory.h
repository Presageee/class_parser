#pragma once
#include "common.h"
#include <fstream>

extern verification_type_info_factory verification_type_factory;

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

    virtual void display(const std::vector<constant_info*> &info) {};

    u1 getFrameType()
    {
        return frame_type;
    }
private:
    u1 frame_type;
};

class same_frame : public stack_map_frame
{
public:
    same_frame(u1 frame_type) : stack_map_frame(frame_type) {};

    void readInfo(std::ifstream &in) {};

    void display(const std::vector<constant_info*> &info)
    {
        std::cout << "SAME" << std::endl;
    }
};


class same_locals_1_stack_item_frame : public stack_map_frame
{
public:
    same_locals_1_stack_item_frame(u1 frame_type) :stack_map_frame(frame_type) {};

    same_locals_1_stack_item_frame()
    {
        if (!info)
            delete info;
    }

    void readInfo(std::ifstream &in)
    {
        char byte[1];
        in.read(byte, 1);

        verification_type_factory.getInstance(byte[0], &info);
    }

    void display(const std::vector<constant_info*> &info)
    {
        std::cout << "SAME_LOCALS_1_STACK_ITEM => ";
        this->info->display(info);
    }

private:
    verification_type_info *info = nullptr;
};

class same_locals_1_stack_item_frame_extended :public stack_map_frame
{
public:
    same_locals_1_stack_item_frame_extended(u1 frame_type) :stack_map_frame(frame_type) {};

    ~same_locals_1_stack_item_frame_extended()
    {
        if (!info)
            delete info;
    }

    void readInfo(std::ifstream &in)
    {
        char byte[2];
        in.read(byte, 2);
        offfset_delta = _2_u2(byte);

        char type[1];
        in.read(type, 1);

        verification_type_factory.getInstance(type[0], &info);
    }

    void display(const std::vector<constant_info*> &info)
    {
        std::cout << "SAME_LOCALS_1_STACK_ITEM_EXTENDED => ";
        this->info->display(info);
    }

private:
    u2 offfset_delta;
    verification_type_info *info = nullptr;
};

class chop_frame : public stack_map_frame
{
public:
    chop_frame(u1 frame_type) : stack_map_frame(frame_type) {};

    void readInfo(std::ifstream &in)
    {
        char byte[2];
        in.read(byte, 2);
        this->offset_delta = _2_u2(byte);
    }

    void display(const std::vector<constant_info*> &info)
    {
        std::cout << "CHOP: ";
        std::cout << "offset_delta => " << offset_delta << std::endl;
    }

private:
    u2 offset_delta;
};

class same_frame_extended : public stack_map_frame
{
public:
    same_frame_extended(u1 frame_type) : stack_map_frame(frame_type) {};

    void readInfo(std::ifstream &in)
    {
        char byte[2];
        in.read(byte, 2);
        this->offset_delta = _2_u2(byte);
    }

    void display(const std::vector<constant_info*> &info)
    {
        std::cout << "SAME_FRAME_EXTENDED: ";
        std::cout << "offset_delta => " << offset_delta << std::endl;
    }

private:
    u2 offset_delta;
};

class append_frame : public stack_map_frame
{
public:
    append_frame(u1 frame_type) : stack_map_frame(frame_type) {};

    ~append_frame()
    {
        for (auto &val : infos)
            delete val;
    }

    void readInfo(std::ifstream &in)
    {
        char byte[2];
        in.read(byte, 2);
        this->offset_delta = _2_u2(byte);

        int size = getFrameType() - 251;
        for (int i = 0; i < size; i++)
        {
            verification_type_info *info = nullptr;

            char type[1];
            in.read(type, 1);
            verification_type_factory.getInstance(type[0], &info);
            
            infos.push_back(info);
        }
    }

    void display(const std::vector<constant_info*> &info)
    {
        std::cout << "APPEND: ";
        std::cout << "offset => " << offset_delta << std::endl;
        
        for (auto &val : infos)
            val->display(info);
    }

private:
    u2 offset_delta;
    std::vector<verification_type_info*> infos;
};

class stack_map_frame_factory
{
public:
    int getInstance(u1 frame_type, stack_map_frame **map_frame)
    {
        stack_map_frame *frame = nullptr;

        if (frame_type >= 0 && frame_type <= 63)
        {
            frame = new same_frame(frame_type);
            *map_frame = frame;
        }
        else if (frame_type >= 64 && frame_type <= 127)
        {
            frame = new same_locals_1_stack_item_frame(frame_type);
            *map_frame = frame;
        }
        else if (frame_type == 247)
        {
            frame = new same_locals_1_stack_item_frame_extended(frame_type);
            *map_frame = frame;
        } 
        else if (frame_type >= 248 && frame_type <= 250)
        {
            frame = new chop_frame(frame_type);
            *map_frame = frame;
        }
        else if (frame_type == 251)
        {
            frame = new same_frame_extended(frame_type);
            *map_frame = frame;
        }
        else
        {
            frame = new append_frame(frame_type);
            *map_frame = frame;
        }
    }
};