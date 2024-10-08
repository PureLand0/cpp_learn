#include <iostream>
#include <string.h>

using namespace std;

// reference 引用 其实就是别名
int main(int argc, char const *argv[])
{
    int num = 0;
    int &num_ref = num; // 这里num_ref用&标识就是num的引用 你可以把它理解为别名
    num_ref = 10;       // 那么num也会被改为10

    // 对于结构体也是一样的 matA_ref是matA的别名
    Matrix matA = {3, 4};
    matA.pData = new float[matA.rows * matA.cols]{};
    Matrix &matA_ref = matA;

    // 注意！！！：引用必须初始化 不像指针可以不初始化
    // 引用和指针在很多方面都非常相似，不同的点在于上面的初始化以及引用一般比指针更加安全 指针难以控制边界
    
    // 比如我们想找到这个矩阵的最大值，其实有三种方法，我们可以传入这个矩阵，但是这样效率很低，因为要拷贝，我们也可以传入他的指针
    // 但是比较危险，那这个时候其实我们可以传入他的引用，不用拷贝很高效，而且安全，但是注意，如果我们在函数里面通过这个引用改变值，那么真实
    // 值也会被改变的 解决方法是可以在函数参数那加上const

    //即 函数的参数列表这搭配使用 const和&

    // 与之相对应 return返回的也是拷贝

    return 0;
}

struct Matrix
{
    size_t rows;
    size_t cols;
    float *pData;
};


