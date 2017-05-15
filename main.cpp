#include "common.h"
#include <iostream>
#include <fstream>
#include "field_info.h"
using namespace std;

int main()
{
    ifstream file;
    file.open("C:\\Users\\LJT\\Desktop\\fashen.txt", ios::binary | ios::in);
    if (!file)
        cout << "open error" << endl;
    field_info f;
    f.field_info::readInfo(file);
    return 0;
}