#include "constant_info.h"

class constant_method_ref: public constant_info
{
public:
    constant_method_ref(u1 tag):constant_info(tag)
    {
        
    }
    void readInfo(std::ifstream &in)
    {
        char c_tmp[2];
        char n_tmp[2];
        in.read(c_tmp, 2);
        in.read(n_tmp, 2);
        this->class_index = _2_u2(c_tmp);
        this->name_and_type_index = _2_u2(n_tmp);
    }

    void disaply(const std::vector<constant_info*> &info)
    {
        if (ERR == CHECK_INDEX(class_index))
        {
            PRINT("[error] >>> index out of -1");
            exit(0);
        }

        u2 real_class_index = class_index - 1;

        if (OK == CHECK_INDEX(real_class_index))
        {
            std::cout << "#" << real_class_index << ",";
        }

        if (ERR == CHECK_INDEX(name_and_type_index))
        {
            PRINT("[error] >>> index out of -1");
            exit(0);
        }

        u2 real_name_and_type_index = name_and_type_index - 1;

        if (OK == CHECK_INDEX(real_name_and_type_index))
        {
            std::cout << "#" << real_name_and_type_index;
        }
    }
private:
    u2 class_index;
    u2 name_and_type_index;
};