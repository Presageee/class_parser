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

    void display(const std::vector<constant_info*> &info)
    {
        if (ERR == CHECK_INDEX(string_index))
        {
            PRINT("[error] >>> index out of -1");
            exit(0);
        }

        u2 real_string_index = string_index - 1;

        if (OK == CHECK_INDEX(real_string_index))
        {
            //info[real_class_index]->display(info);
            std::cout << "#" << real_string_index << ",";
        }

    }
private:
    u2 string_index;
};