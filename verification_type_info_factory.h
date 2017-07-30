#pragma once
#include "common.h"
#include <fstream>
#include <map>

class verification_type_info
{
public:
    verification_type_info() {};

    verification_type_info(u1 tag)
    {
        this->tag = tag;
    }

    virtual void readInfo(std::ifstream &in) {};

    virtual void display(const std::vector<constant_info*> &info) {};

private:
    u1 tag;
};

class top_var_info : public verification_type_info
{
public:
    top_var_info(u1 tag) : verification_type_info(tag) {};

    void readInfo(std::ifstream &in) {};

    void display(const std::vector<constant_info*> &info)
    {
        std::cout << "ITEM_Top" << std::endl;
    }
};

class integer_var_info : public verification_type_info
{
public:
    integer_var_info(u1 tag) :verification_type_info(tag) {};

    void readInfo(std::ifstream &in) {};

    void display(const std::vector<constant_info*> &info)
    {
        std::cout << "ITEM_Integer" << std::endl;
    }
};

class float_var_info : public verification_type_info
{
public:
    float_var_info(u1 tag) : verification_type_info(tag) {};

    void readInfo(std::ifstream &in) {};

    void display(const std::vector<constant_info*> &info)
    {
        std::cout << "ITEM_Float" << std::endl;
    }
};

class long_var_info : public verification_type_info
{
public:
    long_var_info(u1 tag) : verification_type_info(tag) {};

    void readInfo(std::ifstream &in) {};

    void display(const std::vector<constant_info*> &info)
    {
        std::cout << "ITEM_Long" << std::endl;
    }
};

class double_var_info : public verification_type_info
{
public:
    double_var_info(u1 tag) : verification_type_info(tag) {};

    void readInfo(std::ifstream &in) {};

    void display(const std::vector<constant_info*> &info)
    {
        std::cout << "ITEM_Double" << std::endl;
    }
};

class null_var_info : public verification_type_info
{
public:
    null_var_info(u1 tag) : verification_type_info(tag) {};

    void readInfo(std::ifstream &in) {};

    void display(const std::vector<constant_info*> &info)
    {
        std::cout << "ITEM_Null" << std::endl;
    }
};

class uninitializedThis_var_info : public verification_type_info
{
public:
    uninitializedThis_var_info(u1 tag) : verification_type_info(tag) {};

    void readInfo(std::ifstream &in) {};

    void display(const std::vector<constant_info*> &info)
    {
        std::cout << "ITEM_UninitializedThis" << std::endl;
    }
};

class object_var_info: public verification_type_info
{
public:
    object_var_info(u1 tag) : verification_type_info(tag) {};

    void readInfo(std::ifstream &in)
    {
        char tmp[2];
        in.read(tmp, 2);

        this->cpool_index = _2_u2(tmp);
    }

    void display(const std::vector<constant_info*> &info)
    {
        std::cout << "ITEM_Object, cpool_index => " << info[cpool_index - 1] << std::endl;
    }
private:
    u2 cpool_index;
};

class uninitialized_var_info :public verification_type_info
{
public:
    uninitialized_var_info(u1 tag) : verification_type_info(tag) {};

    void readInfo(std::ifstream &in)
    {
        char tmp[2];
        in.read(tmp, 2);

        this->offset = _2_u2(tmp);
    }

    void display(const std::vector<constant_info*> &info)
    {
        std::cout << "ITEM_Uninitialized, offset => " << offset << std::endl;
    }
private:
    u2 offset;
};

class verification_type_info_factory
{
public:
    int init();

    int getInstance(u1 tag, verification_type_info **info);
private:
    typedef int(verification_type_info_factory::*createInstance)(u1, verification_type_info**);

    std::map<u1, createInstance> infoMap;

    bool hasKey(const u1 key)
    {
        return infoMap.end() != infoMap.find(key);
    }

    int getTop(u1 tag, verification_type_info **info)
    {
        top_var_info *top = new top_var_info(tag);
        *info = top;
        return OK;
    }

    int getInteger(u1 tag, verification_type_info **info)
    {
        integer_var_info *integer = new integer_var_info(tag);
        *info = integer;
        return OK;
    }

    int getFloat(u1 tag, verification_type_info **info)
    {
        float_var_info *_float = new float_var_info(tag);
        *info = _float;
        return OK;
    }

    int getLong(u1 tag, verification_type_info **info)
    {
        long_var_info *_long = new long_var_info(tag);
        *info = _long;
        return OK;
    }

    int getDouble(u1 tag, verification_type_info **info)
    {
        double_var_info *_double = new double_var_info(tag);
        *info = _double;
        return OK;
    }

    int getNull(u1 tag, verification_type_info **info)
    {
        null_var_info *_null = new null_var_info(tag);
        *info = _null;
        return OK;
    }

    int getUninitializedThis(u1 tag, verification_type_info **info)
    {
        uninitializedThis_var_info *uninitialized_this = new uninitializedThis_var_info(tag);
        *info = uninitialized_this;
        return OK;
    }

    int getObject(u1 tag, verification_type_info **info)
    {
        object_var_info *object = new object_var_info(tag);
        *info = object;
        return OK;
    }

    int getUninitialized(u1 tag, verification_type_info **info)
    {
        uninitialized_var_info *uninitialized = new uninitialized_var_info(tag);
        *info = uninitialized;
        return OK;
    }

};

int verification_type_info_factory::init()
{
    infoMap[Top_vriable_info] = &verification_type_info_factory::getTop;
    infoMap[Integer_variable_info] = &verification_type_info_factory::getInteger;
    infoMap[Float_variable_info] = &verification_type_info_factory::getFloat;
    infoMap[Long_variable_info] = &verification_type_info_factory::getLong;
    infoMap[Double_variable_info] = &verification_type_info_factory::getDouble;
    infoMap[Null_variable_info] = &verification_type_info_factory::getNull;
    infoMap[UninitializedThis_variable_info] = &verification_type_info_factory::getUninitializedThis;
    infoMap[Object_variable_info] = &verification_type_info_factory::getObject;
    infoMap[Uninitialized_variable_info] = &verification_type_info_factory::getUninitialized;
}

int verification_type_info_factory::getInstance(u1 tag, verification_type_info **info)
{
    return hasKey(tag) ? (this->*infoMap[tag])(tag, info) : ERR;
}