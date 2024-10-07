// precision.cpp
#include <iostream>
using namespace std;

int main()
{
    float f1 = 23400000000;//这是int 赋给float没问题
    float f2 = f1 + 10;
    cout.setf(ios_base::fixed, ios_base::floatfield); // fixed-point
    cout << "f1 = " << f1 << endl;
    cout << "f2 = " << f2 << endl;
    cout << "f1 - f2 = " << f1 - f2 << endl;
    cout << "(f1 - f2 == 0) = " << (f1 - f2 == 0) << endl;
    // f1 = 23399999488.000000
    // f2 = 23399999488.000000
    // f1 - f2 = 0.000000
    // (f1 - f2 == 0) = 1

    //小数类型有2种 float和double
    //float为4B 他的表示范围比int大得多 但是精确度会缩小（在范围内取代表点） 所以上面的例子中 float+10 结果没变一点 因为没到下一个阈值
    //double为8B 表示范围和精度都比float大
    //比较大小不建议使用== 而是应该使用减法 看他们的差值是不是小于一个值

     float f1 = 2.0f / 0.0f;//会产生一个特殊的浮点值 inf 表示无穷大
     //0.0写出来默认为double 直接赋值也行 但建议加f表示这是float的 以免造成一些性能上的差异
     float f2 = 0.0f / 0.0f;//会产生一个特殊的浮点值 nan 表示错误

     //folat的计算慢于整形 double的计算慢于float

    return 0;
}