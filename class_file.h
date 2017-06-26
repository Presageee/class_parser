#include "common.h"
#include "constant_info.h"
#include "field_info.h"
#include "method_info.h"
#include "constant_info_factory.h"
#include <fstream>

class class_file
{
public:
    class_file(std::string file_path)
    {
        this->input.open(file_path, std::ios::binary | std::ios::in);
    }

    ~class_file()
    {
        if (this->input.is_open())
        {
            input.close();
        }
    }

    void parseClass()
    {
        CHECK_AND_PRINT(readMagic(magic), "[info] >>> read magic success",
            "[error] >>> read magic error");

        CHECK_AND_PRINT(readMinorVersion(minor_version), "[info] >>> read minor version success",
            "[error] >>> read minor version error");

        CHECK_AND_PRINT(readMajorVersion(major_version), "[info] >>> read major version success",
            "[error] >>> read major version error");

        CHECK_AND_PRINT(readContantPoolCount(constant_pool_count), "[info] >>> read constant pool count success",
            "[error] >>> read constant pool count error");

        CHECK_AND_PRINT(readConstantInfo(), "[info] >>> read constant info success",
            "[error] >>> read constant info error");

        CHECK_AND_PRINT(readAccessFlags(access_flags), "[info] >>> read access flag success",
            "[error] >>> read access flag error");

        CHECK_AND_PRINT(readThisClass(this_class), "[info] >>> read this class success",
            "[error] >>> read this class error");

        CHECK_AND_PRINT(readSuperClass(super_class), "[info] >>> read super class success",
            "[error] >>> read super class error");

        CHECK_AND_PRINT(readInterfacesCount(interfaces_count), "[info] >>> read interface count success",
            "[error] >>> read interface count success");

        CHECK_AND_PRINT(readInterfaces(), "[info] >>> read interfaces success",
            "[error] >>> read interfaces error");

        CHECK_AND_PRINT(readFeildCount(field_count), "[info] >>> read field count success",
            "[error] >>> read field count error");

        CHECK_AND_PRINT(readFieldInfo(), "[info] >>> read field info success",
            "[error] >>> read field error");
        
        CHECK_AND_PRINT(readMethodCount(method_count), "[info] >>> read method count success",
            "[error] >>> read method count error");

        CHECK_AND_PRINT(readMethodInfo(), "[info] >>> read method info success",
            "[error] >>> read method info error");

        CHECK_AND_PRINT(readAttributeCount(attributes_count), "[info] >>> read attribute count success",
            "[error] >>> read attribute count error");

        CHECK_AND_PRINT(readAttributeInfo(), "[info] >>> read attribute info success",
            "[error] >>> read attribute info error");

        PRINT("[info] parse class success");
    }

    void display()
    {
        //todo
    }
//method
protected:
    int readMagic(u4& magic)
    {
        char byte[4];
        input.read(byte, 4);
        magic = _2_u4(byte);
        return OK;
    }

    int readMinorVersion(u2& minor_version)
    {
        char byte[2];
        input.read(byte, 2);
        minor_version = _2_u2(byte);
        return OK;
    }

    int readMajorVersion(u2& major_version)
    {
        char byte[2];
        input.read(byte, 2);
        major_version = _2_u2(byte);
        return OK;
    }

    int readContantPoolCount(u2& constant_pool_count)
    {
        char byte[2];
        input.read(byte, 2);
        constant_pool_count = _2_u2(byte);
        return OK;
    }

    int readConstantInfo()
    {
        if (info == nullptr)
        {
            info = new constant_info[constant_pool_count];
        }

        constant_info_factory factory;
        factory.init();//init map

        for (int i = 0; i < constant_pool_count; i++)
        {
            u1 tag;
            if (readTag(tag) == OK)
            {
                constant_info* data;
                if (factory.getInstance(tag, *data) != OK)
                {
                    return ERR;
                }
                info[i] = *data;
                
                //read info
                data->readInfo(input);
            }
        }

        return OK;
    }

    int readTag(u1& tag)
    {
        char byte[1];
        input.read(byte, 1);
        tag = byte[0];
        return OK;
    }

    int readAccessFlags(u2& access_flags)
    {
        char byte[2];
        input.read(byte, 2);
        access_flags = _2_u2(byte);
        return OK;
    }

    int readThisClass(u2& this_class)
    {
        char byte[2];
        input.read(byte, 2);
        this_class = _2_u2(byte);
        return OK;
    }

    int readSuperClass(u2& super_class)
    {
        char byte[2];
        input.read(byte, 2);
        super_class = _2_u2(byte);
        return OK;
    }

    int readInterfacesCount(u2& interfaces_count)
    {
        char byte[2];
        input.read(byte, 2);
        interfaces_count = _2_u2(byte);
        return OK;
    }

    int readInterfaces()
    {
        if (interfaces == nullptr)
        {
            interfaces = new u2[interfaces_count];
        }

        char byte[2];
        for (int i = 0; i < interfaces_count; i++)
        {
            input.read(byte, 2);
            //new u2 on heap
            u2 *data = new u2;
            *data = _2_u2(byte);

            interfaces[i] = *data;

        }

        return OK;
    }

    int readFeildCount(u2& field_count)
    {
        char byte[2];
        input.read(byte, 2);
        field_count = _2_u2(byte);
        return OK;
    }

    int readFieldInfo()
    {
        if (fields == nullptr)
        {
            fields = new field_info[field_count];
        }

        for (int i = 0; i < field_count; i++)
        {
            field_info *field = new field_info;
            field->readInfo(input);

            fields[i] = *field;
        }

        return OK;
    }

    int readMethodCount(u2& method_count)
    {
        char byte[2];
        input.read(byte, 2);
        method_count = _2_u2(byte);
        return OK;
    }

    int readMethodInfo()
    {
        if (methods == nullptr)
        {
            methods = new method_info[method_count];
        }

        for (int i = 0; i < method_count; i++)
        {
            method_info *method = new method_info;
            method->readInfo(input);

            methods[i] = *method;
        }

        return OK;
    }

    int readAttributeCount(u2& attribute_count)
    {
        char byte[2];
        input.read(byte, 2);
        attribute_count = _2_u2(byte);
        return OK;
    }

    int readAttributeInfo()
    {
        if (attributes == nullptr)
        {
            attributes = new attribute_info[attributes_count];
        }

        for (int i = 0; i < attributes_count; i++)
        {
            attribute_info *attribute = new attribute_info;
            attribute->readInfo(input);

            attributes[i] = *attribute;
        }

        return OK;
    }

protected:
    std::ifstream input;

private:
    u4 magic;
    u2 minor_version;
    u2 major_version;
    u2 constant_pool_count;
    constant_info* info = nullptr;
    u2 access_flags;
    u2 this_class;
    u2 super_class;
    u2 interfaces_count;
    u2* interfaces = nullptr;
    u2 field_count;
    field_info* fields = nullptr;
    u2 method_count;
    method_info* methods = nullptr;
    u2 attributes_count;
    attribute_info* attributes = nullptr;
};