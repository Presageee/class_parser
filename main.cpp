#include "common.h"
#include <iostream>
using namespace std;

int main()
{
	unsigned char b[4] = {0, 0, 0, 5};
    unsigned int d = _2_u4(b);
    unsigned int q = (unsigned int)&b;
	cout << d<< endl;
    cout << q << endl;
    unsigned char c[2] = { 0,3 };
    unsigned short a = _2_u2(c);
    cout << a << endl;
    unsigned char dd[8] = { 0,0,0,0,0,0,0,123 };
    long long cc = _2_u8(dd);
    long long ee = dd[7];
    int i = 7;
    for (int j = 0; j < 7; j++, i--)
    {
        ee |= (dd[j] & 0xFF << (j * 8));
    }
    cout << cc << endl;
    cout << ee << endl;
    return 0;
}