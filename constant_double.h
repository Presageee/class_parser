#include "constant_info.h"

class constant_double: public constant_info
{
public:
    constant_double(u1 tag):constant_info(tag)
    {
        
    }
    void readInfo(std::ifstream &in)
    {
        //char h_tmp[4];
        //char l_tmp[4];
        //in.read(h_tmp, 4);
        //in.read(l_tmp, 4);
        //this->hight_val = _2_u4(h_tmp);
        //this->low_val = _2_u4(l_tmp);
        char tmp[8];
        in.read(tmp, 8);
        this->val = _2_u8(tmp);
    }

    void display(const std::vector<constant_info*> &info)
    {
        std::cout << std::setw(20) << val;
    }
private:
    //u4 hight_val;
    //u4 low_val;

    double val;
};