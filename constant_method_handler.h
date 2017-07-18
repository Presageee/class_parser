#include "constant_info.h"
#include "common.h"

extern method_handler_factory handler_factory;

class constant_method_handler: public constant_info
{
public:
    constant_method_handler(u1 tag):constant_info(tag)
    {
        
    }
    void readInfo(std::ifstream &in)
    {
        this->reference_kind = (u1)in.get();
        char tmp[2];
        in.read(tmp, 2);
        this->reference_index = _2_u2(tmp);
    }
    void display(const std::vector<constant_info*> &info)
    {
        std::cout << std::setw(20) << "MethodHandler";
        std::string msg;
        std::string err = "null";
        if (err.compare((msg = handler_factory.getType(reference_kind))))
        {
            PRINT("[error] >>> reference_kind is null");
            exit(0);
        }

        std::cout << std::setw(20) << msg;

        if (ERR == CHECK_INDEX(reference_index))
        {
            PRINT("[error] >>> index out of -1");
            exit(0);
        }

        u2 real_reference_index = reference_index - 1;

        if (OK == CHECK_INDEX(real_reference_index))
        {
            std::string msg_("#");
            std::cout << msg.append(std::to_string(real_reference_index));
        }
    }
private:
    //reference_kind must greater than 1 and less than 9.
    //if kind is in range of 1 to 4, the ref_index must be constant_field_ref
    //if kind is in range of 5 to 8, the ref_index must be constant_method_ref
    //if kind is 9,the ref_index must be constant_interface
    //when kind is 5, 6, 7, 9, the ref_index value hasn't <init> or <clinit>
    //if kind is 8, the ref_index value must be <init>
    u1 reference_kind;
    u2 reference_index;
};