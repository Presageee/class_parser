#include "common.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream file;
    file.open("C:\\Users\\LJT\\Desktop\\fashen.txt", ios::binary | ios::in);
    if (!file)
        cout << "open error" << endl;
    cout << file.get() << endl;
    char tmp[3];
    memset(tmp, 0, 3);
    file.read(tmp, 2);
    cout << tmp << endl;
    return 0;
}