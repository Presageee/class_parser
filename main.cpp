#include "common.h"
#include <iostream>
#include <fstream>
#include "class_file.h"
using namespace std;

int main()
{
    extern void init();
    init();
    class_file clazz("E:\\project\\Test.class");
    clazz.parseClass();
    clazz.display();
    int a = 0;
    return 0;
}