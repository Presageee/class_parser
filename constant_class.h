#include "constant_info.h"

class constant_class: public constant_info
{
public:
    friend void readInfo(const std::ifstream &in)
    {
        char tmp[2];
        in.read(tmp, 2);
        this->name_index = _2_u2(tmp);
    }
private:
    u2 name_index;
};