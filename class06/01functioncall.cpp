#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{

    return 0;
}


//函数声明 因为先使用了函数drawLine 然后才有的定义 所以需要再使用之前声明一下
bool drawLine(int x1, int y1, int x2, int y2);


bool drawRectangle(int x1, int y1, int x2, int y2)
{
    
    // drawLine(...);
    // drawLine(...);
    // drawLine(...);
    // drawLine(...);
    return true;
}

// define it later
bool drawLine(int x1, int y1, int x2, int y2)
{
    return true;
}
