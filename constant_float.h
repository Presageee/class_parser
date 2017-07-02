#include "constant_info.h"

class constant_float: public constant_info
{
public:
    constant_float(u1 tag):constant_info(tag)
    {
        
    }
    void readInfo(std::ifstream &in)
    {
        char tmp[4];
        in.read(tmp, 4);
        this->val = _2_u4(tmp);
    }
private:
    u4 val;
};