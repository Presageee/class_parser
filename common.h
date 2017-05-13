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

#define u1 unsigned char
#define u2 unsigned short
#define u4 unsigned int
#define u8 double
//& 0xFF È¡¸ß°ËÎ» 0000£¬0000£¬0000£¬0010 & 0xFF => 0000£¬0010
#define _2_u4(val) val[0] << 24 | val[1] << 16 | val[2] << 8 | val[3]
#define _2_u2(val) val[0] << 8 | val[1]
#define _2_u8(val) val[7] | val[6] << 8 | val[5] << 16 |val[4] << 24 | val[3] << 32 | val[2] << 40 | val[1] << 48 | val[0] << 56 