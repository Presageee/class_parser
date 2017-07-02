#include "constant_info.h"

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
private:
    u1 reference_kind;
    u2 reference_index;
};