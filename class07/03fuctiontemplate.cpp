#include <iostream>
#include <string.h>

using namespace std;
// 上面的02中sum明明一模一样的操作 还要写三遍 可以使用template

//定义template
template <typename T>
T sum(T x, T y)
{
    cout << "The input type is " << typeid(T).name() << endl;
    return x + y;
}


// 使用前需要进行实例化 然后后面才可以用
template double sum<double>(double, double);
template char sum<>(char, char);
template int sum(int, int);


// 上面全是数字 如果我就想传入结构体point呢？ 这个时候需要“特例化”
struct  point
{
    int x;
    int y;
};

// 这是“特例化”
template<>
point sum<point>(point pt1,point pt2)
{
    point a;
    return a;
}

int main(int argc, char const *argv[])
{
    cout << sum(1,3) <<endl;
    return 0;
}



