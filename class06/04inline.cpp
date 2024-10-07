#include <iostream>
#include <string.h>
using namespace std;

inline float max_function(float a, float b)
{
    if (a > b)
        return a;
    else
        return b;
}

int main()
{
    int num1 = 20;
    int num2 = 30;
    int maxv = max_function(num1, num2);
}


// 正常情况下，调用函数的花销是很大的：保存上下文，copy....
// 这时可以在函数前面加个inline 这样相当于是把main替换为了下面这样 不用调函数了 大大提升了效率
// int main()
// {
//     int num1 = 20;
//     int num2 = 30;
//     int maxv =
//         maxv =
//     { if (num1 > num2) return num1;
//     else return num2;
// }
// }