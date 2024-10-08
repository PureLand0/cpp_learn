#include <iostream>
#include "time.hpp"

using namespace std;

int main()
{
    MyTime t1(1, 20);
    int test1 = t1;    // 自定义类型转换1
    float test2 = float(t1); //自定义类型转换2 必须显示调用


    // 下面这俩看着像 但是不是一回事！！！
    MyTime t2 = MyTime(70);// 构造函数
    

    MyTime t3;
    t3 = 80;// 对=的overload
    

    return 0;
}