#include "constant_info.h"

class constant_name_and_type: public constant_info
{
public:
    constant_name_and_type(u1 tag)
    {
        constant_info(tag);
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
private:
    u2 class_index;
    u2 name_and_type_index;
};