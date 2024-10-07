#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    
    return 0;
}

//计算平方函数
//goto不建议使用 这是唯一的使用场景
float mysquare(float value)
{
    float result = 0.0f;
    if(value >= 1.0f || value <= 0)
    {
        cerr << "The input is out of range." << endl;
        goto EXIT_ERROR;
    }
    result = value * value;
    return result;

  EXIT_ERROR://标签

    //做一些关闭文件等善后操作
    
    return 0.0f;
}

