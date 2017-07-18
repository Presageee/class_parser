#include "constant_info.h"

class constant_name_and_type: public constant_info
{
public:
    constant_name_and_type(u1 tag):constant_info(tag)
    {
        
    }

    void readInfo(std::ifstream &in)
    {
        char c_tmp[2];
        char n_tmp[2];
        in.read(c_tmp, 2);
        in.read(n_tmp, 2);
        this->name_index = _2_u2(c_tmp);
        this->description_index = _2_u2(n_tmp);
    }
    void display(const std::vector<constant_info*> &info)
    {
        std::cout << std::setw(20) << "NameAndType";
        if (ERR == CHECK_INDEX(name_index))
        {
            PRINT("[error] >>> index out of -1");
            exit(0);
        }

        u2 real_name_index = name_index - 1;

        if (OK == CHECK_INDEX(real_name_index))
        {
            std::string msg("#");
            std::cout << std::setw(20) << msg.append(std::to_string(real_name_index)) << ",";
        }

        if (ERR == CHECK_INDEX(description_index))
        {
            PRINT("[error] >>> index out of -1");
            exit(0);
        }

        u2 real_description_index = description_index - 1;

        if (OK == CHECK_INDEX(real_description_index))
        {
            std::cout << "#" << real_description_index;
        }
    }
private:
    u2 name_index;
    u2 description_index;
};