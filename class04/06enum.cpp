#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    //可以把enum理解为replace 从此之后 WHITE就是0 BLACK就是1 RED就是2.....
    enum color
    {
        WHITE,
        BLACK,
        RED,
        GREEN,
        BLUE,
        YELLOW,
        NUM_COLORS
    };//也可以放外面

    color pen_color = RED;   //！！！color就是数字
    pen_color = color(3);   //是green 其实就是整数3
    
    cout << "We have " << NUM_COLORS << " pens." << endl;


    //pen_color += 1; // error! 不可以进行运算

    int color_index = pen_color;//想要进行运算先转为int 再算
    color_index += 1;
    cout << "color_index = " << color_index << endl;
    return 0;
}
