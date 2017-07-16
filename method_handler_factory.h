#pragma once
#include "common.h"
#include <map>
#include <string>

class method_handler_factory
{
public:
    int init();

    const std::string& getType(u1 type);

    inline bool hasKey(const u1 key)
    {
        return mhMap.end() != mhMap.find(key);
    }
private:
    std::map<u1, std::string> mhMap;
};

int method_handler_factory::init()
{
    mhMap[1] = "REF_getField";
    mhMap[2] = "REF_getStatic";
    mhMap[3] = "REF_putField";
    mhMap[4] = "REF_putStatic";
    mhMap[5] = "REF_invokeVirual";
    mhMap[6] = "REF_invokeStatic";
    mhMap[7] = "REF_invokeSpecial";
    mhMap[8] = "REF_newInvokeSpecial";
    mhMap[9] = "REF_invokeInterface";

    return OK;
}

const std::string& method_handler_factory::getType(u1 type)
{
    return hasKey(type) ? mhMap[type] : "null";
}