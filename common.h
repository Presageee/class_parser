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

<<<<<<< HEAD
//access_flags
#define ACC_PUBLIC 0x0001
#define ACC_FINAL 0x0010
#define ACC_SUPER 0x0020
#define ACC_INTERFACE 0x0200
#define ACC_ABSTRACT 0x0400
#define ACC_SYNTHETIC 0x1000
#define ACC_ANNOTATION 0x2000
#define ACC_ENUM 0x4000

=======
>>>>>>> 696d02f01bf5a12d9814c22365a1bb7387c8de3e
#define u1 unsigned char
#define u2 unsigned short
#define u4 unsigned int
#define u8 double
<<<<<<< HEAD
//& 0xFF ȡ�߰�λ 0000��0000��0000��0010 & 0xFF => 0000��0010
=======
//& 0xFF ȡ�߰�λ 0000��0000��0000��0010 & 0xFF => 0000��0010
>>>>>>> 696d02f01bf5a12d9814c22365a1bb7387c8de3e
#define _2_u4(val) val[0] << 24 | val[1] << 16 | val[2] << 8 | val[3]
#define _2_u2(val) val[0] << 8 | val[1]
#define _2_u8(val) val[7] | val[6] << 8 | val[5] << 16 |val[4] << 24 | val[3] << 32 | val[2] << 40 | val[1] << 48 | val[0] << 56 