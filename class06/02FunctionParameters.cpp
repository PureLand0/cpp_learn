#include <iostream>
#include <string.h>
using namespace std;

// 在下面这种情况下 x只是相当于num1的拷贝 所以你改变x不会对num1有任何影响
int foo(int x)
{
    x += 10;
    return x;
}
int main()
{
    int num1 = 20;
    int num2 = foo(num1);
    return 0;
}

// 在下面这种情况中 p1仍然只是指针p的拷贝 但是遗憾的是 我们确实可以通过这个拷贝p1找到原先的数据num1 所以可以通过p1修改num1
// 可以让p1指向别的数据 这对p以及num1不会有任何影响
int foo(int *p1)
{
    (*p1) += 10;
    return *p1;
}
int main()
{
    int num1 = 20;
    int *p = &num1;
    int num2 = foo(p);
    return 0;
}

//所以 如果函数参数传入的是结构体 那么对于结构体里面的基本数据类型 仍然是数据拷贝 对于里面的指针类型 是拷贝 但是可以根据这个拷贝找到源数据
 
