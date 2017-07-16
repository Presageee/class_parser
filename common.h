#pragma once

#define CONSTANT_UTF_8 1
#define CONSTANT_INTEGER 3
#define CONSTANT_FLOAT 4
#define CONSTANT_LONG 5
#define CONSTANT_DOUBLE 6
#define CONSTANT_CLASS 7
#define CONSTANT_STRING 8
#define CONSTANT_FIELD_REF 9
#define CONSTANT_METHOD_REF 10
#define CONSTANT_INTERFACE_METHOD_REF 11
#define CONSTANT_NAME_AND_TYPE 12
#define CONSTANT_METHOD_HANDLE 15
#define CONSTANT_METHOD_TYPE 16
#define CONSTANT_INVOKE_DYNAMIC 18

//access_flags
#define C_ACC_PUBLIC 0x0001
#define C_ACC_FINAL 0x0010
#define C_ACC_SUPER 0x0020
#define C_ACC_INTERFACE 0x0200
#define C_ACC_ABSTRACT 0x0400
#define C_ACC_SYNTHETIC 0x1000
#define C_ACC_ANNOTATION 0x2000
#define C_ACC_ENUM 0x4000

#define F_ACC_PUBLIC 0x0001
#define F_ACC_PRIVATE 0x0002
#define F_ACC_PROTECTED 0x0004
#define F_ACC_STATIC 0x0008
#define F_ACC_FINAL 0x0010
#define F_ACC_VOLATILE 0x0040
#define F_ACC_TRANSINT 0x0080
#define F_ACC_SYNTHETIC 0x1000
#define F_ACC_ENUM 0x4000

#define M_ACC_PUBLIC 0x0001
#define M_ACC_PRIVATE 0x0002
#define M_ACC_PROTECTED 0x0004
#define M_ACC_STATIC 0x0008
#define M_ACC_FINAL 0X0010
#define M_ACC_SYNCHRONIZED 0x0020
#define M_ACC_BRIDGE 0x0040
#define M_ACC_VARARGS 0x0080
#define M_ACC_NATIVE 0x0100
#define M_ACC_ABSTRACT 0x0400
#define M_ACC_STRICT 0x0800
#define M_ACC_SYNTHETIC 0x1000

// method reference
#define REF_getField 1
#define REF_getStatic 2
#define REF_putField 3
#define REF_putStatic 4
#define REF_invokeVirtual 5
#define REF_invokeStatic 6
#define REF_invokeSpecial 7
#define REF_newInvokeSpecial 8
#define REF_invokeInterface 9

#define u1 unsigned char
#define u2 unsigned short
#define u4 unsigned int
#define u8 double
//& 0xFF top 8, 0000£¬0000£¬0000£¬0010 & 0xFF => 0000£¬0010

//to float
#define _2_u4(val) val[0] << 24 | val[1] << 16 | val[2] << 8 | val[3]
//to unsigned short
#define _2_u2(val) val[0] << 8 | val[1]
//to double
#define _2_u8(val) val[7] | val[6] << 8 | val[5] << 16 |val[4] << 24 | val[3] << 32 | val[2] << 40 | val[1] << 48 | val[0] << 56 


#define OK 1
#define ERR 0

#include <iostream>
#include <cstdlib>
#define CHECK_AND_PRINT(val, str1, str2) if (val == OK) {std::cout << str1 << std::endl;} else {std::cout << str2 << std::endl; exit(0);}
#define PRINT(str) std::cout << str << std::endl;
#define CHECK_INDEX(val) val  < 0 ? ERR : OK
#define CHECK_FIRST_OUTPUT(val) if (val) std::cout << ",";


#include "method_handler_factory.h"
#include "constant_info_factory.h"
//gobal var
constant_info_factory info_factory;
method_handler_factory handler_factory;

void init()
{
    info_factory.init();

    handler_factory.init();
}