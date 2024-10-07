#include <iostream>
#include <string.h>

using namespace std;

// 默认参数是在函数声明式使用的 其必须从后往前定义 比如下面的2和3条 不可以反过来定义
float norm(float x, float y, float z);
float norm(float x, float y, float z = 0);
float norm(float x, float y = 0, float z);

int main()
{
    cout << norm(3.0f) << endl;
    cout << norm(3.0f, 4.0f) << endl;
    cout << norm(3.0f, 4.0f, 5.0f) << endl;
    return 0;
}
float norm(float x, float y, float z)
{
    return (x * x + y * y + z * z);
}