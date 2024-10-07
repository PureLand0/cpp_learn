#include <iostream>
#include <string.h>

using namespace std;

// 下面是2个函数声明
float norm_l1(float x, float y);
float norm_l2(float x, float y);
// 定义一个函数指针 这个指针的返回值 参数列表应该和你需要指向的函数一样
float (*norm_ptr)(float x, float y);
// 那么同理 函数也是有引用的 和指针不同的是需要在创造的时候init
float (&norm_refer)(float x, float y) = norm_l2;


int main(int argc, char const *argv[])
{
    //下面2行时使指针指向函数 二者等效
    norm_ptr = norm_l1;                    // Pointer norm_ptr is pointing to norm_l1
    norm_ptr = &norm_l2;                   // Pointer norm_ptr is pointing to norm_l2
    //下面2行是使用指针 二者等效
    float len1 = norm_ptr(-3.0f, 4.0f);    // function invoked
    float len2 = (*norm_ptr)(-3.0f, 4.0f); // function invoked


    //引用的使用和指针一样
    norm_refer(-3.0f, 4.0f);
    return 0;
}



float norm_l1(float x, float y)
{
    return 0.1f;
}
float norm_l2(float x, float y)
{
    return 0.1f;
}