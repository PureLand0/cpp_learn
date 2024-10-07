//size.cpp
#include <iostream>
#include <cstdint>
using namespace std;

int main()
{
    cout << "sizeof(int)=" << sizeof(int) << endl;//4
    cout << "sizeof(short int)=" << sizeof(short int) << endl;//2 可简写为short
    cout << "sizeof(long int)=" << sizeof(long int) << endl;//4  可简写为long
    cout << "sizeof(long long int)=" << sizeof(long long int) << endl;//8  可简写为long long
    //其实在不同的平台 上面这些所占的位置不尽相同 只能说大致如此罢了


    cout << "sizeof(char)=" << sizeof(char) << endl;//1B 本质上是整形 ascii码对应
    //1B只能表示ASCII那128位 所以有了更长的char
    char16_t c1 = u'杨';//26472
    char32_t c2 = U'杨';//26472
    cout << c1 << endl << c2 << endl;//打印出来的是整形 但是如果你是char去打印的话下来是字符

    //每个类型又分为signed和unsigned 如果前面啥都不写 默认是signed
    //但是char不一样 如果前面不写signed 在不同的平台上他的默认不一样 所以建议始终加上signed和unsigned

    //bool类型占用1B 本质上还是整形 true是1 false是0 bool会把一切非0量（char short int long float double）变为1
    bool b1 = true;
    bool b2 = 1;
    bool b3 = 12;//true
    cout << b1 << endl;


    //同一整数类型的不同宽度可能会导致程序难以移植到不同平台。自 C++11 起，<cstdint> 中引入了一些固定宽度整数类型。
    //它们是int8_t、uint8_t、int16_t、uint16_t、int32_t、uint32_t、int64_t、uint64_t等。
    //还有一些有用的宏，如INT_MAX、INT_MIN、INT8_MAX、UINT8_MAX等。这些整数类型可以显式声明变量的宽度。
    cout << INT_MAX << endl;

    return 0;
}