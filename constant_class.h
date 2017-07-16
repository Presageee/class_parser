#include "constant_info.h"


class constant_class: public constant_info
{
public:
    constant_class(u1 tag):constant_info(tag)
    {
      
    }

    void readInfo(std::ifstream &in)
    {
        char tmp[2];
        in.read(tmp, 2);
        this->name_index = _2_u2(tmp);
    }

    void display(const std::vector<constant_info*> &info)
    {
        std::cout << std::setw(20) << "Class";
        if (ERR == CHECK_INDEX(name_index)) 
        {
            PRINT("[error] >>> index out of -1");
            exit(0);
        }

        u2 real_index = name_index - 1;

        if (ERR == CHECK_INDEX(real_index))
        {
            return;
        }
        std::string msg("#");
        std::cout << std::setw(20) << msg.append(std::to_string(real_index));

        info[real_index]->display(info);
    }
private:
    u2 name_index;
};