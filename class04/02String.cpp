#include <iostream>
#include <string.h>
using namespace std;

//总共三种形式
int main(int argc, char const *argv[])
{
    // 可以使用char数组作为字符串，以0或者'\0'结尾
    char rabbit[16] = {'P', 'e', 't', 'e', 'r'};                             // 后面自动补0，很好
    char bad_pig[9] = {'P', 'e', 'p', 'p', 'a', ' ', 'P', 'i', 'g'};         // 没有0结尾，不好
    char good_pig[10] = {'P', 'e', 'p', 'p', 'a', ' ', 'P', 'i', 'g', '\0'}; // 主动加0，很好

    // strlen(str)是一个函数 计算str的长度
    char s[] = {'1', '2', 0, '3', '4'};
    cout << strlen(s) << endl;

    // 上面这么写太麻烦了 所以有了下面的变种 会在后面自动补0
    char name1[] = "Southern";
    
    // char只能表示128个ASCII码 所以有了下面的
    char16_t s9[] = u"ABCD "; 
    char32_t s6[] = U"ABCD "; 

    //下面介绍三个函数strcpy strcat strcmp
    //1 会将c2所代表的字符串copy给c1 而且是全部copy 所以会产生越界的问题
    char c1[] = "abc";
    char c2[] = "12345678\09";
    strcpy(c1,c2);
    cout<<c1<<endl;//12345678
    //2 会将c4所代表的字符串cat在c3后面 而且是全部cat 所以会产生越界的问题
    char c3[] = "abc";
    char c4[] = "12345678\09";
    strcat(c3,c4);
    cout<<c3<<endl;//abc12345678
    //3 字符串大小比较
    cout << strcmp(c3,c4) << endl;

    //上面的形式还是麻烦 于是封装了string类 后面自动加0
    string str1 = "Hello";
    string str2 = "world";
    //1 copy
    str1 = str2;
    cout << str1 << endl;
    //2 cat
    cout << str1 + str2 << endl;
    //3 compare
    cout << (str1<str2) << endl;


    //只有第2和3种形式可以存中文，这个时候一个中文是3B，英文和数字还是1B
    //char ch1[] = {'你','好'};
    char ch2[] = "你好1";
    string ch3 = "你好";  
}