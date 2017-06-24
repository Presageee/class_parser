#pragma once
#include "constant_utf8.h"
#include "constant_class.h"
#include "constant_double.h"
#include "constant_field_ref.h"
#include "constant_float.h"
#include "constant_integer.h"
#include "constant_interface_method_ref.h"
#include "constant_invoke_dynamic.h"
#include "constant_long.h"
#include "constant_string.h"
#include "constant_name_and_type.h"
#include "constant_method_type.h"
#include "constant_method_handler.h"
#include "constant_method_ref.h"
#include <map>

class constant_info_factory
{
public:
    int getInstance(u1 tag, constant_info& info);
    
    int init();
private:
    typedef int(constant_info_factory::*createInstance)(u1, constant_info&);
    
    std::map<u1, createInstance> operationMap;

    bool hasKey(const u1 key)
    {
        return operationMap.end() != operationMap.find(key);
    }

    int getUTF8(u1 tag, constant_info &info)
    {
        constant_utf8 *utf8 = new constant_utf8(tag);
        info = *utf8;
        return OK;
    }

    int getInteger(u1 tag, constant_info &info)
    {
        constant_integer *integer = new constant_integer(tag);
        info = *integer;
        return OK;
    }

    int getFloat(u1 tag, constant_info& info)
    {
        constant_float *_float = new constant_float(tag);
        info = *_float;
        return OK;
    }

    int getLong(u1 tag, constant_info& info)
    {
        constant_long *_long = new constant_long(tag);
        info = *_long;
        return OK;
    }

    int getDouble(u1 tag, constant_info& info)
    {
        constant_double *_double = new constant_double(tag);
        info = *_double;
        return OK;
    }

    int getClass(u1 tag, constant_info& info)
    {
        constant_class *_class = new constant_class(tag);
        info = *_class;
        return OK;
    }

    int getString(u1 tag, constant_info& info)
    {
        constant_string *str = new constant_string(tag);
        info = *str;
        return OK;
    }

    int getFieldRef(u1 tag, constant_info& info)
    {
        constant_field_ref *field = new constant_field_ref(tag);
        info = *field;
        return OK;
    }

    int getMethodRef(u1 tag, constant_info& info)
    {
        constant_method_ref *method_ref = new constant_method_ref(tag);
        info = *method_ref;
        return OK;
    }

    int getInterfaceMethodRef(u1 tag, constant_info& info)
    {
        constant_interface_method_ref *_interface_method_ref =
            new constant_interface_method_ref(tag);
        info = *_interface_method_ref;
        return OK;
    }

    int getNameAndType(u1 tag, constant_info& info)
    {
        constant_name_and_type *name_and_type = new constant_name_and_type(tag);
        info = *name_and_type;
        return OK;
    }

    int getMethodHandler(u1 tag, constant_info& info)
    {
        constant_method_handler *method_handler = new constant_method_handler(tag);
        info = *method_handler;
        return OK;
    }

    int getMethodType(u1 tag, constant_info& info)
    {
        constant_method_type *method_type = new constant_method_type(tag);
        info = *method_type;
        return OK;
    }

    int getInvokeDynamic(u1 tag, constant_info& info)
    {
        constant_invoke_dynamic *invoke_dynamic = new constant_invoke_dynamic(tag);
        info = *invoke_dynamic;
        return OK;
    }
};

int constant_info_factory::init()
{
    operationMap[CONSTANT_UTF_8] = &constant_info_factory::getUTF8;
    operationMap[CONSTANT_INTEGER] = &constant_info_factory::getInteger;
    operationMap[CONSTANT_FLOAT] = &constant_info_factory::getFloat;
    operationMap[CONSTANT_LONG] = &constant_info_factory::getLong;
    operationMap[CONSTANT_DOUBLE] = &constant_info_factory::getDouble;
    operationMap[CONSTANT_CLASS] = &constant_info_factory::getClass;
    operationMap[CONSTANT_STRING] = &constant_info_factory::getString;
    operationMap[CONSTANT_FIELD_REF] = &constant_info_factory::getFieldRef;
    operationMap[CONSTANT_METHOD_REF] = &constant_info_factory::getMethodRef;
    operationMap[CONSTANT_INTERFACE_METHOD_REF] = 
        &constant_info_factory::getInterfaceMethodRef;
    operationMap[CONSTANT_NAME_AND_TYPE] = &constant_info_factory::getNameAndType;
    operationMap[CONSTANT_METHOD_HANDLE] = &constant_info_factory::getMethodHandler;
    operationMap[CONSTANT_METHOD_TYPE] = &constant_info_factory::getMethodType;
    operationMap[CONSTANT_INVOKE_DYNAMIC] = &constant_info_factory::getInvokeDynamic;

    return OK;

}

int constant_info_factory::getInstance(u1 tag, constant_info &info)
{
    return hasKey(tag) ? (this->*operationMap[tag])(tag, info) : ERR;
  //  switch (tag)
  //  {
  //  case CONSTANT_UTF_8:
  //      constant_utf8 *utf8 = new constant_utf8(tag);
  //      info = *utf8;
  //      return OK;
  //  case CONSTANT_INTEGER:
  //      constant_integer *integer = new constant_integer(tag);
		//info = *integer;
  //      return OK;
  //  case CONSTANT_FLOAT:
  //      constant_float *_float = new constant_float(tag);
  //      info = *_float;
  //      return OK;
  //  case CONSTANT_LONG:
  //      constant_long *_long = new constant_long(tag);
  //      info = *_long;
  //      return OK;
  //  case CONSTANT_DOUBLE:
  //      constant_double *_double = new constant_double(tag);
  //      info = *_double;
  //      return OK;
  //  case CONSTANT_CLASS:

  //  default:
		//return ERR;
  //  }
}

