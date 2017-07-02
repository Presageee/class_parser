#include "constant_info.h"

class constant_string: public constant_info
{
public:
    constant_string(u1 tag):constant_info(tag)
    {
        
    }
    void readInfo(std::ifstream &in)
    {
        char tmp[2];
        in.read(tmp, 2);
        this->string_index = _2_u2(tmp);
    }
private:
    u2 string_index;
};