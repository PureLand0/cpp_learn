#define PI 3.14
double len(double r)
{
    return 2.0 * PI * r;
}


//预处理指令define会定义“宏” 本质上是一种替换 即会把下面所有出现PI的地方全部replace 3.14 然后再去进行编译

/**
甚至可以使用它代替函数的功能
#define MAX(a,b) (((a)>(b))?(a):(b))
int main()
{
    //...
    float a = 2.0f;
    float b = 3.0f;
    float m;
    m = MAX(a, b);
    //...
}
 */