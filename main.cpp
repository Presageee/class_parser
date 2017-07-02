#include "common.h"
#include <iostream>
#include <fstream>
#include "class_file.h"
using namespace std;

int main()
{
    class_file clazz("E:\\project\\Test.class");
    clazz.parseClass();
    int a = 0;
    return 0;
}