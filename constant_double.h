#include "constant_info.h"

class constant_double: public constant_info
{
public:
    constant_double(u1 tag):constant_info(tag)
    {
        
    }
    void readInfo(std::ifstream &in)
    {
        char h_tmp[4];
        char l_tmp[4];
        in.read(h_tmp, 4);
        in.read(l_tmp, 4);
        this->hight_val = _2_u4(h_tmp);
        this->low_val = _2_u4(l_tmp);
    }
private:
    u4 hight_val;
    u4 low_val;
};