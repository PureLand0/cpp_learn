#include <iostream>
#include <string.h>

using namespace std;

//c++中函数的key是函数名和参数列表。如果函数名和参数列表都一样，这就是一样的函数，禁止
//如果函数名一样 参数列表不一样 就叫重载
//如果函数名不一样 那必须可以！！！

int sum(int x, int y)
{
    cout << "sum(int, int) is called" << endl;
    return x + y;
}
float sum(float x, float y)
{
    cout << "sum(float, float) is called" << endl;
    return x + y;
}
double sum(double x, double y)
{
    cout << "sum(double, double) is called" << endl;
    return x + y;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}

