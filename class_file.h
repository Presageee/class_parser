#include "common.h"
#include "constant_info.h"
#include "field_info.h"
#include "method_info.h"
#include "constant_info_factory.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <iomanip>


extern constant_info_factory info_factory;

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
        printMagic();

        printMinorVersion();

        printMajorVersion();
        
        printAccessFlags();

        printConstantPool();

        printThisClass();

        printSuperClass();

        printInterfaces();

        printFields();

        printMethods();

        printAttributes();
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
        //if (info == nullptr)
        //{
        //    info = new constant_info[constant_pool_count];
        //}

        //constant_info_factory factory;
        info_factory.init();//init map

        for (int i = 1; i < constant_pool_count; i++)
        {
            u1 tag;
            if (readTag(tag) == OK)
            {
                constant_info* data = nullptr;
                if (info_factory.getInstance(tag, &data) != OK)
                {
                    return ERR;
                }
                //info[i] = *data;
                info.push_back(data);
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
        //if (interfaces == nullptr)
        //{
        //    interfaces = new u2[interfaces_count];
        //}

        char byte[2];
        for (int i = 0; i < interfaces_count; i++)
        {
            input.read(byte, 2);
            //new u2 on heap
            u2 *data = new u2;
            *data = _2_u2(byte);

            interfaces.push_back(data);
            //interfaces[i] = *data;

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
        //if (fields == nullptr)
        //{
        //    fields = new field_info[field_count];
        //}

        for (int i = 0; i < field_count; i++)
        {
            field_info *field = new field_info;
            field->readInfo(input);

            fields.push_back(field);
            //fields[i] = *field;
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
        /*if (methods == nullptr)
        {
            methods = new method_info[method_count];
        }*/

        for (int i = 0; i < method_count; i++)
        {
            method_info *method = new method_info;
            method->readInfo(input);

            methods.push_back(method);
            //methods[i] = *method;
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
        //if (attributes == nullptr)
        //{
        //    attributes = new attribute_info[attributes_count];
        //}

        for (int i = 0; i < attributes_count; i++)
        {
            attribute_info *attribute = new attribute_info;
            attribute->readInfo(input);

            attributes.push_back(attribute);
            //attributes[i] = *attribute;
        }

        return OK;
    }

    void printMagic()
    {
        std::cout << "magic : " << magic << std::endl;
    }

    void printMinorVersion()
    {
        std::cout << "minor version : " << minor_version << std::endl;
    }

    void printMajorVersion()
    {
        std::cout << "major version : " << major_version << std::endl;
    }

    void printConstantPool()
    {
        std::cout << "Constant pool size : " << constant_pool_count - 1 << std::endl;
        std::cout << "Constant pool : " << std::endl;

        int counter = 1;
        for (auto& val : info)
        {
            std::cout << std::setw(5) << "#" << counter++;
            val->display(info);
            std::cout << std::endl;
        }
    }

    void printAccessFlags()
    {
        std::cout << "flags : ";
        bool isOut = false;
        if (access_flags & C_ACC_PUBLIC)
        {
            std::cout << "PUBLIC";
            isOut = true;
        }

        if (access_flags & C_ACC_FINAL)
        {
            CHECK_FIRST_OUTPUT(isOut);
            std::cout << "FINAL";
            isOut = true;
        }

        if (access_flags & C_ACC_SUPER)
        {
            CHECK_FIRST_OUTPUT(isOut);
            std::cout << "SUPER";
            isOut = true;
        }

        if (access_flags & C_ACC_INTERFACE)
        {
            CHECK_FIRST_OUTPUT(true);
            std::cout << "INTERFACE";
            isOut = true;
        }

        if (access_flags & C_ACC_ABSTRACT)
        {
            CHECK_FIRST_OUTPUT(true);
            std::cout << "ABSTRACT";
            isOut = true;
        }

        if (access_flags & C_ACC_SYNTHETIC)
        {
            CHECK_FIRST_OUTPUT(true);
            std::cout << "SYNTHETIC";
            isOut = true;
        }

        if (access_flags & C_ACC_ANNOTATION)
        {
            CHECK_FIRST_OUTPUT(true);
            std::cout << "ANNOTATION";
            isOut = true;
        }

        if (access_flags & C_ACC_ENUM)
        {
            CHECK_FIRST_OUTPUT(true);
            std::cout << "ENUM";
            isOut = true;
        }

        std::cout << std::endl;
    }

    void printThisClass()
    {
        std::cout << "Class ";

        if (ERR == CHECK_INDEX(this_class))
        {
            PRINT("[error] >>> index out of -1");
            exit(0);
        }

        u2 real_this_class = this_class - 1;

        if (OK == CHECK_INDEX(real_this_class))
        {
            info[real_this_class]->outputVal(info);
        }

        std::cout;
    }

    void printSuperClass()
    {
        std::cout << " :";

        if (ERR == CHECK_INDEX(super_class))
        {
            PRINT("[error] >>> index out of -1");
            exit(0);
        }

        u2 real_super_class = super_class - 1;

        if (OK == CHECK_INDEX(real_super_class))
        {
            info[real_super_class]->outputVal(info);
        }

        std::cout << std::endl;
    }

    void printInterfaces()
    {
        if (!interfaces_count)
        {
            return;
        }

        std::cout << "Interface : ";
        
        for (auto &val : interfaces)
        {
            if (ERR == CHECK_INDEX(*val))
            {
                PRINT("[error] >>> index out of -1");
                exit(0);
            }

            u2 real_interface = *val - 1;

            if (OK == CHECK_INDEX(real_interface))
            {
                info[real_interface]->display(info);
            }
        }
        std::cout << std::endl;
    }

    void printFields()
    {
        if (!field_count)
        {
            return;
        }

        std::cout << "Field : " << std::endl;
        for (auto &val : fields)
        {
            val->display(info);
            std::cout << std::endl;
        }
    }

    void printMethods()
    {
        if (!method_count)
        {
            return;
        }

        std::cout << "Method :" << std::endl;
        for (auto &val : methods)
        {
            val->outputVal(info);
            std::cout << std::endl;
        }
    }

    void printAttributes()
    {
        if (!attributes_count)
        {
            return;
        }

        std::cout << "Attribute : " << std::endl;
        for (auto &val : attributes)
        {
            val->disaply(info);
            std::cout << std::endl;
        }
    }
protected:
    std::ifstream input;

private:
    u4 magic;
    u2 minor_version;
    u2 major_version;
    u2 constant_pool_count;
    //constant_info* info = nullptr;
    std::vector<constant_info*> info;
    u2 access_flags;
    u2 this_class;
    u2 super_class;
    u2 interfaces_count;
    //u2* interfaces = nullptr;
    std::vector<u2*> interfaces;
    u2 field_count;
    //field_info* fields = nullptr;
    std::vector<field_info*> fields;
    u2 method_count;
    std::vector<method_info*> methods;
    //method_info* methods = nullptr;
    u2 attributes_count;
    std::vector<attribute_info*> attributes;
    //attribute_info* attributes = nullptr;
};