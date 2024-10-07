#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    /*
            95   // 十进制
            0137 // 八进制
            0x5F // 十六进制

            95   // int
            95u  // unsigned int
            95l  // long
            95ul // unsigned long

            3.14159 // double
            3.0     // double
            6.02e13 // 6.02 x 10^13
            1.6e-9  // 1.6 x 10^-9

            6.02e13f // float
            6.02e13  // double
            6.02e13L // long double
    */

    const float pi = 3.1415926f; // const修饰 不可再修改

    /* 算术运算
        a + b
        a - b
        a * b
        a / b
        a % b 取余数（模）
        ispositive ? a : b

        ~a按位取反
        a & b按位与
        a | b按位或
        a ^ b按位异或

        a << b a左移b位 每移一位相当于乘2 这个比单纯的乘法快 乘2意义可适用于正整数和负整数 结果也一定是整数
        a >> b a右移b位 每移一位相当于除2 这个比单纯的除法快 除2意义可适用于正整数和负整数 结果也一定是整数
    */

    /*
    只有四种类型可以进行上面的算术运算：int long float double
    所以当运算符两端的类型不满足时 会将其转换为离他们最近的类型（不失精度转换）且最终二者类型需一致
    不失精度转换：char short int long float double 反之为失精度转换
        不失精度转换可自动可强制 可能会损失精度比如大int转float
        失精度转换可自动可强制 可能会损失精度
    */
    unsigned char char1 = 255;
    unsigned char char2 = 1;
    int num = char1 + char2; // +两端转为int再计算

    int num2 = 1.2f + 3.4; // -> 1.2 + 3.4 -> 4.6 -> 4 即double转int只留整数部分

    float float_num = 17 / 5; // f = 3.0f /两端全为int或者long 则只进行整数除法

    auto a = 2;       // type of a is int
    auto b = 2.3;    // type of b is double
    //auto c;           // valid in C, but not in C++
    auto d = a * 1.2; // type of d is double


    /*
        赋值运算符： 在上面算数运算的基础上加个=
        还有a++ ++a a-- --a
    */
    return 0;
}
